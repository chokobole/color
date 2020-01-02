load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("//bazel:color_cc.bzl", "color_cc_library", "color_cc_test")

exports_files(["LICENSE"])

color_cc_library(
    name = "color",
    srcs = [
        "color/color.cc",
        "color/color_conversion.cc",
        "color/colormap.cc",
        "color/gradient.cc",
    ],
    hdrs = [
        "color/color.h",
        "color/color_conversion.h",
        "color/colormap.h",
        "color/export.h",
        "color/gradient.h",
        "color/named_color.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_chokobole_base//base/strings",
    ],
)

color_cc_test(
    name = "color_unittests",
    srcs = [
        "color/color_conversion_unittest.cc",
        "color/color_unittest.cc",
        "color/gradient_unittest.cc",
    ],
    deps = [
        ":color",
        "@com_google_googletest//:gtest_main",
    ],
)

buildifier(
    name = "buildifier",
)
