// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "repeating_key_xor.h"

namespace {

constexpr char kMessage[] =
  "Burning 'em, if you ain't quick and nimble\n"
  "I go crazy when I hear a cymbal";

constexpr char kKey[] = "ICE";

constexpr char kXoredMessage[] =
  "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a2622632427276527"
  "2a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";

TEST(RepeatingKeyXor, EncodeCorrectly) {
  ASSERT_STREQ(kXoredMessage,
               repeatingkeyxor::RepeatingKeyXor(std::string(kMessage),
                                                std::string(kKey)).c_str());
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
