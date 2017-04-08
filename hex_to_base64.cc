// Copyright 2017 <felipeamp>

#include "hex_to_base64.h"

#include <cassert>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

#include "utils.h"


namespace hextobase64 {

constexpr char kByteToBase64[] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string ThreeBytesToBase64(const std::vector<unsigned char>& bytes,
                               const size_t start_index) {
  assert(start_index + 2 < bytes.size());
  std::string base64;

  unsigned char first_char = bytes[start_index] >> 2;
  unsigned char second_char = ((bytes[start_index] << 4) & 0x30)
                              | (bytes[start_index + 1] >> 4);
  unsigned char third_char = ((bytes[start_index + 1] << 2) & 0x3C)
                             | (bytes[start_index + 2] >> 6);
  unsigned char fourth_char = bytes[start_index + 2] & 0x3F;

  base64 += kByteToBase64[first_char];
  base64 += kByteToBase64[second_char];
  base64 += kByteToBase64[third_char];
  base64 += kByteToBase64[fourth_char];

  return move(base64);
}

std::string HexToBase64(const std::string& s) {
  std::vector<unsigned char> bytes = utils::HexToBytes(s);

  // Padding with zeros
  int chars_to_remove = 0;
  if (bytes.size() % 3 == 1) {
    bytes.push_back(0);
    bytes.push_back(0);
    chars_to_remove = 2;
  } else if (bytes.size() % 3 == 2) {
    bytes.push_back(0);
    chars_to_remove = 1;
  }

  // Translate to base64
  std::string base64;
  for (size_t index = 0; index + 2 < bytes.size(); index += 3) {
      base64 += ThreeBytesToBase64(bytes, index);
  }

  // Remove extra chars due to padding
  if (chars_to_remove > 0) {
    base64 = base64.substr(0, base64.size() - chars_to_remove);
  }

  return move(base64);
}

}  // namespace hextobase64
