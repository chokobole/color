// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "color/color.h"

#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"

namespace color {

namespace {

// 0 ~ 255
template <typename T,
          std::enable_if_t<std::is_same<T, uint8_t>::value>* = nullptr>
bool StringToNumber(absl::string_view input, uint8_t* number) {
  unsigned n;
  if (!base::StringToUint(input, &n)) return false;
  if (n > 255) return false;
  *number = static_cast<uint8_t>(n);
  return true;
}

template <typename T,
          std::enable_if_t<std::is_same<T, float>::value>* = nullptr>
bool StringToNumber(absl::string_view input, float* number) {
  float n;
  if (!base::StringToFloat(input, &n)) return false;
  if (n > 1) return false;
  *number = n;
  return true;
}

// Parse comma separated numbers.
template <size_t N, typename T>
bool ParseCommaSeparatedNumbers(absl::string_view* input, T* numbers) {
  std::vector<absl::string_view> v =
      absl::StrSplit(*input, ',', absl::SkipWhitespace());
  if (v.size() != N) return false;
  T n_temps[N];
  for (size_t i = 0; i < N; ++i) {
    if (!StringToNumber<T>(v[i], &n_temps[i])) return false;
  }
  for (size_t i = 0; i < N; ++i) {
    numbers[i] = n_temps[i];
  }
  return true;
}

bool ParseRgbNumbers(absl::string_view* input, uint8_t* numbers) {
  return ParseCommaSeparatedNumbers<3>(input, numbers);
}

bool ParseRgbaNumbers(absl::string_view* input, uint8_t* numbers) {
  return ParseCommaSeparatedNumbers<4>(input, numbers);
}

bool ParseHsvNumbers(absl::string_view* input, float* numbers) {
  Hsv hsv;
  if (!ParseCommaSeparatedNumbers<3>(input, hsv.data.array)) return false;
  if (!hsv.IsValid()) return false;
  memcpy(numbers, hsv.data.array, sizeof(float) * 3);
  return true;
}

bool ParseHsvaNumbers(absl::string_view* input, float* numbers) {
  Hsv hsv;
  if (!ParseCommaSeparatedNumbers<4>(input, hsv.data.array)) return false;
  if (!hsv.IsValid()) return false;
  memcpy(numbers, hsv.data.array, sizeof(float) * 4);
  return true;
}

bool ConsumeHex(absl::string_view* input, uint8_t* c) {
  absl::string_view c_sv(input->data(), 2);
  uint32_t n;
  if (!base::HexStringToUint(c_sv, &n)) return false;
  if (n > 255) return false;
  *c = static_cast<uint8_t>(n);
  input->remove_prefix(2);
  return true;
}

bool ConsumeHexRgba(absl::string_view* input, uint8_t* r, uint8_t* g,
                    uint8_t* b, uint8_t* a) {
  uint8_t r_temp;
  uint8_t g_temp;
  uint8_t b_temp;
  uint8_t a_temp = 255;
  size_t len = input->length();
  if (len == 6 || len == 8) {
    if (!(ConsumeHex(input, &r_temp) && ConsumeHex(input, &g_temp) &&
          ConsumeHex(input, &b_temp)))
      return false;
    if (len == 8) {
      if (!ConsumeHex(input, &a_temp)) return false;
    }
  } else {
    return false;
  }

  *r = r_temp;
  *g = g_temp;
  *b = b_temp;
  *a = a_temp;

  return true;
}

}  // namespace

std::string Rgb::ToString() const { return ToRgbaString(); }

std::string Rgb::ToRgbString() const {
  return absl::StrFormat("rgb(%u, %u, %u)", data.r, data.g, data.b);
}

std::string Rgb::ToRgbaString() const {
  return absl::StrFormat("rgba(%u, %u, %u, %u)", data.r, data.g, data.b,
                         data.a);
}

std::string Rgb::ToRgbHexString() const {
  return absl::StrFormat("#%02x%02x%02x", data.r, data.g, data.b);
}

std::string Rgb::ToRgbaHexString() const {
  return absl::StrFormat("#%02x%02x%02x%02x", data.r, data.g, data.b, data.a);
}

bool Rgb::FromString(const std::string& text) {
  absl::string_view input(text);
  if (base::ConsumePrefix(&input, "rgb(") && base::ConsumeSuffix(&input, ")")) {
    if (ParseRgbNumbers(&input, data.array)) {
      data.a = 255;
      return true;
    }
  } else if (base::ConsumePrefix(&input, "rgba(") &&
             base::ConsumeSuffix(&input, ")")) {
    return ParseRgbaNumbers(&input, data.array);
  } else if (base::ConsumePrefix(&input, "#")) {
    return ConsumeHexRgba(&input, &data.r, &data.g, &data.b, &data.a);
  }

  return false;
}

std::ostream& operator<<(std::ostream& os, const Rgb& rgb) {
  return os << rgb.ToString();
}

std::string Hsv::ToString() const { return ToHsvaString(); }

std::string Hsv::ToHsvString() const {
  return absl::StrFormat("hsv(%f, %f, %f)", data.h, data.s, data.v);
}

std::string Hsv::ToHsvaString() const {
  return absl::StrFormat("hsva(%f, %f, %f, %f)", data.h, data.s, data.v,
                         data.a);
}

bool Hsv::FromString(const std::string& text) {
  absl::string_view input(text);
  if (base::ConsumePrefix(&input, "hsv(") && base::ConsumeSuffix(&input, ")")) {
    if (ParseHsvNumbers(&input, data.array)) {
      data.a = 1;
      return true;
    }
  } else if (base::ConsumePrefix(&input, "hsva(") &&
             base::ConsumeSuffix(&input, ")")) {
    return ParseHsvaNumbers(&input, data.array);
  } else {
    return false;
  }

  return false;
}

std::ostream& operator<<(std::ostream& os, const Hsv& hsv) {
  return os << hsv.ToString();
}

}  // namespace color