// Copyright 2017 <felipeamp>

#ifndef BREAK_REPEATING_KEY_XOR_H_
#define BREAK_REPEATING_KEY_XOR_H_

#include <string>

namespace breakrepeatingkeyxor {

void BreakRepeatingKeyXor(const std::vector<unsigned char>& encoded_bytes,
                          std::string *decoded_message,
                          std::string *key);

void BreakRepeatingKeyXor(const std::vector<unsigned char>& encoded_bytes,
                          std::vector<std::string> *decoded_messages,
                          std::vector<std::string> *keys,
                          size_t num_keysizes_tries = 1);

}  // namespace breakrepeatingkeyxor

#endif  // BREAK_REPEATING_KEY_XOR_H_
