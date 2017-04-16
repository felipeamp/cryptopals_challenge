// Copyright 2017 <felipeamp>

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "decrypt_aes_ecb_mode.h"
#include "utils.h"

namespace {
constexpr char kPathToFile7[] =
  "/home/fpereira/Github/cryptopals_challenge/7.txt";

constexpr char kFileOpenError[] = "Couldn't open file \"7.txt\".";

constexpr char kKey[] = "YELLOW SUBMARINE";

constexpr char kMessage[] = "";

bool has_repeated_blocks(const std::string &message, size_t block_size=16) {
  assert(message.size() % block_size == 0);

  size_t num_blocks = message.size() / block_size;
  std::vector<std::string> blocks;
  blocks.reserve(num_blocks);

  for(size_t block_index = 0; block_index < num_blocks; ++block_index) {
    blocks.push_back(
      std::string(message.begin() + block_index * block_size,
                  message.begin() + (block_index + 1) * block_size));
  }

  std::sort(blocks.begin(), blocks.end());
  return (std::adjacent_find(blocks.begin(), blocks.end())
          != blocks.end());
}

TEST(DecryptAesEcbMode, DecryptFileCorrectly) {
  std::ifstream fin;
  fin.open(kPathToFile7);
  if (!fin.is_open()) {
    std::cout << kFileOpenError << std::endl;
  }

  std::string curr_line;
  std::string best_line;
  while(std::getline(fin, curr_line)) {
    std::vector<unsigned char> bytes = utils::Base64ToBytes(curr_line);
    std::string decoded_line = decryptaesecbmode::DecryptAesEcbMode(
      std::string(bytes.begin(), bytes.end()),
      std::string(kKey));

    if(utils::is_printable_or_space(decoded_line)
       && has_repeated_blocks(decoded_line)) {
      best_line = decoded_line;
      std::cout << "Best line found!" << std::endl;
      std::cout << "best_line: " << best_line << std::endl << std::endl;
    }
  }
  // ASSERT_STREQ(kMessage.c_str(), best_line.c_str());
}

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
