// Copyright 2017 <felipeamp>

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "detect_single_character_xor.h"
#include "gtest/gtest.h"


namespace {

constexpr char kPathToFile4[] =
  "/home/fpereira/Github/cryptopals_challenge/4.txt";

constexpr char kFileOpenError[] = "Couldn't open file \"4.txt\".";

constexpr char kCorrectMask = '5';

constexpr char kCorrectlyDecodedMessage[] = "Now that the party is jumping\n";

TEST(DetectSingleCharacterXor, CorrectMessage) {
  std::ifstream fin;
  fin.open(kPathToFile4);
  if (!fin.is_open()) {
    std::cout << kFileOpenError << std::endl;
  }

  unsigned char letter;
  std::string decoded_message;
  double score;
  detectsinglecharacterxor::DetectSingleCharacterXor(fin,
                                                     &letter,
                                                     &decoded_message,
                                                     &score);
  ASSERT_STREQ(kCorrectlyDecodedMessage, decoded_message.c_str());
}

TEST(DetectSingleCharacterXor, CorrectLetter) {
  std::ifstream fin;
  fin.open(kPathToFile4);
  if (!fin.is_open()) {
    std::cout << kFileOpenError << std::endl;
  }

  unsigned char letter;
  std::string decoded_message;
  double score;
  detectsinglecharacterxor::DetectSingleCharacterXor(fin,
                                                     &letter,
                                                     &decoded_message,
                                                     &score);
  ASSERT_EQ(kCorrectMask, letter);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
