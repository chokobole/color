// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_NAMED_COLOR_H_
#define COLOR_NAMED_COLOR_H_

#include "color/color.h"

namespace color {

// https://developer.mozilla.org/ko/docs/Web/CSS/color_value

// CSS Level 1
constexpr const Rgb kBlack = Rgb(0, 0, 0);
constexpr const Rgb kSilver = Rgb(192, 192, 192);
constexpr const Rgb kGray = Rgb(128, 128, 128);
constexpr const Rgb kWhite = Rgb(255, 255, 255);
constexpr const Rgb kMaroon = Rgb(128, 0, 0);
constexpr const Rgb kRed = Rgb(255, 0, 0);
constexpr const Rgb kPurple = Rgb(128, 0, 128);
constexpr const Rgb kFuchsia = Rgb(255, 0, 255);
constexpr const Rgb kGreen = Rgb(0, 128, 0);
constexpr const Rgb kLime = Rgb(0, 255, 0);
constexpr const Rgb kOlive = Rgb(128, 128, 0);
constexpr const Rgb kYellow = Rgb(255, 255, 0);
constexpr const Rgb kNavy = Rgb(0, 0, 128);
constexpr const Rgb kBlue = Rgb(0, 0, 255);
constexpr const Rgb kTeal = Rgb(0, 128, 128);
constexpr const Rgb kAqua = Rgb(0, 255, 255);
// CSS Level 2(Reveision 1)
constexpr const Rgb kOrange = Rgb(255, 165, 0);
// CSS Color Module Level 3
constexpr const Rgb kAliceblue = Rgb(240, 248, 255);
constexpr const Rgb kAntiquewhite = Rgb(250, 235, 215);
constexpr const Rgb kAquamarine = Rgb(127, 255, 212);
constexpr const Rgb kAzure = Rgb(240, 255, 255);
constexpr const Rgb kBeige = Rgb(245, 245, 220);
constexpr const Rgb kBisque = Rgb(255, 228, 196);
constexpr const Rgb kBlanchedalmond = Rgb(255, 235, 205);
constexpr const Rgb kBlueviolet = Rgb(138, 43, 226);
constexpr const Rgb kBrown = Rgb(165, 42, 42);
constexpr const Rgb kBurlywood = Rgb(222, 184, 135);
constexpr const Rgb kCadetblue = Rgb(95, 158, 160);
constexpr const Rgb kChartreuse = Rgb(127, 255, 0);
constexpr const Rgb kChocolate = Rgb(210, 105, 30);
constexpr const Rgb kCoral = Rgb(255, 127, 80);
constexpr const Rgb kCornflowerblue = Rgb(100, 149, 237);
constexpr const Rgb kCornsilk = Rgb(255, 248, 220);
constexpr const Rgb kCrimson = Rgb(220, 20, 60);
constexpr const Rgb kCyan = Rgb(0, 255, 255);
constexpr const Rgb kDarkblue = Rgb(0, 0, 139);
constexpr const Rgb kDarkcyan = Rgb(0, 139, 139);
constexpr const Rgb kDarkgoldenrod = Rgb(184, 134, 11);
constexpr const Rgb kDarkgray = Rgb(169, 169, 169);
constexpr const Rgb kDarkgreen = Rgb(0, 100, 0);
constexpr const Rgb kDarkgrey = Rgb(169, 169, 169);
constexpr const Rgb kDarkkhaki = Rgb(189, 183, 107);
constexpr const Rgb kDarkmagenta = Rgb(139, 0, 139);
constexpr const Rgb kDarkolivegreen = Rgb(85, 107, 47);
constexpr const Rgb kDarkorange = Rgb(255, 140, 0);
constexpr const Rgb kDarkorchid = Rgb(153, 50, 204);
constexpr const Rgb kDarkred = Rgb(139, 0, 0);
constexpr const Rgb kDarksalmon = Rgb(233, 150, 122);
constexpr const Rgb kDarkseagreen = Rgb(143, 188, 143);
constexpr const Rgb kDarkslateblue = Rgb(72, 61, 139);
constexpr const Rgb kDarkslategray = Rgb(47, 79, 79);
constexpr const Rgb kDarkslategrey = Rgb(47, 79, 79);
constexpr const Rgb kDarkturquoise = Rgb(0, 206, 209);
constexpr const Rgb kDarkviolet = Rgb(148, 0, 211);
constexpr const Rgb kDeeppink = Rgb(255, 20, 147);
constexpr const Rgb kDeepskyblue = Rgb(0, 191, 255);
constexpr const Rgb kDimgray = Rgb(105, 105, 105);
constexpr const Rgb kDimgrey = Rgb(105, 105, 105);
constexpr const Rgb kDodgerblue = Rgb(30, 144, 255);
constexpr const Rgb kFirebrick = Rgb(178, 34, 34);
constexpr const Rgb kFloralwhite = Rgb(255, 250, 240);
constexpr const Rgb kForestgreen = Rgb(34, 139, 34);
constexpr const Rgb kGainsboro = Rgb(220, 220, 220);
constexpr const Rgb kGhostwhite = Rgb(248, 248, 255);
constexpr const Rgb kGold = Rgb(255, 215, 0);
constexpr const Rgb kGoldenrod = Rgb(218, 165, 32);
constexpr const Rgb kGreenyellow = Rgb(173, 255, 47);
constexpr const Rgb kGrey = Rgb(128, 128, 128);
constexpr const Rgb kHoneydew = Rgb(240, 255, 240);
constexpr const Rgb kHotpink = Rgb(255, 105, 180);
constexpr const Rgb kIndianred = Rgb(205, 92, 92);
constexpr const Rgb kIndigo = Rgb(75, 0, 130);
constexpr const Rgb kIvory = Rgb(255, 255, 240);
constexpr const Rgb kKhaki = Rgb(240, 230, 140);
constexpr const Rgb kLavender = Rgb(230, 230, 250);
constexpr const Rgb kLavenderblush = Rgb(255, 240, 245);
constexpr const Rgb kLawngreen = Rgb(124, 252, 0);
constexpr const Rgb kLemonchiffon = Rgb(255, 250, 205);
constexpr const Rgb kLightblue = Rgb(173, 216, 230);
constexpr const Rgb kLightcoral = Rgb(240, 128, 128);
constexpr const Rgb kLightcyan = Rgb(224, 255, 255);
constexpr const Rgb kLightgoldenrodyellow = Rgb(250, 250, 210);
constexpr const Rgb kLightgray = Rgb(211, 211, 211);
constexpr const Rgb kLightgreen = Rgb(144, 238, 144);
constexpr const Rgb kLightgrey = Rgb(211, 211, 211);
constexpr const Rgb kLightpink = Rgb(255, 182, 193);
constexpr const Rgb kLightsalmon = Rgb(255, 160, 122);
constexpr const Rgb kLightseagreen = Rgb(32, 178, 170);
constexpr const Rgb kLightskyblue = Rgb(135, 206, 250);
constexpr const Rgb kLightslategray = Rgb(119, 136, 153);
constexpr const Rgb kLightslategrey = Rgb(119, 136, 153);
constexpr const Rgb kLightsteelblue = Rgb(176, 196, 222);
constexpr const Rgb kLightyellow = Rgb(255, 255, 224);
constexpr const Rgb kLimegreen = Rgb(50, 205, 50);
constexpr const Rgb kLinen = Rgb(250, 240, 230);
constexpr const Rgb kMagenta = Rgb(255, 0, 255);
constexpr const Rgb kMediumaquamarine = Rgb(102, 205, 170);
constexpr const Rgb kMediumblue = Rgb(0, 0, 205);
constexpr const Rgb kMediumorchid = Rgb(186, 85, 211);
constexpr const Rgb kMediumpurple = Rgb(147, 112, 219);
constexpr const Rgb kMediumseagreen = Rgb(60, 179, 113);
constexpr const Rgb kMediumslateblue = Rgb(123, 104, 238);
constexpr const Rgb kMediumspringgreen = Rgb(0, 250, 154);
constexpr const Rgb kMediumturquoise = Rgb(72, 209, 204);
constexpr const Rgb kMediumvioletred = Rgb(199, 21, 133);
constexpr const Rgb kMidnightblue = Rgb(25, 25, 112);
constexpr const Rgb kMintcream = Rgb(245, 255, 250);
constexpr const Rgb kMistyrose = Rgb(255, 228, 225);
constexpr const Rgb kMoccasin = Rgb(255, 228, 181);
constexpr const Rgb kNavajowhite = Rgb(255, 222, 173);
constexpr const Rgb kOldlace = Rgb(253, 245, 230);
constexpr const Rgb kOlivedrab = Rgb(107, 142, 35);
constexpr const Rgb kOrangered = Rgb(255, 69, 0);
constexpr const Rgb kOrchid = Rgb(218, 112, 214);
constexpr const Rgb kPalegoldenrod = Rgb(238, 232, 170);
constexpr const Rgb kPalegreen = Rgb(152, 251, 152);
constexpr const Rgb kPaleturquoise = Rgb(175, 238, 238);
constexpr const Rgb kPalevioletred = Rgb(219, 112, 147);
constexpr const Rgb kPapayawhip = Rgb(255, 239, 213);
constexpr const Rgb kPeachpuff = Rgb(255, 218, 185);
constexpr const Rgb kPeru = Rgb(205, 133, 63);
constexpr const Rgb kPink = Rgb(255, 192, 203);
constexpr const Rgb kPlum = Rgb(221, 160, 221);
constexpr const Rgb kPowderblue = Rgb(176, 224, 230);
constexpr const Rgb kRosybrown = Rgb(188, 143, 143);
constexpr const Rgb kRoyalblue = Rgb(65, 105, 225);
constexpr const Rgb kSaddlebrown = Rgb(139, 69, 19);
constexpr const Rgb kSalmon = Rgb(250, 128, 114);
constexpr const Rgb kSandybrown = Rgb(244, 164, 96);
constexpr const Rgb kSeagreen = Rgb(46, 139, 87);
constexpr const Rgb kSeashell = Rgb(255, 245, 238);
constexpr const Rgb kSienna = Rgb(160, 82, 45);
constexpr const Rgb kSkyblue = Rgb(135, 206, 235);
constexpr const Rgb kSlateblue = Rgb(106, 90, 205);
constexpr const Rgb kSlategray = Rgb(112, 128, 144);
constexpr const Rgb kSlategrey = Rgb(112, 128, 144);
constexpr const Rgb kSnow = Rgb(255, 250, 250);
constexpr const Rgb kSpringgreen = Rgb(0, 255, 127);
constexpr const Rgb kSteelblue = Rgb(70, 130, 180);
constexpr const Rgb kTan = Rgb(210, 180, 140);
constexpr const Rgb kThistle = Rgb(216, 191, 216);
constexpr const Rgb kTomato = Rgb(255, 99, 71);
constexpr const Rgb kTurquoise = Rgb(64, 224, 208);
constexpr const Rgb kViolet = Rgb(238, 130, 238);
constexpr const Rgb kWheat = Rgb(245, 222, 179);
constexpr const Rgb kWhitesmoke = Rgb(245, 245, 245);
constexpr const Rgb kYellowgreen = Rgb(154, 205, 50);
// CSS Color Module Level 4
constexpr const Rgb kRebeccapurple = Rgb(102, 51, 153);

}  // namespace color

#endif  // COLOR_NAMED_COLOR_H_