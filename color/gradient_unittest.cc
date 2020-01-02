// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/gradient.h"

#include "color/color_conversion.h"
#include "color/named_color.h"
#include "gtest/gtest.h"

namespace color {

TEST(Gradient, ColorsReturnFalse) {
  Gradient gradient;
  std::vector<Rgb> colors;
  EXPECT_FALSE(gradient.Colors(0, &colors));
  gradient = Gradient({kOlive});
  EXPECT_FALSE(gradient.Colors(0, &colors));
  EXPECT_FALSE(gradient.Colors(1, &colors));
  gradient = Gradient({kOlive, kBlue});
  EXPECT_FALSE(gradient.Colors(0, &colors));
  EXPECT_TRUE(gradient.Colors(1, &colors));
  EXPECT_TRUE(gradient.Colors(2, &colors));
}

TEST(Gradient, ColorsRgb) {
  Rgb from_color(200, 200, 0);
  Rgb to_color(0, 0, 200);

  Gradient gradient({from_color, to_color});
  std::vector<Rgb> colors;
  EXPECT_TRUE(gradient.Colors(5, &colors));
  EXPECT_EQ(colors.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(colors[i].data.r, 50 * (4 - i));
    EXPECT_EQ(colors[i].data.g, 50 * (4 - i));
    EXPECT_EQ(colors[i].data.b, 50 * i);
  }

  StopColor stop_color(Rgb(30, 0, 20), 0.2);
  Gradient gradient2({from_color, to_color, stop_color});
  EXPECT_TRUE(gradient2.Colors(5, &colors));
  EXPECT_EQ(colors[0], from_color);
  for (size_t i = 1; i < 5; ++i) {
    EXPECT_EQ(colors[i].data.r, 10 * (4 - i));
    EXPECT_EQ(colors[i].data.g, 0);
    EXPECT_EQ(colors[i].data.b, 20 + 60 * (i - 1));
  }
}

}  // namespace color