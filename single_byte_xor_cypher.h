// Copyright 2017 <felipeamp>

#ifndef SINGLE_BYTE_XOR_CYPHER_H_
#define SINGLE_BYTE_XOR_CYPHER_H_

#include <string>
#include <vector>

namespace singlebytexorcypher {

  void SingleByteXorCypher(const std::vector<unsigned char> &bytes,
                           unsigned char *letter,
                           std::string *decoded_message,
                           double *score);

  void SingleByteXorCypher(const std::string &hex_message,
                           unsigned char *letter,
                           std::string *decoded_message,
                           double *score);

  double GetMessageScore(const std::vector<unsigned char> &message);

  std::vector<unsigned char> UnmaskVector(
      const std::vector<unsigned char> &bytes,
      unsigned char mask);

}  // namespace singlebytexorcypher

#endif  // SINGLE_BYTE_XOR_CYPHER_H_
