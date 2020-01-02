// Copyright (c) 2020 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// The name and stop colors are taken and modified from
// https://github.com/bpostlethwaite/colormap/blob/master/colorScale.js
#include "color/colormap.h"

namespace color {

Colormap::Colormap() = default;

Colormap::Colormap(const Colormap& other) = default;

Colormap& Colormap::operator=(const Colormap& other) = default;

bool Colormap::Jet(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 131), 0},
      {Rgb(0, 60, 170), 0.125},
      {Rgb(5, 255, 255), 0.375},
      {Rgb(255, 255, 0), 0.625},
      {Rgb(255, 0, 0), 0.875},
      {Rgb(128, 0, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Hsv(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(255, 0, 0), 0},
      {Rgb(253, 255, 2), 0.169},
      {Rgb(247, 255, 2), 0.173},
      {Rgb(0, 252, 4), 0.337},
      {Rgb(0, 252, 10), 0.341},
      {Rgb(1, 249, 255), 0.506},
      {Rgb(2, 0, 253), 0.671},
      {Rgb(8, 0, 253), 0.675},
      {Rgb(255, 0, 251), 0.839},
      {Rgb(255, 0, 245), 0.843},
      {Rgb(255, 0, 6), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Hot(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(230, 0, 0), 0.3},
      {Rgb(255, 210, 0), 0.6},
      {Rgb(255, 255, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Cool(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(125, 0, 179), 0},
      {Rgb(116, 0, 218), 0.13},
      {Rgb(98, 74, 237), 0.25},
      {Rgb(68, 146, 231), 0.38},
      {Rgb(0, 204, 197), 0.5},
      {Rgb(0, 247, 146), 0.63},
      {Rgb(0, 255, 88), 0.75},
      {Rgb(40, 255, 8), 0.88},
      {Rgb(147, 255, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Spring(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(255, 0, 255), 0},
      {Rgb(255, 255, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Summer(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 128, 102), 0},
      {Rgb(255, 255, 102), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Autumn(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(255, 0, 0), 0},
      {Rgb(255, 255, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Winter(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 255), 0},
      {Rgb(0, 255, 128), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Bone(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(84, 84, 116), 0.376},
      {Rgb(169, 200, 200), 0.753},
      {Rgb(255, 255, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Copper(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(255, 160, 102), 0.804},
      {Rgb(255, 199, 127), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Greys(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(255, 255, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Greens(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 68, 27), 0},
      {Rgb(0, 109, 44), 0.125},
      {Rgb(35, 139, 69), 0.25},
      {Rgb(65, 171, 93), 0.375},
      {Rgb(116, 196, 118), 0.5},
      {Rgb(161, 217, 155), 0.625},
      {Rgb(199, 233, 192), 0.75},
      {Rgb(229, 245, 224), 0.875},
      {Rgb(247, 252, 245), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::BlueRed(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 255), 0},
      {Rgb(255, 0, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::YIGnBu(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(8, 29, 88), 0},
      {Rgb(37, 52, 148), 0.125},
      {Rgb(34, 94, 168), 0.25},
      {Rgb(29, 145, 192), 0.375},
      {Rgb(65, 182, 196), 0.5},
      {Rgb(127, 205, 187), 0.625},
      {Rgb(199, 233, 180), 0.75},
      {Rgb(237, 248, 217), 0.875},
      {Rgb(255, 255, 217), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::YIOrRd(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(128, 0, 38), 0},
      {Rgb(189, 0, 38), 0.125},
      {Rgb(227, 26, 28), 0.25},
      {Rgb(252, 78, 42), 0.375},
      {Rgb(253, 141, 60), 0.5},
      {Rgb(254, 178, 76), 0.625},
      {Rgb(254, 217, 118), 0.75},
      {Rgb(255, 237, 160), 0.875},
      {Rgb(255, 255, 204), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::RdBu(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(5, 10, 172), 0},
      {Rgb(106, 137, 247), 0.35},
      {Rgb(190, 190, 190), 0.5},
      {Rgb(220, 170, 132), 0.6},
      {Rgb(230, 145, 90), 0.7},
      {Rgb(178, 10, 28), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Picnic(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 255), 0},
      {Rgb(51, 153, 255), 0.1},
      {Rgb(102, 204, 255), 0.2},
      {Rgb(153, 204, 255), 0.3},
      {Rgb(204, 204, 255), 0.4},
      {Rgb(255, 255, 255), 0.5},
      {Rgb(255, 204, 255), 0.6},
      {Rgb(255, 153, 255), 0.7},
      {Rgb(255, 102, 204), 0.8},
      {Rgb(255, 102, 102), 0.9},
      {Rgb(255, 0, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Rainbow(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(150, 0, 90), 0},
      {Rgb(0, 0, 200), 0.125},
      {Rgb(0, 25, 255), 0.25},
      {Rgb(0, 152, 255), 0.375},
      {Rgb(44, 255, 150), 0.5},
      {Rgb(151, 255, 0), 0.625},
      {Rgb(255, 234, 0), 0.75},
      {Rgb(255, 111, 0), 0.875},
      {Rgb(255, 0, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::RainbowSoft(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(125, 0, 179), 0},
      {Rgb(199, 0, 180), 0.1},
      {Rgb(255, 0, 121), 0.2},
      {Rgb(255, 108, 0), 0.3},
      {Rgb(222, 194, 0), 0.4},
      {Rgb(150, 255, 0), 0.5},
      {Rgb(0, 255, 55), 0.6},
      {Rgb(0, 246, 150), 0.7},
      {Rgb(50, 167, 222), 0.8},
      {Rgb(103, 51, 235), 0.9},
      {Rgb(124, 0, 186), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Portland(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(12, 51, 131), 0},
      {Rgb(10, 136, 186), 0.25},
      {Rgb(242, 211, 56), 0.5},
      {Rgb(242, 143, 56), 0.75},
      {Rgb(217, 30, 30), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::BlackBody(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(230, 0, 0), 0.2},
      {Rgb(230, 210, 0), 0.4},
      {Rgb(255, 255, 255), 0.7},
      {Rgb(160, 200, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Earth(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 130), 0},
      {Rgb(0, 180, 180), 0.1},
      {Rgb(40, 210, 40), 0.2},
      {Rgb(230, 230, 50), 0.4},
      {Rgb(120, 70, 20), 0.6},
      {Rgb(255, 255, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Electric(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(30, 0, 100), 0.15},
      {Rgb(120, 0, 100), 0.4},
      {Rgb(160, 90, 0), 0.6},
      {Rgb(230, 200, 0), 0.8},
      {Rgb(255, 250, 220), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Alpha(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(255, 255, 255), 0},
      {Rgb(255, 255, 255), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Viridis(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(68, 1, 84), 0},
      {Rgb(71, 44, 122), 0.13},
      {Rgb(59, 81, 139), 0.25},
      {Rgb(44, 113, 142), 0.38},
      {Rgb(33, 144, 141), 0.5},
      {Rgb(39, 173, 129), 0.63},
      {Rgb(92, 200, 99), 0.75},
      {Rgb(170, 220, 50), 0.88},
      {Rgb(253, 231, 37), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Inferno(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 4), 0},
      {Rgb(31, 12, 72), 0.13},
      {Rgb(85, 15, 109), 0.25},
      {Rgb(136, 34, 106), 0.38},
      {Rgb(186, 54, 85), 0.5},
      {Rgb(227, 89, 51), 0.63},
      {Rgb(249, 140, 10), 0.75},
      {Rgb(249, 201, 50), 0.88},
      {Rgb(252, 255, 164), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Magma(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 4), 0},
      {Rgb(28, 16, 68), 0.13},
      {Rgb(79, 18, 123), 0.25},
      {Rgb(129, 37, 129), 0.38},
      {Rgb(181, 54, 122), 0.5},
      {Rgb(229, 80, 100), 0.63},
      {Rgb(251, 135, 97), 0.75},
      {Rgb(254, 194, 135), 0.88},
      {Rgb(252, 253, 191), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Plasma(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(13, 8, 135), 0},
      {Rgb(75, 3, 161), 0.13},
      {Rgb(125, 3, 168), 0.25},
      {Rgb(168, 34, 150), 0.38},
      {Rgb(203, 70, 121), 0.5},
      {Rgb(229, 107, 93), 0.63},
      {Rgb(248, 148, 65), 0.75},
      {Rgb(253, 195, 40), 0.88},
      {Rgb(240, 249, 33), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Warm(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(125, 0, 179), 0},
      {Rgb(172, 0, 187), 0.13},
      {Rgb(219, 0, 170), 0.25},
      {Rgb(255, 0, 130), 0.38},
      {Rgb(255, 63, 74), 0.5},
      {Rgb(255, 123, 0), 0.63},
      {Rgb(234, 176, 0), 0.75},
      {Rgb(190, 228, 0), 0.88},
      {Rgb(147, 255, 0), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Bathymetry(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(40, 26, 44), 0},
      {Rgb(59, 49, 90), 0.13},
      {Rgb(64, 76, 139), 0.25},
      {Rgb(63, 110, 151), 0.38},
      {Rgb(72, 142, 158), 0.5},
      {Rgb(85, 174, 163), 0.63},
      {Rgb(120, 206, 163), 0.75},
      {Rgb(187, 230, 172), 0.88},
      {Rgb(253, 254, 204), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::CDOM(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(47, 15, 62), 0},
      {Rgb(87, 23, 86), 0.13},
      {Rgb(130, 28, 99), 0.25},
      {Rgb(171, 41, 96), 0.38},
      {Rgb(206, 67, 86), 0.5},
      {Rgb(230, 106, 84), 0.63},
      {Rgb(242, 149, 103), 0.75},
      {Rgb(249, 193, 135), 0.88},
      {Rgb(254, 237, 176), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Chlorophyll(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(18, 36, 20), 0},
      {Rgb(25, 63, 41), 0.13},
      {Rgb(24, 91, 59), 0.25},
      {Rgb(13, 119, 72), 0.38},
      {Rgb(18, 148, 80), 0.5},
      {Rgb(80, 173, 89), 0.63},
      {Rgb(132, 196, 122), 0.75},
      {Rgb(175, 221, 162), 0.88},
      {Rgb(215, 249, 208), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Density(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(54, 14, 36), 0},
      {Rgb(89, 23, 80), 0.13},
      {Rgb(110, 45, 132), 0.25},
      {Rgb(120, 77, 178), 0.38},
      {Rgb(120, 113, 213), 0.5},
      {Rgb(115, 151, 228), 0.63},
      {Rgb(134, 185, 227), 0.75},
      {Rgb(177, 214, 227), 0.88},
      {Rgb(230, 241, 241), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::FreeSurface_Blue(size_t numbers,
                                std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(30, 4, 110), 0},
      {Rgb(47, 14, 176), 0.13},
      {Rgb(41, 45, 236), 0.25},
      {Rgb(25, 99, 212), 0.38},
      {Rgb(68, 131, 200), 0.5},
      {Rgb(114, 156, 197), 0.63},
      {Rgb(157, 181, 203), 0.75},
      {Rgb(200, 208, 216), 0.88},
      {Rgb(241, 237, 236), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::FreeSurface_Red(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(60, 9, 18), 0},
      {Rgb(100, 17, 27), 0.13},
      {Rgb(142, 20, 29), 0.25},
      {Rgb(177, 43, 27), 0.38},
      {Rgb(192, 87, 63), 0.5},
      {Rgb(205, 125, 105), 0.63},
      {Rgb(216, 162, 148), 0.75},
      {Rgb(227, 199, 193), 0.88},
      {Rgb(241, 237, 236), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Oxygen(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(64, 5, 5), 0},
      {Rgb(106, 6, 15), 0.13},
      {Rgb(144, 26, 7), 0.25},
      {Rgb(168, 64, 3), 0.38},
      {Rgb(188, 100, 4), 0.5},
      {Rgb(206, 136, 11), 0.63},
      {Rgb(220, 174, 25), 0.75},
      {Rgb(231, 215, 44), 0.88},
      {Rgb(248, 254, 105), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Par(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(51, 20, 24), 0},
      {Rgb(90, 32, 35), 0.13},
      {Rgb(129, 44, 34), 0.25},
      {Rgb(159, 68, 25), 0.38},
      {Rgb(182, 99, 19), 0.5},
      {Rgb(199, 134, 22), 0.63},
      {Rgb(212, 171, 35), 0.75},
      {Rgb(221, 210, 54), 0.88},
      {Rgb(225, 253, 75), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Phase(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(145, 105, 18), 0},
      {Rgb(184, 71, 38), 0.13},
      {Rgb(186, 58, 115), 0.25},
      {Rgb(160, 71, 185), 0.38},
      {Rgb(110, 97, 218), 0.5},
      {Rgb(50, 123, 164), 0.63},
      {Rgb(31, 131, 110), 0.75},
      {Rgb(77, 129, 34), 0.88},
      {Rgb(145, 105, 18), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Salinity(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(42, 24, 108), 0},
      {Rgb(33, 50, 162), 0.13},
      {Rgb(15, 90, 145), 0.25},
      {Rgb(40, 118, 137), 0.38},
      {Rgb(59, 146, 135), 0.5},
      {Rgb(79, 175, 126), 0.63},
      {Rgb(120, 203, 104), 0.75},
      {Rgb(193, 221, 100), 0.88},
      {Rgb(253, 239, 154), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Temperature(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(4, 35, 51), 0},
      {Rgb(23, 51, 122), 0.13},
      {Rgb(85, 59, 157), 0.25},
      {Rgb(129, 79, 143), 0.38},
      {Rgb(175, 95, 130), 0.5},
      {Rgb(222, 112, 101), 0.63},
      {Rgb(249, 146, 66), 0.75},
      {Rgb(249, 196, 65), 0.88},
      {Rgb(232, 250, 91), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Turbidity(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(34, 31, 27), 0},
      {Rgb(65, 50, 41), 0.13},
      {Rgb(98, 69, 52), 0.25},
      {Rgb(131, 89, 57), 0.38},
      {Rgb(161, 112, 59), 0.5},
      {Rgb(185, 140, 66), 0.63},
      {Rgb(202, 174, 88), 0.75},
      {Rgb(216, 209, 126), 0.88},
      {Rgb(233, 246, 171), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Velocity_Blue(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(17, 32, 64), 0},
      {Rgb(35, 52, 116), 0.13},
      {Rgb(29, 81, 156), 0.25},
      {Rgb(31, 113, 162), 0.38},
      {Rgb(50, 144, 169), 0.5},
      {Rgb(87, 173, 176), 0.63},
      {Rgb(149, 196, 189), 0.75},
      {Rgb(203, 221, 211), 0.88},
      {Rgb(254, 251, 230), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Velocity_Green(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(23, 35, 19), 0},
      {Rgb(24, 64, 38), 0.13},
      {Rgb(11, 95, 45), 0.25},
      {Rgb(39, 123, 35), 0.38},
      {Rgb(95, 146, 12), 0.5},
      {Rgb(152, 165, 18), 0.63},
      {Rgb(201, 186, 69), 0.75},
      {Rgb(233, 216, 137), 0.88},
      {Rgb(255, 253, 205), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

bool Colormap::Cubehelix(size_t numbers, std::vector<Rgb>* colors) const {
  std::vector<StopColor> stop_colors({
      {Rgb(0, 0, 0), 0},
      {Rgb(22, 5, 59), 0.07},
      {Rgb(60, 4, 105), 0.13},
      {Rgb(109, 1, 135), 0.2},
      {Rgb(161, 0, 147), 0.27},
      {Rgb(210, 2, 142), 0.33},
      {Rgb(251, 11, 123), 0.4},
      {Rgb(255, 29, 97), 0.47},
      {Rgb(255, 54, 69), 0.53},
      {Rgb(255, 85, 46), 0.6},
      {Rgb(255, 120, 34), 0.67},
      {Rgb(255, 157, 37), 0.73},
      {Rgb(241, 191, 57), 0.8},
      {Rgb(224, 220, 93), 0.87},
      {Rgb(218, 241, 142), 0.93},
      {Rgb(227, 253, 198), 1},
  });
  Gradient gradient(stop_colors);
  return gradient.Colors(numbers, colors);
}

}  // namespace color