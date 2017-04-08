// Copyright 2017 <felipeamp>

#include <cassert>
#include <string>
#include <utility>
#include <vector>

#include "fixed_xor.h"
#include "utils.h"

namespace fixedxor {

std::string FixedXor(const std::string& s1, const std::string& s2) {
  std::vector<unsigned char> bytes1 = utils::HexToBytes(s1);
  std::vector<unsigned char> bytes2 = utils::HexToBytes(s2);

  assert(bytes1.size() == bytes2.size());
  size_t num_bytes = bytes1.size();

  std::vector<unsigned char> xored_bytes;
  xored_bytes.reserve(num_bytes);
  for (size_t index = 0; index < num_bytes; ++index) {
      xored_bytes.push_back(bytes1[index] ^ bytes2[index]);
  }
  return move(utils::BytesToHex(xored_bytes));
}

}  // namespace fixedxor
