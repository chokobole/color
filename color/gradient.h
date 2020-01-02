// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_GRADIENT_H_
#define COLOR_GRADIENT_H_

#include <vector>

#include "color/color.h"
#include "color/export.h"

namespace color {

struct StopColor {
  Rgb color;
  double position;  // 0 to 1

  constexpr StopColor() : position(-1) {}
  constexpr StopColor(Rgb color) : color(color), position(-1) {}
  constexpr StopColor(Rgb color, double position)
      : color(color), position(position) {}

 private:
  friend class Gradient;

  constexpr bool IsPositionUnassigned() const {
    return position >= 0 && position <= 1;
  }
};

class COLOR_EXPORT Gradient {
 public:
  enum StepMethod {
    STEP_METHOD_RGB,
    STEP_METHOD_HSV_CW,
    STEP_METHOD_HSV_CCW,
  };

  Gradient();
  Gradient(const std::vector<StopColor>& stop_colors);
  Gradient(std::vector<StopColor>&& stop_colors);

  Gradient(const Gradient& other);
  Gradient(Gradient&& other) noexcept;

  Gradient& operator=(const Gradient& other);
  Gradient& operator=(Gradient&& other) noexcept;

  // Returns true when successfully generated |colors|.
  // Returns false if |stop_colors_| is less than or equal to 1.
  bool Colors(size_t numbers, std::vector<Rgb>* colors,
              StepMethod = STEP_METHOD_RGB) const;

 private:
  void ColorsRgb(const std::vector<StopColor>& stop_colors,
                 std::vector<Rgb>* colors) const;
  void ColorsHsvCw(const std::vector<StopColor>& stop_colors,
                   std::vector<Rgb>* colors) const;
  void ColorsHsvCcw(const std::vector<StopColor>& stop_colors,
                    std::vector<Rgb>* colors) const;

  std::vector<StopColor> stop_colors_;
};

}  // namespace color

#endif  // COLOR_GRADIENT_H_