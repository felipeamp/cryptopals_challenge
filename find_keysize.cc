// Copyright 2017 <felipeamp>

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

#include "find_keysize.h"
#include "utils.h"


#include <iostream>


namespace findkeysize {

double KeysizeScore(const std::vector<unsigned char>& bytes, size_t keysize) {
  assert(keysize > 0);
  assert(keysize <= bytes.size() / 2);

  size_t total_hamming_dist = 0.0;
  for (size_t index = 0; index < keysize; ++index) {
    total_hamming_dist += utils::HammingDist(bytes[index],
                                             bytes[index + keysize]);
  }
  return (static_cast<double>(total_hamming_dist)
          / static_cast<double>(keysize));
}

std::vector<size_t> FindKeysize(const std::vector<unsigned char>& bytes,
                                size_t num_ret) {
  assert(num_ret > 0);

  size_t max_keysize = bytes.size() / 2;
  assert(num_ret <= max_keysize);

  std::vector<std::pair<double, size_t>> score_and_keysize;
  score_and_keysize.reserve(max_keysize + 1);
  for (size_t keysize = 1; keysize <= max_keysize; ++keysize) {
    double score = KeysizeScore(bytes, keysize);
    score_and_keysize.push_back(std::make_pair(score, keysize));
  }

  std::sort(score_and_keysize.begin(), score_and_keysize.end());

  std::vector<size_t> best_keysizes;
  best_keysizes.reserve(num_ret);
  for (size_t position = 0; position < num_ret; ++position) {
    best_keysizes.push_back(score_and_keysize[position].second);
  }
  return move(best_keysizes);
}

}  // namespace findkeysize
