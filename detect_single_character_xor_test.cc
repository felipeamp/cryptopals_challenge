// Copyright 2017 <felipeamp>

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "detect_single_character_xor.h"
#include "gtest/gtest.h"


namespace {

TEST(DetectSingleCharacterXor, CorrectMessage) {
  std::ifstream fin;
  fin.open("4.txt");
  if (!fin.is_open()) {
    std::cout << "Couldn't open file \"4.txt\"." << std::endl;
  }
  unsigned char letter;
  std::string decoded_message;
  double score;
  detectsinglecharacterxor::DetectSingleCharacterXor(fin,
                                                     &letter,
                                                     &decoded_message,
                                                     &score);
  ASSERT_STREQ(std::string("Now that the party is jumping\n").c_str(),
               decoded_message.c_str());
}

TEST(DetectSingleCharacterXor, CorrectLetter) {
  std::ifstream fin;
  fin.open("4.txt");
  if (!fin.is_open()) {
    std::cout << "Couldn't open file \"4.txt\"." << std::endl;
  }
  unsigned char letter;
  std::string decoded_message;
  double score;
  detectsinglecharacterxor::DetectSingleCharacterXor(fin,
                                                     &letter,
                                                     &decoded_message,
                                                     &score);
  ASSERT_EQ(letter, '5');
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
