// Copyright 2017 <felipeamp>

#ifndef DETECT_SINGLE_CHARACTER_XOR_H_
#define DETECT_SINGLE_CHARACTER_XOR_H_

#include <string>
#include <istream>

namespace detectsinglecharacterxor {

void DetectSingleCharacterXor(std::istream &iss,
                              unsigned char *letter,
                              std::string *decoded_message,
                              double *score);

}  // namespace detectsinglecharacterxor

#endif  // DETECT_SINGLE_CHARACTER_XOR_H_
