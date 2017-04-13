// Copyright 2017 <felipeamp>

#include <string>

#include "fixed_xor.h"
#include "gtest/gtest.h"

namespace {

constexpr char kString1Before[] = "1c0111001f010100061a024b53535009181c";

constexpr char kString2Before[] = "686974207468652062756c6c277320657965";

constexpr char kStringAfter[] = "746865206b696420646f6e277420706c6179";

TEST(FixedXorTest, XorsCorrectly) {
  ASSERT_STREQ(kStringAfter,
               fixedxor::FixedXor(std::string(kString1Before),
                                  std::string(kString2Before)).c_str());
}

}  // namespace


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
