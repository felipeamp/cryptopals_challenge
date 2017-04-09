// Copyright 2017 <felipeamp>

#include <cassert>
#include <string>
#include <utility>
#include <vector>

#include "repeating_key_xor.h"
#include "utils.h"

namespace repeatingkeyxor {

std::string RepeatingKeyXor(const std::string &message,
                            const std::string &key) {
  assert(!key.empty());
  std::vector<unsigned char> key_as_bytes(key.begin(), key.end());

  std::vector<unsigned char> encoded_message;
  encoded_message.reserve(message.size());

  for (size_t index = 0; index < message.size(); ++index) {
    encoded_message.push_back(static_cast<unsigned char>(message[index])
                              ^ key_as_bytes[index % key.size()]);
  }
  return utils::BytesToHex(encoded_message);
}

}  // namespace repeatingkeyxor
