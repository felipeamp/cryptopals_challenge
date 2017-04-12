cc_library(
    name = "break-repeating-key-xor",
    srcs = ["break_repeating_key_xor.cc"],
    hdrs = ["break_repeating_key_xor.h"],
    deps = [":find-keysize",
            ":single-byte-xor-cypher",
            ":utils"],
)

cc_library(
    name = "detect-single-character-xor",
    srcs = ["detect_single_character_xor.cc"],
    hdrs = ["detect_single_character_xor.h"],
    deps = [":single-byte-xor-cypher"],
)

cc_library(
    name = "find-keysize",
    srcs = ["find_keysize.cc"],
    hdrs = ["find_keysize.h"],
    deps = [":utils"],
)

cc_library(
    name = "fixed-xor",
    srcs = ["fixed_xor.cc"],
    hdrs = ["fixed_xor.h"],
    deps = [":utils"],
)

cc_library(
    name = "hex-to-base64",
    srcs = ["hex_to_base64.cc"],
    hdrs = ["hex_to_base64.h"],
    deps = [":utils"],
)

cc_library(
    name = "repeating-key-xor",
    srcs = ["repeating_key_xor.cc"],
    hdrs = ["repeating_key_xor.h"],
    deps = [":utils"],
)

cc_library(
    name = "single-byte-xor-cypher",
    srcs = ["single_byte_xor_cypher.cc"],
    hdrs = ["single_byte_xor_cypher.h"],
    deps = [":utils"],
)

cc_library(
    name = "utils",
    srcs = ["utils.cc"],
    hdrs = ["utils.h"],
)

cc_test(
    name = "break-repeating-key-xor-test",
    srcs = ["break_repeating_key_xor_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":break-repeating-key-xor",],
)

cc_test(
    name = "detect-single-character-xor-test",
    srcs = ["detect_single_character_xor_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":detect-single-character-xor",],
)

cc_test(
    name = "find-keysize-test",
    srcs = ["find_keysize_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":find-keysize",],
)

cc_test(
    name = "fixed-xor-test",
    srcs = ["fixed_xor_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":fixed-xor",],
)

cc_test(
    name = "hex-to-base64-test",
    srcs = ["hex_to_base64_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":hex-to-base64",],
)

cc_test(
    name = "repeating-key-xor-test",
    srcs = ["repeating_key_xor_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":repeating-key-xor",],
)

cc_test(
    name = "single-byte-xor-cypher-test",
    srcs = ["single_byte_xor_cypher_test.cc"],
    copts = ["-Iexternal/gtest/googletest-release-1.8.0/googletest/include"],
    deps = ["@gtest//:main",
            ":single-byte-xor-cypher",],
)
