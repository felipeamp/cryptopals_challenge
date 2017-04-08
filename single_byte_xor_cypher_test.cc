// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "single_byte_xor_cypher.h"

namespace {

TEST(SingleByteXorCypher, GetCorrectMessage) {
  std::string message("1b37373331363f78151b7f2b783431333d"
                      "78397828372d363c78373e783a393b3736");
  unsigned char letter;
  std::string decoded_message;
  double score;
  singlebytexorcypher::SingleByteXorCypher(message,
                                           &letter,
                                           &decoded_message,
                                           &score);
  ASSERT_STREQ(std::string("Cooking MC's like a pound of bacon").c_str(),
               decoded_message.c_str());
}

TEST(SingleByteXorCypher, GetCorrectLetter) {
  std::string message("1b37373331363f78151b7f2b783431333d"
                      "78397828372d363c78373e783a393b3736");
  unsigned char letter;
  std::string decoded_message;
  double score;
  singlebytexorcypher::SingleByteXorCypher(message,
                                           &letter,
                                           &decoded_message,
                                           &score);
  ASSERT_EQ(letter, 'X');
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
