// Copyright 2017 <felipeamp>

#include <cassert>
#include <string>
#include <utility>
#include <vector>

#include "break_repeating_key_xor.h"
#include "find_keysize.h"
#include "single_byte_xor_cypher.h"
#include "utils.h"


#include <iostream>


namespace breakrepeatingkeyxor {

std::vector<std::vector<unsigned char>> TransposeBlocks(
    const std::vector<unsigned char> &encoded_bytes,
    size_t keysize) {
  std::vector<std::vector<unsigned char>> transposed(keysize);
  for (size_t index = 0; index < encoded_bytes.size(); ++index) {
    transposed[index % keysize].push_back(encoded_bytes[index]);
  }
  return move(transposed);
}

std::string DetransposeBlocks(const std::vector<std::string> &decoded_blocks) {
  assert(decoded_blocks.size() > 0);
  std::string detransposed;
  detransposed.reserve(decoded_blocks.size() * decoded_blocks[0].size());

  for (size_t string_index = 0;
       string_index < decoded_blocks[0].size();
       ++string_index) {
    for (size_t block_index = 0;
         block_index < decoded_blocks.size();
         ++block_index) {
      if (string_index < decoded_blocks[block_index].size()) {
        detransposed += decoded_blocks[block_index][string_index];
      }
    }
  }
  return move(detransposed);
}

void BreakRepeatingKeyXor(
    const std::vector<unsigned char>& encoded_bytes,
    std::vector<std::string> *decoded_messages,
    std::vector<std::string> *keys,
    size_t num_keysizes_tries) {
  std::vector<size_t> best_keysizes = findkeysize::FindKeysize(encoded_bytes,
                                                          num_keysizes_tries);
  for (size_t keysize : best_keysizes) {
    std::vector<std::vector<unsigned char>> transposed = TransposeBlocks(
      encoded_bytes,
      keysize);
    std::string key;
    std::vector<std::string> decoded_blocks;
    for (std::vector<unsigned char> block : transposed) {
      std::string decoded_block;
      unsigned char letter;
      double score;
      singlebytexorcypher::SingleByteXorCypher(block,
                                               &letter,
                                               &decoded_block,
                                               &score);
      std::cout << "decoded_block: " << decoded_block <<  std::endl;
      key += static_cast<char>(letter);
      decoded_blocks.push_back(decoded_block);
    }
    decoded_messages->push_back(DetransposeBlocks(decoded_blocks));
    keys->push_back(key);
  }
}

void BreakRepeatingKeyXor(const std::vector<unsigned char>& encoded_bytes,
                          std::string *decoded_message,
                          std::string *key) {
  std::vector<std::string> decoded_messages(1, "");
  std::vector<std::string> keys(1, "");
  BreakRepeatingKeyXor(encoded_bytes, &decoded_messages, &keys);
  *decoded_message = decoded_messages[0];
  *key = keys[0];
}

}  // namespace breakrepeatingkeyxor
