// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "repeating_key_xor.h"

TEST(RepeatingKeyXor, EncodeCorrectly) {
  std::string message("Burning 'em, if you ain't quick and nimble\n"
                      "I go crazy when I hear a cymbal");
  std::string key("ICE");
  ASSERT_STREQ(std::string("0b3637272a2b2e63622c2e69692a23693a2a3"
                           "c6324202d623d63343c2a2622632427276527"
                           "2a282b2f20430a652e2c652a3124333a653e2"
                           "b2027630c692b20283165286326302e27282f").c_str(),
               repeatingkeyxor::RepeatingKeyXor(message, key).c_str());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
