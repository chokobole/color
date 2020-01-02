load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def color_deps():
    if not native.existing_rule("com_google_googletest"):
        http_archive(
            name = "com_google_googletest",
            sha256 = "353ab86e35cea1cd386115279cf4b16695bbf21b897bfbf2721cf4cb5f64ade8",
            strip_prefix = "googletest-997d343dd680e541ef96ce71ee54a91daf2577a0",
            urls = [
                "https://mirror.bazel.build/github.com/google/googletest/archive/997d343dd680e541ef96ce71ee54a91daf2577a0.zip",
                "https://github.com/google/googletest/archive/997d343dd680e541ef96ce71ee54a91daf2577a0.zip",
            ],
        )

    if not native.existing_rule("com_chokobole_base"):
        http_archive(
            name = "com_chokobole_base",
            sha256 = "3e52b291abb4dc97ba419cf09189fa4d327341b8b31b24ba8b8b49ac599a0add",
            strip_prefix = "base-94b0f4b284e65d185c6b3a31b8eef132f6c9fa0e",
            urls = [
                "https://github.com/chokobole/base/archive/94b0f4b284e65d185c6b3a31b8eef132f6c9fa0e.zip",
            ],
        )
