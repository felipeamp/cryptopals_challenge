// Copyright 2017 <felipeamp>

#include "hex_to_base64.h"

#include <cassert>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

#include "utils.h"


namespace hextobase64 {

std::string HexToBase64(const std::string& s) {
  std::vector<unsigned char> bytes = utils::HexToBytes(s);
  std::string base64 = utils::BytesToBase64(bytes);
  return move(base64);
}

}  // namespace hextobase64
