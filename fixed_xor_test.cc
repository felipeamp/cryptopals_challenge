// Copyright 2017 <felipeamp>

#include <string>

#include "fixed_xor.h"
#include "gtest/gtest.h"

namespace {

TEST(FixedXorTest, XorsCorrectly) {
  ASSERT_STREQ(std::string("746865206b69642064"
                           "6f6e277420706c6179").c_str(),
               fixedxor::FixedXor("1c0111001f01010006"
                                  "1a024b53535009181c",
                                  "686974207468652062"
                                  "756c6c277320657965").c_str());
}

}  // namespace


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
