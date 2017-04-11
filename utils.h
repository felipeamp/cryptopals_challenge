// Copyright 2017 <felipeamp>

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>

namespace utils {

std::vector<unsigned char> Base64ToBytes(const std::string& s);

std::string BytesToBase64(const std::vector<unsigned char>& bytes);

std::string BytesToHex(const std::vector<unsigned char>& bytes);

std::vector<unsigned char> HexToBytes(const std::string& s);

bool is_printable_or_space(const std::string& s);

bool is_printable_or_space(const std::vector<unsigned char>& v);

}  // namespace utils

#endif  // UTILS_H_
