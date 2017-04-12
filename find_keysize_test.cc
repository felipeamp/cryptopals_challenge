// Copyright 2017 <felipeamp>

#include <string>
#include <vector>

#include "find_keysize.h"
#include "gtest/gtest.h"
#include "utils.h"


namespace {

  TEST(HammingDist, CalculatesCorrectly) {
    std::string s1("this is a test");
    std::string s2("wokka wokka!!!");
    ASSERT_EQ(utils::HammingDist(s1, s2),
              static_cast<unsigned char>(37));
  }

}  // namespace


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}