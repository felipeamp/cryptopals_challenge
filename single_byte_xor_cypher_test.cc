// Copyright 2017 <felipeamp>

#include <string>

#include "gtest/gtest.h"
#include "single_byte_xor_cypher.h"

namespace {

constexpr char kEncodedMessage[] =
  "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

constexpr char kDecodedMessage[] = "Cooking MC's like a pound of bacon";

constexpr char kKey = 'X';

TEST(SingleByteXorCypher, GetCorrectMessage) {
  std::string message(kEncodedMessage);
  unsigned char letter;
  std::string decoded_message;
  double score;
  singlebytexorcypher::SingleByteXorCypher(message,
                                           &letter,
                                           &decoded_message,
                                           &score);
  ASSERT_STREQ(kDecodedMessage, decoded_message.c_str());
}

TEST(SingleByteXorCypher, GetCorrectLetter) {
  std::string message(kEncodedMessage);
  unsigned char letter;
  std::string decoded_message;
  double score;
  singlebytexorcypher::SingleByteXorCypher(message,
                                           &letter,
                                           &decoded_message,
                                           &score);
  ASSERT_EQ(kKey, letter);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
