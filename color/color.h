// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_COLOR_H_
#define COLOR_COLOR_H_

#include <stdint.h>

#include <string>

namespace color {

struct Rgb {
  constexpr Rgb() {}
  constexpr Rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
      : data(r, g, b, a) {}
  // This is convenience constructor.
  // e.g) Without this, Rgb(0, 0, 0) makes you annoyed!
  constexpr Rgb(int r, int g, int b, int a = 255)
      : Rgb(static_cast<uint8_t>(r), static_cast<uint8_t>(g),
            static_cast<uint8_t>(b), static_cast<uint8_t>(a)) {}
  // |r|, |g|, |b| and |a| should be in 0 to 1.
  constexpr Rgb(float r, float g, float b, float a = 1) : data(r, g, b, a) {}

  Rgb(const Rgb& other) = default;
  Rgb& operator=(const Rgb& other) = default;

  // Converts to std::string. It's redirected to ToRgbaString().
  std::string ToString() const;
  // Converts to std::string.
  // e.g) if (r, g, b, a) is (0, 0, 0, 1), then it returns "rgb(0, 0, 0)".
  std::string ToRgbString() const;
  // Converts to std::string.
  // e.g) if (r, g, b, a) is (0, 0, 0, 1) and |hex| is false, then it returns
  // "rgba(0, 0, 0, 1)". Or |hex| is true, it returns "#00000001".
  std::string ToRgbaString() const;
  // Converts to std::string.
  // e.g) if (r, g, b, a) is (255, 0, 0, 1), it returns "#ff0000".
  std::string ToRgbHexString() const;
  // Converts to std::string.
  // e.g) if (r, g, b, a) is (255, 0, 0, 1), it returns "#ff000001".
  std::string ToRgbaHexString() const;
  // Converts from std::string. Returns true if succeeded.
  // Expected form is "rgb(r, g, b)", "rgba(r, g, b, a), #abcdef or "#ABCDEF".
  bool FromString(const std::string& text);

  constexpr bool IsValid() const { return true; }

  union Data {
    struct {
      uint8_t r;
      uint8_t g;
      uint8_t b;
      uint8_t a;
    };
    uint8_t array[4];
    uint32_t rgba;

    constexpr Data() : rgba(0) {}
    constexpr Data(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r), g(g), b(b), a(a) {}
    constexpr Data(float r, float g, float b, float a)
        : r(r * 255), g(g * 255), b(b * 255), a(a * 255) {}

  } data;
};

inline bool operator==(const Rgb& rgb, const Rgb& rgb2) {
  return rgb.data.rgba == rgb2.data.rgba;
}

inline bool operator!=(const Rgb& rgb, const Rgb& rgb2) {
  return !operator==(rgb, rgb2);
}

std::ostream& operator<<(std::ostream& os, const Rgb& rgb);

struct Hsv {
  constexpr Hsv() {}
  constexpr Hsv(float h, float s, float v, float a = 1) : data(h, s, v, a) {}

  Hsv(const Hsv& other) = default;
  Hsv& operator=(const Hsv& other) = default;

  // Converts to std::string. It's redirected to ToHsvaString().
  std::string ToString() const;
  // Converts to std::string.
  // e.g) if (h, s, v, a) is (0, 0, 0, 1), then it returns "hsv(0, 0, 0)".
  std::string ToHsvString() const;
  // e.g) if (h, s, v, a) is (0, 0, 0, 1), then it returns "hsva(0, 0, 0, 1)".
  std::string ToHsvaString() const;
  // Converts from std::string. Returns true if succeeded.
  // Expected form is "hsv(h, s, v)" or "hsva(h, s, v, a)".
  bool FromString(const std::string& text);

  constexpr bool IsValid() const {
    return data.h >= 0 && data.h <= 360 && data.s >= 0 && data.s <= 1 &&
           data.v >= 0 && data.v <= 1 && data.a >= 0 && data.a <= 1;
  }

  union Data {
    struct {
      float h;
      float s;
      float v;
      float a;
    };
    float array[4];

    constexpr Data() : array{0} {}
    constexpr Data(float h, float s, float v, float a)
        : h(h), s(s), v(v), a(a) {}
  } data;
};

inline bool operator==(const Hsv& hsv, const Hsv& hsv2) {
  return hsv.data.h == hsv2.data.h && hsv.data.s == hsv2.data.s &&
         hsv.data.v == hsv2.data.v && hsv.data.a == hsv2.data.a;
}

inline bool operator!=(const Hsv& hsv, const Hsv& hsv2) {
  return !operator==(hsv, hsv2);
}

std::ostream& operator<<(std::ostream& os, const Hsv& hsv);

}  // namespace color

#endif  // COLOR_COLOR_H_