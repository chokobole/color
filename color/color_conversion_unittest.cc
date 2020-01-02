// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/color_conversion.h"

#include "color/named_color.h"
#include "gtest/gtest.h"

namespace color {

TEST(ColorConversion, RgbAndHsv) {
  Hsv hsv = RgbToHsv(kMagenta);
  EXPECT_EQ(300, hsv.data.h);
  EXPECT_EQ(1, hsv.data.s);
  EXPECT_EQ(1, hsv.data.v);
  Rgb rgb = HsvToRgb(hsv);
  EXPECT_EQ(kMagenta, rgb);
}

}  // namespace color