// Copyright 2017 <felipeamp>

#include "utils.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>
#include <vector>


#include <iostream>

namespace utils {

constexpr size_t kBase64BlockSizeBytes = 3;
constexpr size_t kBase64BlockSizeString = 4;
constexpr size_t kHexBlockSize = 2;

constexpr unsigned char kAlphabetSize = 26;
constexpr unsigned char kNumDigits = 10;

constexpr char kByteToBase64[] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char Base64ToUnsignedChar(char base64_char) {
  if (std::isupper(base64_char)) {
    return base64_char - 'A';
  } else if (std::islower(base64_char)) {
    return (base64_char - 'a' + kAlphabetSize);
  } else if (std::isdigit(base64_char)) {
    return (base64_char - '0' + 2 * kAlphabetSize);
  } else if (base64_char == '+') {
    return 2 * kAlphabetSize + kNumDigits;
  } else if (base64_char == '/') {
    return 2 * kAlphabetSize + kNumDigits + 1;
  } else {
    throw std::invalid_argument("Character is not a base64 char.");
  }
}

std::vector<unsigned char> Base64ToThreeBytes(const std::string& base64,
                                              const size_t start_index) {
  assert(start_index + kBase64BlockSizeString <= base64.size());

  unsigned char first_letter = Base64ToUnsignedChar(base64[start_index]);
  unsigned char second_letter = Base64ToUnsignedChar(base64[start_index + 1]);
  unsigned char third_letter = Base64ToUnsignedChar(base64[start_index + 2]);
  unsigned char fourth_letter = Base64ToUnsignedChar(base64[start_index + 3]);

  std::vector<unsigned char> bytes;
  bytes.push_back((first_letter << 2)
                  + ((second_letter & 0x30) >> 4));
  bytes.push_back(((second_letter & 0x0F) << 4)
                  + ((third_letter & 0x3C) >> 2));
  bytes.push_back(((third_letter & 0x03) << 6)
                  + fourth_letter);

  return move(bytes);
}

std::string ThreeBytesToBase64(const std::vector<unsigned char>& bytes,
                               const size_t start_index) {
  assert(start_index + kBase64BlockSizeBytes <= bytes.size());
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

std::vector<unsigned char> Base64ToBytes(const std::string& base64) {
  // Check for padding
  size_t padding;
  if (base64[base64.size() - 2] == '=') {
    padding = 2;
  } else if (base64[base64.size() - 1] == '=') {
    padding = 1;
  } else {
    padding = 0;
  }

  // Convert base64 to bytes
  std::vector<unsigned char> bytes;
  bytes.reserve(kBase64BlockSizeBytes * base64.size() / kBase64BlockSizeString);
  for (size_t index = 0;
       index + kBase64BlockSizeString + padding <= base64.size();
       index += kBase64BlockSizeString) {
    std::vector<unsigned char> curr_bytes = Base64ToThreeBytes(base64,
                                                               index);
    bytes.insert(bytes.end(), curr_bytes.begin(), curr_bytes.end());
  }

  // Deal with padding
  if (padding == 2) {
    std::string end_chars = { base64[base64.size() - 4],
                              base64[base64.size() - 3],
                              'A',
                              'A' };

    std::vector<unsigned char> curr_bytes = Base64ToThreeBytes(end_chars, 0);
    bytes.push_back(curr_bytes[0]);
  } else if (padding == 1) {
    std::string end_chars = { base64[base64.size() - 4],
                              base64[base64.size() - 3],
                              base64[base64.size() - 2],
                              'A' };

    std::vector<unsigned char> curr_bytes = Base64ToThreeBytes(end_chars, 0);
    bytes.insert(bytes.end(), curr_bytes.begin(), curr_bytes.end() - 1);
  }

  return bytes;
}

std::string BytesToBase64(const std::vector<unsigned char>& bytes) {
  // Check for padding
  int padding = 0;
  std::vector<unsigned char> end_bytes;
  if (bytes.size() % kBase64BlockSizeBytes == 1) {
    end_bytes.push_back(bytes[bytes.size() - 1]);
    end_bytes.push_back(0);
    end_bytes.push_back(0);
    padding = 2;
  } else if (bytes.size() % kBase64BlockSizeBytes == 2) {
    end_bytes.push_back(bytes[bytes.size() - 2]);
    end_bytes.push_back(bytes[bytes.size() - 1]);
    end_bytes.push_back(0);
    padding = 1;
  }

  // Translate to base64
  std::string base64;
  for (size_t index = 0;
       index + kBase64BlockSizeBytes <= bytes.size();
       index += kBase64BlockSizeBytes) {
      base64 += ThreeBytesToBase64(bytes, index);
  }

  // Change extra chars due to padding
  if (padding == 1) {
    base64 += ThreeBytesToBase64(end_bytes, 0);
    base64[base64.size() - 1] = '=';
  } else if (padding == 2) {
    base64 += ThreeBytesToBase64(end_bytes, 0);
    base64[base64.size() - 2] = '=';
    base64[base64.size() - 1] = '=';
  }
  return move(base64);
}

std::string BytesToHex(const std::vector<unsigned char>& bytes) {
  std::ostringstream oss;
  oss << std::setfill('0');
  std::for_each(bytes.begin(), bytes.end(),
    [&oss](unsigned char ch) {
      oss << std::hex
          << std::setw(kHexBlockSize)
          << static_cast<int>(ch);
    });
  return move(oss.str());
}

std::vector<unsigned char> HexToBytes(const std::string& s) {
  assert((s.size() & 1) == 0);
  std::vector<unsigned char> bytes;
  for (size_t index = 0;index < s.size(); index += kHexBlockSize) {
    std::string byte_str = s.substr(index, kHexBlockSize);
    unsigned char byte = static_cast<unsigned char>(
      strtoul(byte_str.c_str(), nullptr, 16));
    bytes.push_back(byte);
  }
  return move(bytes);
}

bool is_printable_or_space(const std::string& s) {
  for (char c : s) {
    if (!std::isprint(c) && !std::isspace(c)) {
      return false;
    }
  }
  return true;
}

bool is_printable_or_space(const std::vector<unsigned char>& v) {
    for (unsigned char c : v) {
    if (!std::isprint(c) && !std::isspace(c)) {
      return false;
    }
  }
  return true;
}

}  // namespace utils
