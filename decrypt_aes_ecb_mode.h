// Copyright 2017 <felipeamp>

#ifndef DECRYPT_AES_ECB_MODE_H_
#define DECRYPT_AES_ECB_MODE_H_

#include <string>

namespace decryptaesecbmode {

std::string DecryptAesEcbMode(const std::string &encrypted_bytes,
                              const std::string &key);

}  // namespace decryptaesecbmode

#endif  // DECRYPT_AES_ECB_MODE_H_
