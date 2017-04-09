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

namespace utils {

std::string BytesToHex(const std::vector<unsigned char>& bytes) {
  std::ostringstream oss;
  oss << std::setfill('0');
  std::for_each(bytes.begin(), bytes.end(),
    [&oss](unsigned char ch) {
      oss << std::hex
          << std::setw(2)
          << static_cast<int>(ch);
    });
  return move(oss.str());
}

std::vector<unsigned char> HexToBytes(const std::string& s) {
  assert((s.size() & 1) == 0);
  std::vector<unsigned char> bytes;
  for (size_t index = 0; index < s.size(); index += 2) {
    std::string byte_str = s.substr(index, 2);
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
