// Copyright 2017 <felipeamp>

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

#include "find_keysize.h"
#include "utils.h"


namespace findkeysize {

double KeysizeScore(const std::string& s, size_t keysize) {
  assert(keysize > 0 && keysize <= s.size() / 2);

  size_t total_hamming_dist = 0.0;
  for (size_t index = 0; index < keysize; ++index) {
    total_hamming_dist += utils::HammingDist(
      static_cast<unsigned char>(s[index]),
      static_cast<unsigned char>(s[index + keysize]));
  }
  return (static_cast<double>(total_hamming_dist)
          / static_cast<double>(keysize));
}

std::vector<size_t> FindKeysize(const std::string& s, size_t num_ret) {
  assert(num_ret > 0);

  size_t max_keysize = s.size() / 2;
  assert(num_ret <= max_keysize);

  std::vector<std::pair<double, size_t>> keysize_and_score;
  keysize_and_score.reserve(max_keysize + 1);
  for (size_t keysize = 0; keysize <= max_keysize; ++keysize) {
    keysize_and_score.push_back(std::make_pair(KeysizeScore(s, keysize),
                                               keysize));
  }
  std::sort(keysize_and_score.rbegin(), keysize_and_score.rend());

  std::vector<size_t> best_keysizes;
  best_keysizes.reserve(num_ret);
  for (size_t position = 0; position < num_ret; ++position) {
    best_keysizes.push_back(keysize_and_score[position].second);
  }
  return move(best_keysizes);
}

}  // namespace findkeysize
