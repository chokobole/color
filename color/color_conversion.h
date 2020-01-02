// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_COLOR_CONVERSION_H_
#define COLOR_COLOR_CONVERSION_H_

#include "color/color.h"
#include "color/export.h"

namespace color {

COLOR_EXPORT Rgb HsvToRgb(const Hsv& hsv);

COLOR_EXPORT Hsv RgbToHsv(const Rgb& rgb);

}  // namespace color

#endif  // COLOR_COLOR_CONVERSION_H_