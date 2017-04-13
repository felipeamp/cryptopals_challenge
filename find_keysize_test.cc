// Copyright 2017 <felipeamp>

#include <string>
#include <vector>

#include "find_keysize.h"
#include "gtest/gtest.h"
#include "utils.h"


namespace {

constexpr char kMessage1[] = "this is a test";

constexpr char kMessage2[] = "wokka wokka!!!";

constexpr unsigned char kCorrectDistance = 37;

  TEST(HammingDist, CalculatesCorrectly) {
    std::string s1(kMessage1);
    std::string s2(kMessage2);
    ASSERT_EQ(kCorrectDistance, utils::HammingDist(s1, s2));
  }

}  // namespace


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
