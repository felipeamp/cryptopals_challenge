// Copyright 2017 <felipeamp>

#ifndef _CRYPTOPALS_DETECT_SINGLE_CHARACTER_XOR_H_
#define _CRYPTOPALS_DETECT_SINGLE_CHARACTER_XOR_H_

#include <string>
#include <istream>

namespace detectsinglecharacterxor {

void DetectSingleCharacterXor(std::istream &iss,
                              unsigned char *letter,
                              std::string *decoded_message,
                              double *score);

}  // namespace detectsinglecharacterxor

#endif  // _CRYPTOPALS_DETECT_SINGLE_CHARACTER_XOR_H_
