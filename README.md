# Color

A C++ utility library for color.

## Contents
- [Color](#color)
  - [Contents](#contents)
  - [How to use](#how-to-use)
  - [Usages](#usages)
    - [Supported colorspace](#supported-colorspace)
    - [Conversion](#conversion)
    - [Named Colors](#named-colors)
    - [Gradients](#gradients)
      - [Gradient](#gradient)
      - [StopColor](#stopcolor)
      - [Gradient::StepMethod](#gradientstepmethod)
    - [Colormap](#colormap)

## How to use

To use `color`, add the followings to your `WORKSPACE` file.

```python
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_chokobole_color",
    sha256 = "<sha256>",
    strip_prefix = "color-<commit>",
    urls = [
        "https://github.com/chokobole/color/archive/<commit>.tar.gz",
    ],
)

load("@com_chokobole_base//bazel:base_deps.bzl", "base_deps")

base_deps()

load("@com_chokobole_bazel_utils//:buildifier_deps.bzl", "buildifier_deps")

buildifier_deps()

load("@com_chokobole_bazel_utils//:buildifier_deps_deps.bzl", "buildifier_deps_deps")

buildifier_deps_deps()
```

Then, in your `BUILD` files, import and use the rules.

```python
load("@com_chokobole_color//bazel:color_cc.bzl", "color_copts")

cc_binary(
    name = "name",
    srcs = [...],
    copts = color_copts(),
    deps = ["@com_chokobole_color//:color"],
)
```

## Usages

### Supported colorspace

* `Rgb`
* `Hsv`

### Conversion

* `Hsv RgbToHsv(const Rgb& rgb)`
* `Rgb HsvToRgb(const Hsv& hsv)`

### Named Colors

There are already defined named colors listed in [color_values](https://developer.mozilla.org/ko/docs/Web/CSS/color_value). You can use like below.

```c++
color::Rgb rgb = kBlack;
```

### Gradients

#### Gradient

* `bool Colors(size_t numbers, std::vector<Rgb>* colors, StepMethod = STEP_METHOD_RGB) const`

#### StopColor

Members

* `Rgb color`
* `double tposition`: Should be inside between 0 and 1.

#### Gradient::StepMethod

* `STEP_METHOD_RGB`: Interpolate between stop colors by RGB step method.
* `STEP_METHOD_HSV_CW`: Interpolate between stop colors by HSV clock wise step method.
* `STEP_METHOD_HSV_CCW`: Interpolate between stop colors by HSV counter clock wise step method.


For examples,

```c++
color::Gradient gradient({kBlack, kRed});
std::vector<color::Rgb> colors;
gradient.Color(5, &colors);
```

### Colormap

For examples,

```c++
color::Colormap colormap;
std::vector<color::Rgb> colors;
colormap.Jet(24, &colors);
```

Methods

* `bool Jet(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Hsv(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Hot(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Cool(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Spring(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Summer(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Autumn(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Winter(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Bone(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Copper(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Greys(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Greens(size_t numbers, std::vector<Rgb>* colors) const`
* `bool BlueRed(size_t numbers, std::vector<Rgb>* colors) const`
* `bool YIGnBu(size_t numbers, std::vector<Rgb>* colors) const`
* `bool YIOrRd(size_t numbers, std::vector<Rgb>* colors) const`
* `bool RdBu(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Picnic(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Rainbow(size_t numbers, std::vector<Rgb>* colors) const`
* `bool RainbowSoft(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Portland(size_t numbers, std::vector<Rgb>* colors) const`
* `bool BlackBody(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Earth(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Electric(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Alpha(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Viridis(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Inferno(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Magma(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Plasma(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Warm(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Bathymetry(size_t numbers, std::vector<Rgb>* colors) const`
* `bool CDOM(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Chlorophyll(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Density(size_t numbers, std::vector<Rgb>* colors) const`
* `bool FreeSurface_Blue(size_t numbers, std::vector<Rgb>* colors) const`
* `bool FreeSurface_Red(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Oxygen(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Par(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Phase(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Salinity(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Temperature(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Turbidity(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Velocity_Blue(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Velocity_Green(size_t numbers, std::vector<Rgb>* colors) const`
* `bool Cubehelix(size_t numbers, std::vector<Rgb>* colors) const`
