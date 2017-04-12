// Copyright 2017 <felipeamp>

#include <string>
#include <vector>

#include "find_keysize.h"
#include "gtest/gtest.h"
#include "utils.h"


namespace {

  TEST(HammingDist, CalculatesCorrectly) {
    std::string s1("this is a test");
    std::vector<unsigned char> bytes1(s1.begin(), s1.end());
    std::string s2("wokka wokka!!!");
    std::vector<unsigned char> bytes2(s2.begin(), s2.end());
    ASSERT_EQ(utils::HammingDist(bytes1, bytes2),
              static_cast<unsigned char>(37));
  }

}  // namespace


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}