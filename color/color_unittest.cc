// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/color.h"

#include "color/named_color.h"
#include "gtest/gtest.h"

namespace color {

TEST(Rgb, StringConvesion) {
  EXPECT_EQ(kGold.ToRgbString(), "rgb(255, 215, 0)");
  EXPECT_EQ(kGold.ToRgbaString(), "rgba(255, 215, 0, 255)");
  EXPECT_EQ(kGold.ToRgbHexString(), "#ffd700");
  EXPECT_EQ(kGold.ToRgbaHexString(), "#ffd700ff");

  Rgb rgb;
  EXPECT_FALSE(rgb.FromString("rgb(255, 215)"));
  EXPECT_FALSE(rgb.FromString("rgb(255, 215, 0"));
  EXPECT_TRUE(rgb.FromString("rgb(255, 215, 0)"));
  EXPECT_EQ(kGold, rgb);
  EXPECT_TRUE(rgb.FromString("rgba(255, 215, 0, 255)"));
  EXPECT_EQ(kGold, rgb);
  EXPECT_FALSE(rgb.FromString("rgb(255, 215, 0, 255"));
  EXPECT_FALSE(rgb.FromString("rgb(255, 215, 0, 255, 0)"));
  EXPECT_FALSE(rgb.FromString("#ffd7"));
  EXPECT_TRUE(rgb.FromString("#ffd700"));
  EXPECT_FALSE(rgb.FromString("#ffd70"));
  EXPECT_EQ(kGold, rgb);
  EXPECT_TRUE(rgb.FromString("#ffd700ff"));
  EXPECT_EQ(kGold, rgb);
  EXPECT_FALSE(rgb.FromString("#ffd700ff0"));
}

TEST(Hsv, StringConvesion) {
  Hsv hsv(0.1, 0.2, 0.3, 0.4);
  EXPECT_EQ(hsv.ToHsvString(), "hsv(0.100000, 0.200000, 0.300000)");
  EXPECT_EQ(hsv.ToHsvaString(), "hsva(0.100000, 0.200000, 0.300000, 0.400000)");

  Hsv hsv2;
  EXPECT_TRUE(hsv2.FromString("hsv(0.1, 0.2, 0.3)"));
  EXPECT_EQ(Hsv(0.1, 0.2, 0.3, 1), hsv2);
  EXPECT_TRUE(hsv2.FromString("hsva(0.1, 0.2, 0.3, 0.4)"));
  EXPECT_EQ(hsv, hsv2);
}

}  // namespace color