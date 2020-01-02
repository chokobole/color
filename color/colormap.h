// Copyright (c) 2020 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_COLORMAP_H_
#define COLOR_COLORMAP_H_

#include "color/export.h"
#include "color/gradient.h"

namespace color {

class COLOR_EXPORT Colormap {
 public:
  Colormap();
  Colormap(const Colormap& other);
  Colormap& operator=(const Colormap& other);

  bool Jet(size_t numbers, std::vector<Rgb>* colors) const;
  bool Hsv(size_t numbers, std::vector<Rgb>* colors) const;

  bool Hot(size_t numbers, std::vector<Rgb>* colors) const;
  bool Cool(size_t numbers, std::vector<Rgb>* colors) const;

  bool Spring(size_t numbers, std::vector<Rgb>* colors) const;
  bool Summer(size_t numbers, std::vector<Rgb>* colors) const;
  bool Autumn(size_t numbers, std::vector<Rgb>* colors) const;
  bool Winter(size_t numbers, std::vector<Rgb>* colors) const;

  bool Bone(size_t numbers, std::vector<Rgb>* colors) const;
  bool Copper(size_t numbers, std::vector<Rgb>* colors) const;

  bool Greys(size_t numbers, std::vector<Rgb>* colors) const;
  bool Greens(size_t numbers, std::vector<Rgb>* colors) const;

  bool BlueRed(size_t numbers, std::vector<Rgb>* colors) const;

  bool YIGnBu(size_t numbers, std::vector<Rgb>* colors) const;
  bool YIOrRd(size_t numbers, std::vector<Rgb>* colors) const;

  bool RdBu(size_t numbers, std::vector<Rgb>* colors) const;
  bool Picnic(size_t numbers, std::vector<Rgb>* colors) const;
  bool Rainbow(size_t numbers, std::vector<Rgb>* colors) const;
  bool RainbowSoft(size_t numbers, std::vector<Rgb>* colors) const;
  bool Portland(size_t numbers, std::vector<Rgb>* colors) const;
  bool BlackBody(size_t numbers, std::vector<Rgb>* colors) const;
  bool Earth(size_t numbers, std::vector<Rgb>* colors) const;
  bool Electric(size_t numbers, std::vector<Rgb>* colors) const;
  bool Alpha(size_t numbers, std::vector<Rgb>* colors) const;

  bool Viridis(size_t numbers, std::vector<Rgb>* colors) const;
  bool Inferno(size_t numbers, std::vector<Rgb>* colors) const;
  bool Magma(size_t numbers, std::vector<Rgb>* colors) const;
  bool Plasma(size_t numbers, std::vector<Rgb>* colors) const;

  bool Warm(size_t numbers, std::vector<Rgb>* colors) const;
  bool Bathymetry(size_t numbers, std::vector<Rgb>* colors) const;
  bool CDOM(size_t numbers, std::vector<Rgb>* colors) const;
  bool Chlorophyll(size_t numbers, std::vector<Rgb>* colors) const;
  bool Density(size_t numbers, std::vector<Rgb>* colors) const;
  bool FreeSurface_Blue(size_t numbers, std::vector<Rgb>* colors) const;
  bool FreeSurface_Red(size_t numbers, std::vector<Rgb>* colors) const;
  bool Oxygen(size_t numbers, std::vector<Rgb>* colors) const;
  bool Par(size_t numbers, std::vector<Rgb>* colors) const;
  bool Phase(size_t numbers, std::vector<Rgb>* colors) const;
  bool Salinity(size_t numbers, std::vector<Rgb>* colors) const;
  bool Temperature(size_t numbers, std::vector<Rgb>* colors) const;
  bool Turbidity(size_t numbers, std::vector<Rgb>* colors) const;
  bool Velocity_Blue(size_t numbers, std::vector<Rgb>* colors) const;
  bool Velocity_Green(size_t numbers, std::vector<Rgb>* colors) const;
  bool Cubehelix(size_t numbers, std::vector<Rgb>* colors) const;
};

}  // namespace color

#endif  // COLOR_COLORMAP_H_