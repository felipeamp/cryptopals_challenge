// Copyright 2017 <felipeamp>

#ifndef _CRYPTOPALS_BASE_H_
#define _CRYPTOPALS_BASE_H_

#include <string>
#include <vector>

namespace utils {

std::string BytesToHex(const std::vector<unsigned char>& bytes);

std::vector<unsigned char> HexToBytes(const std::string& s);

bool is_printable_or_space(const std::string& s);

bool is_printable_or_space(const std::vector<unsigned char>& v);

}  // namespace utils

#endif  // _CRYPTOPALS_BASE_H_
