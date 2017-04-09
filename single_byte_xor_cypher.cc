// Copyright 2017 <felipeamp>

#include <array>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <limits>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#include "single_byte_xor_cypher.h"
#include "utils.h"


namespace singlebytexorcypher {

  constexpr size_t kAlphabetSize = 26;
  constexpr size_t kAlphabetSizePlusSpace = kAlphabetSize + 1;
  constexpr size_t kPossibleMasksSize = (2 * kAlphabetSize) + 1;

  constexpr std::array<double, kAlphabetSizePlusSpace> kDictionaryFrequency = {
    // last entry corresponds to space character
    0.06553, 0.01271, 0.02651, 0.03352, 0.10218, 0.01972, 0.01636,  // <- g
    0.04862, 0.05734, 0.00114, 0.00569, 0.03356, 0.02017, 0.05703,  // <- n
    0.06201, 0.01503, 0.00088, 0.04972, 0.05326, 0.07510, 0.02295,  // <- u
    0.00788, 0.01690, 0.00150, 0.01470, 0.00060, 0.18317 };
  constexpr double kDictionaryFrequencyNorm = 0.27841577218254;

  double GetMessageScore(const std::vector<unsigned char> &message) {
    assert(!message.empty());

    if (!utils::is_printable_or_space(message)) {
        return 0.0;
    }

    std::array<uint64_t, kAlphabetSizePlusSpace> char_count;
    char_count.fill(0);
    uint64_t total_count = 0;
    for (unsigned char letter : message) {
      if (std::isalpha(letter)) {
        size_t char_index = std::toupper(letter) - 'A';
        ++char_count[char_index];
        ++total_count;
      } else if (letter == ' ') {
        ++char_count[kAlphabetSize];
        ++total_count;
      }
    }

    if (total_count == 0) {
      return 0.0;
    }
    double score = std::inner_product(char_count.begin(),
                                      char_count.end(),
                                      kDictionaryFrequency.begin(),
                                      0.0);
    double vector_norm = std::sqrt(std::inner_product(char_count.begin(),
                                                      char_count.end(),
                                                      char_count.begin(),
                                                      0.0));
    score /= (vector_norm * kDictionaryFrequencyNorm);
    return score;
  }

  std::vector<unsigned char> UnmaskVector(
      const std::vector<unsigned char> &bytes,
      unsigned char mask) {
    std::vector<unsigned char> unmasked;
    unmasked.reserve(bytes.size());
    for (unsigned char byte : bytes) {
      unmasked.push_back(byte ^ mask);
    }
    return move(unmasked);
  }

  void SingleByteXorCypher(const std::string &message,
                           unsigned char *letter,
                           std::string *decoded_message,
                           double *score) {
    assert(!message.empty());

    std::vector<unsigned char> bytes = utils::HexToBytes(message);

    double best_score = std::numeric_limits<double>::min();
    unsigned char best_mask;
    unsigned char mask = 0;
    do {
      std::vector<unsigned char> decoded_bytes = UnmaskVector(bytes, mask);

      double curr_score = GetMessageScore(decoded_bytes);
      if (curr_score > best_score) {
        best_score = curr_score;
        best_mask = mask;
      }

      ++mask;
    } while (mask != 0);

    *score = best_score;
    if (best_score == std::numeric_limits<double>::min()) {
      return;
    }

    *letter = best_mask;
    std::vector<unsigned char> decoded_bytes = UnmaskVector(bytes, best_mask);
    *decoded_message = std::string(decoded_bytes.begin(), decoded_bytes.end());
  }

}  // namespace singlebytexorcypher
