// Copyright (c) 2019 The Color Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COLOR_EXPORT_H_
#define COLOR_EXPORT_H_

#if defined(COLOR_COMPONENT_BUILD)

#if defined(_WIN32)
#ifdef COLOR_COMPILE_LIBRARY
#define COLOR_EXPORT __declspec(dllexport)
#else
#define COLOR_EXPORT __declspec(dllimport)
#endif  // defined(COLOR_COMPILE_LIBRARY)

#else
#ifdef COLOR_COMPILE_LIBRARY
#define COLOR_EXPORT __attribute__((visibility("default")))
#else
#define COLOR_EXPORT
#endif  // defined(COLOR_COMPILE_LIBRARY)
#endif  // defined(_WIN32)

#else
#define COLOR_EXPORT
#endif  // defined(COLOR_COMPONENT_BUILD)

#endif  // COLOR_EXPORT_H_