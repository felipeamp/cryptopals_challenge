// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "hex_to_base64.h"
#include "utils.h"

#include <iostream>

namespace {

TEST(HexToBase64Test, ConvertsCorrectly) {
  ASSERT_STREQ(std::string("SSdtIGtpbGxpbmcg"
                           "eW91ciBicmFpbiBs"
                           "aWtlIGEgcG9pc29u"
                           "b3VzIG11c2hyb29t").c_str(),
               hextobase64::HexToBase64("49276d206b696c6c"
                                        "696e6720796f7572"
                                        "20627261696e206c"
                                        "696b65206120706f"
                                        "69736f6e6f757320"
                                        "6d757368726f6f6d").c_str());
}

TEST(HexToBase64Test, ConvertsCorrectlyBothWays) {
  std::string s("49276d206b696c6c"
                "696e6720796f7572"
                "20627261696e206c"
                "696b65206120706f"
                "69736f6e6f757320"
                "6d757368726f6f6d");
  std::string gone_and_back = utils::BytesToHex(
    utils::Base64ToBytes(hextobase64::HexToBase64(s)));
  ASSERT_STREQ(s.c_str(),
               gone_and_back.c_str());
}

TEST(Base64ToHex, ConvertsCorrectlySinglePadding) {
  std::string s("any carnal pleasure.");
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(std::string("YW55IGNhcm5hbCBwbGVhc3VyZS4=").c_str(),
               utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyDoublePadding) {
  std::string s("any carnal pleasure");
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(std::string("YW55IGNhcm5hbCBwbGVhc3VyZQ==").c_str(),
               utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyNoPadding) {
  std::string s("any carnal pleasur");
  std::vector<unsigned char> v(s.begin(), s.end());
  ASSERT_STREQ(std::string("YW55IGNhcm5hbCBwbGVhc3Vy").c_str(),
               utils::BytesToBase64(v).c_str());
}

TEST(Base64ToHex, ConvertsCorrectlyBothWaysSinglePadding) {
  std::string s("any carnal pleasure.");
  std::vector<unsigned char> v(s.begin(), s.end());
  std::vector<unsigned char> gone_and_back = utils::Base64ToBytes(
    utils::BytesToBase64(v));
  ASSERT_STREQ(s.c_str(),
               std::string(gone_and_back.begin(), gone_and_back.end()).c_str());
}

// TEST(Base64ToHex, ConvertsCorrectlyBothWaysDoublePadding) {
//   std::string s("any carnal pleasure");
//   std::vector<unsigned char> v(s.begin(), s.end());
//   ASSERT_STREQ(std::string("YW55IGNhcm5hbCBwbGVhc3VyZQ==").c_str(),
//                utils::BytesToBase64(v).c_str());
// }

// TEST(Base64ToHex, ConvertsCorrectlyBothWaysNoPadding) {
//   std::string s("any carnal pleasur");
//   std::vector<unsigned char> v(s.begin(), s.end());
//   ASSERT_STREQ(std::string("YW55IGNhcm5hbCBwbGVhc3Vy").c_str(),
//                utils::BytesToBase64(v).c_str());
// }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
