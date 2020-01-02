// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/gradient.h"

#include <algorithm>

#include "color/color_conversion.h"

namespace color {

namespace {

class Interpolater {
 public:
  Interpolater(StopColor from, StopColor to, std::vector<Rgb>* colors)
      : colors(colors) {
    start = current = from.position * colors->size();
    end = to.position * colors->size();
    (*colors)[static_cast<size_t>(current)] = from.color;
    current++;
  }

  void FillGradients() {
    while (HasNext()) {
      Step();
    }
  }

 protected:
  virtual void Step() = 0;

  bool HasNext() const { return current < end; }

  std::vector<Rgb>* colors;
  double start;
  double current;
  double end;
};

class RgbInterpolater : public Interpolater {
 public:
  RgbInterpolater(StopColor from, StopColor to, std::vector<Rgb>* colors)
      : Interpolater(from, to, colors),
        r_dist(static_cast<double>(to.color.data.r - from.color.data.r)),
        g_dist(static_cast<double>(to.color.data.g - from.color.data.g)),
        b_dist(static_cast<double>(to.color.data.b - from.color.data.b)),
        start_color(from.color) {}

 private:
  void Step() override {
    Rgb c(start_color);
    double r = (current - start) / (end - start - 1);
    c.data.r += r_dist * r;
    c.data.g += g_dist * r;
    c.data.b += b_dist * r;
    (*colors)[static_cast<size_t>(current)] = c;
    current++;
  }

  double r_dist;
  double g_dist;
  double b_dist;
  Rgb start_color;
};

class HsvInterpolator : public Interpolater {
 protected:
  HsvInterpolator(StopColor from, StopColor to, std::vector<Rgb>* colors)
      : Interpolater(from, to, colors), start_color(RgbToHsv(from.color)) {}

  void Step() override {
    Hsv c(start_color);
    double r = (current - start) / (end - start - 1);
    c.data.h += h_dist * r;
    if (c.data.h > 360) {
      c.data.h -= 360;
    }
    if (c.data.h < 0) {
      c.data.h += 360;
    }
    c.data.s += s_dist * r;
    c.data.v += v_dist * r;
    (*colors)[static_cast<size_t>(current)] = HsvToRgb(c);
    current++;
  }

  double h_dist;
  double s_dist;
  double v_dist;
  Hsv start_color;
};

class HsvCwInterpolater : public HsvInterpolator {
 public:
  HsvCwInterpolater(StopColor from, StopColor to, std::vector<Rgb>* colors)
      : HsvInterpolator(from, to, colors) {
    Hsv end_color(RgbToHsv(to.color));
    h_dist = end_color.data.h - start_color.data.h;
    s_dist = end_color.data.s - start_color.data.s;
    v_dist = end_color.data.v - start_color.data.v;
    if (h_dist < 0) {
      h_dist += 360;
    }
  }
};

class HsvCcwInterpolater : public HsvInterpolator {
 public:
  HsvCcwInterpolater(StopColor from, StopColor to, std::vector<Rgb>* colors)
      : HsvInterpolator(from, to, colors) {
    Hsv end_color(RgbToHsv(to.color));
    h_dist = end_color.data.h - start_color.data.h;
    s_dist = end_color.data.s - start_color.data.s;
    v_dist = end_color.data.v - start_color.data.v;
    if (h_dist > 0) {
      h_dist -= 360;
    }
  }
};

}  // namespace

Gradient::Gradient() = default;

Gradient::Gradient(const std::vector<StopColor>& stop_colors)
    : stop_colors_(stop_colors) {}

Gradient::Gradient(std::vector<StopColor>&& stop_colors)
    : stop_colors_(std::move(stop_colors)) {}

Gradient::Gradient(const Gradient& other) = default;

Gradient::Gradient(Gradient&& other) noexcept
    : stop_colors_(std::move(other.stop_colors_)) {}

Gradient& Gradient::operator=(const Gradient& other) {
  stop_colors_ = other.stop_colors_;
  return *this;
}

Gradient& Gradient::operator=(Gradient&& other) noexcept {
  stop_colors_ = std::move(other.stop_colors_);
  return *this;
}

bool Gradient::Colors(size_t numbers, std::vector<Rgb>* colors,
                      StepMethod step_method) const {
  if (stop_colors_.size() <= 1) return false;
  if (numbers == 0) return false;

  std::vector<StopColor> stop_colors(stop_colors_);
  size_t unassigned = std::count_if(
      stop_colors.begin(), stop_colors.end(),
      [](const StopColor& c) { return c.IsPositionUnassigned(); });
  double p = 0;
  double a = 1.0 / (stop_colors.size() - unassigned - 1);
  for (StopColor& c : stop_colors) {
    if (!c.IsPositionUnassigned()) {
      c.position = p;
      p += a;
    }
  }
  std::sort(stop_colors.begin(), stop_colors.end(),
            [](const StopColor& c, const StopColor& c2) {
              return c.position <= c2.position;
            });

  colors->clear();
  colors->resize(numbers);

  switch (step_method) {
    case STEP_METHOD_RGB:
      ColorsRgb(stop_colors, colors);
      break;
    case STEP_METHOD_HSV_CW:
      ColorsHsvCw(stop_colors, colors);
      break;
    case STEP_METHOD_HSV_CCW:
      ColorsHsvCcw(stop_colors, colors);
      break;
  }
  colors->back() = stop_colors.back().color;
  return true;
}

void Gradient::ColorsRgb(const std::vector<StopColor>& stop_colors,
                         std::vector<Rgb>* colors) const {
  auto it = stop_colors.begin();
  StopColor to = *(it++);
  while (it != stop_colors.end()) {
    StopColor from = to;
    to = *(it++);
    RgbInterpolater interpolater(from, to, colors);
    interpolater.FillGradients();
  }
}

void Gradient::ColorsHsvCw(const std::vector<StopColor>& stop_colors,
                           std::vector<Rgb>* colors) const {
  auto it = stop_colors.begin();
  StopColor to = *(it++);
  while (it != stop_colors.end()) {
    StopColor from = to;
    to = *(it++);
    HsvCwInterpolater interpolater(from, to, colors);
    interpolater.FillGradients();
  }
}

void Gradient::ColorsHsvCcw(const std::vector<StopColor>& stop_colors,
                            std::vector<Rgb>* colors) const {
  auto it = stop_colors.begin();
  StopColor to = *(it++);
  while (it != stop_colors.end()) {
    StopColor from = to;
    to = *(it++);
    HsvCcwInterpolater interpolater(from, to, colors);
    interpolater.FillGradients();
  }
}

}  // namespace color