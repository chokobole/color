load("@com_chokobole_bazel_utils//:cxxopts.bzl", "cxx14")
load("@com_chokobole_bazel_utils//:dsym.bzl", "dsym")
load("@com_chokobole_bazel_utils//:copts.bzl", "safest_code_copts")
load("@com_chokobole_bazel_utils//:linkopts.bzl", "safest_code_linkopts")

def color_copts():
    return cxx14()

def _color_copts():
    return color_copts() + safest_code_copts()

def _linkopts():
    return safest_code_linkopts()

def color_cc_library(
        name,
        copts = _color_copts(),
        linkopts = _linkopts(),
        **kwargs):
    native.cc_library(
        name = name,
        copts = copts,
        **kwargs
    )

def color_cc_binary(
        name,
        copts = _color_copts(),
        linkopts = _linkopts(),
        **kwargs):
    native.cc_binary(
        name = name,
        copts = copts,
        **kwargs
    )

    dsym(name = name)

def color_cc_test(
        name,
        copts = _color_copts(),
        linkopts = _linkopts(),
        **kwargs):
    native.cc_test(
        name = name,
        copts = copts,
        **kwargs
    )

    dsym(
        name = name,
        testonly = 1,
    )
