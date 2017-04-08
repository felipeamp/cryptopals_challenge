// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "hex_to_base64.h"

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

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
