// Copyright 2017 <felipeamp>

#include <istream>
#include <limits>
#include <string>

#include "detect_single_character_xor.h"
#include "single_byte_xor_cypher.h"


namespace detectsinglecharacterxor {

void DetectSingleCharacterXor(std::istream &iss,
                              unsigned char *letter,
                              std::string *decoded_message,
                              double *score) {
  std::string curr_line;

  unsigned char curr_letter;
  std::string curr_message;
  double curr_score;

  unsigned char best_letter;
  std::string best_decoded_message;
  double best_score = std::numeric_limits<double>::min();

  while (std::getline(iss, curr_line)) {
    singlebytexorcypher::SingleByteXorCypher(curr_line,
                                             &curr_letter,
                                             &curr_message,
                                             &curr_score);
    if (curr_score > best_score) {
      best_letter = curr_letter;
      best_decoded_message = curr_message;
      best_score = curr_score;
    }
  }

  *score = best_score;
  if (best_score == std::numeric_limits<double>::min()) {
    return;
  }

  *letter = best_letter;
  *decoded_message = best_decoded_message;
}

}  // namespace detectsinglecharacterxor
