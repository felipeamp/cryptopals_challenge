// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "hex_to_base64.h"
#include "utils.h"

#include <iostream>

namespace {

constexpr char kBase64Message1[] =
    "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

constexpr char kHexMessage1[] =
  "49276d206b696c6c696e6720796f7572"
  "20627261696e206c696b65206120706f"
  "69736f6e6f7573206d757368726f6f6d";

constexpr char kBase64Message2[] = "YW55IGNhcm5hbCBwbGVhc3VyZS4=";

constexpr char kStringMessage2[] = "any carnal pleasure.";

constexpr char kBase64Message3[] = "YW55IGNhcm5hbCBwbGVhc3VyZQ==";

constexpr char kStringMessage3[] = "any carnal pleasure";

constexpr char kBase64Message4[] = "YW55IGNhcm5hbCBwbGVhc3Vy";

constexpr char kStringMessage4[] = "any carnal pleasur";

TEST(HexToBase64Test, ConvertsCorrectly) {
  ASSERT_STREQ(kBase64Message1,
               hextobase64::HexToBase64(std::string(kHexMessage1)).c_str());
}

TEST(HexToBase64Test, ConvertsCorrectlyBothWays) {
  std::string gone_and_back = utils::BytesToHex(
    utils::Base64ToBytes(hextobase64::HexToBase64(std::string(kHexMessage1))));
  ASSERT_STREQ(kHexMessage1, gone_and_back.c_str());
}

TEST(Base64ToHex, ConvertsCorrectlySinglePadding) {
  std::string s(kStringMessage2);
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(kBase64Message2, utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyDoublePadding) {
  std::string s(kStringMessage3);
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(kBase64Message3, utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyNoPadding) {
  std::string s(kStringMessage4);
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(kBase64Message4, utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyBothWaysSinglePadding) {
  std::string s(kStringMessage2);
  std::vector<unsigned char> v(s.begin(), s.end());
  std::vector<unsigned char> gone_and_back = utils::Base64ToBytes(
    utils::BytesToBase64(v));
  ASSERT_STREQ(kStringMessage2,
               std::string(gone_and_back.begin(), gone_and_back.end()).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyBothWaysDoublePadding) {
  std::string s(kStringMessage3);
  std::vector<unsigned char> v(s.begin(), s.end());
  std::vector<unsigned char> gone_and_back = utils::Base64ToBytes(
    utils::BytesToBase64(v));
  ASSERT_STREQ(kStringMessage3,
               std::string(gone_and_back.begin(), gone_and_back.end()).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyBothWaysNoPadding) {
  std::string s(kStringMessage4);
  std::vector<unsigned char> v(s.begin(), s.end());
  std::vector<unsigned char> gone_and_back = utils::Base64ToBytes(
    utils::BytesToBase64(v));
  ASSERT_STREQ(kStringMessage4,
               std::string(gone_and_back.begin(), gone_and_back.end()).c_str());
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
