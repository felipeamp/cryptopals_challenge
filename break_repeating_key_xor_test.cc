// Copyright 2017 <felipeamp>

#include <fstream>
#include <string>
#include <vector>

#include "break_repeating_key_xor.h"
#include "gtest/gtest.h"
#include "utils.h"


#include <iostream>


namespace {

  TEST(BreakRepeatingKeyXor, BreaksCorrectly) {
    std::ifstream fin;
    fin.open("/home/felipelocal/Projetos/cryptopals_challenge/6.txt");
    std::string encoded_message_base64, curr_line;
    while (std::getline(fin, curr_line)) {
      encoded_message_base64 += curr_line;
    }
    std::vector<unsigned char> encoded_bytes = utils::Base64ToBytes(
      encoded_message_base64);

    std::vector<std::string> decoded_messages;
    std::vector<std::string> keys;
    size_t num_keysize_tries = 3;
    breakrepeatingkeyxor::BreakRepeatingKeyXor(encoded_bytes,
                                               &decoded_messages,
                                               &keys,
                                               num_keysize_tries);
    for (size_t keysize_index = 0;
         keysize_index < num_keysize_tries;
         ++keysize_index) {
      std::cout << "keys[" << keysize_index << "]: "
                << keys[keysize_index]
                << std::endl;
      std::cout << "decoded_messages[" << keysize_index << "]: "
                << std::endl
                << decoded_messages[keysize_index]
                << std::endl
                << std::endl;
    }
  }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}