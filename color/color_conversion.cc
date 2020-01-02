// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/color_conversion.h"

#include <algorithm>
#include <cmath>

namespace color {

Rgb HsvToRgb(const Hsv& hsv) {
  if (!hsv.IsValid()) return {};

  float h = hsv.data.h;
  float s = hsv.data.s;
  float v = hsv.data.v;
  uint8_t r, g, b, a = hsv.data.a * 255;

  float H = h / 60;

  float c = v * s;
  float x = c * (1 - std::abs(fmod(H, 2) - 1));
  float m = v - c;

  switch (static_cast<uint8_t>(H)) {
    case 0:
      r = (c + m) * 255;
      g = (x + m) * 255;
      b = m * 255;
      break;
    case 1:
      r = (x + m) * 255;
      g = (c + m) * 255;
      b = m * 255;
      break;
    case 2:
      r = m * 255;
      g = (c + m) * 255;
      b = (x + m) * 255;
      break;
    case 3:
      r = m * 255;
      g = (x + m) * 255;
      b = (c + m) * 255;
      break;
    case 4:
      r = (x + m) * 255;
      g = m * 255;
      b = (c + m) * 255;
      break;
    default:
      r = (c + m) * 255;
      g = m * 255;
      b = (x + m) * 255;
      break;
  }

  return {r, g, b, a};
}

Hsv RgbToHsv(const Rgb& rgb) {
  uint8_t r = rgb.data.r;
  uint8_t g = rgb.data.g;
  uint8_t b = rgb.data.b;
  float a = rgb.data.a / 255;

  uint8_t min = std::min(r, std::min(g, b));
  uint8_t max = std::max(r, std::max(g, b));
  uint8_t delta = max - min;

  float v = static_cast<float>(max) / 255;

  if (delta == 0) {
    return {0, 0, v, a};
  }

  float s = static_cast<float>(delta) / max;
  float h;
  if (r == max) {
    h = static_cast<float>(g - b) / delta;
  } else if (g == max) {
    h = 2 + static_cast<float>(b - r) / delta;
  } else {  // b == max
    h = 4 + static_cast<float>(r - g) / delta;
  }
  h *= 60;
  if (h < 0) {
    h += 360;
  }

  return {h, s, v, a};
}

}  // namespace color
