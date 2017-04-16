// Copyright 2017 <felipeamp>

#include <string>

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

#include "decrypt_aes_ecb_mode.h"
#include "utils.h"

namespace decryptaesecbmode {

std::string DecryptAesEcbMode(const std::string &encrypted_bytes,
                              const std::string &key) {
  std::basic_string<unsigned char> encrypted_bytes_uc(encrypted_bytes.begin(),
                                                      encrypted_bytes.end());
  std::basic_string<unsigned char> key_uc(key.begin(), key.end());

  EVP_CIPHER_CTX ctx;
  EVP_CIPHER_CTX_init(&ctx);
  EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, key_uc.c_str(), NULL);
  EVP_CIPHER_CTX_set_padding(&ctx, false);

  unsigned char buffer[1024], *buffer_pointer = buffer;
  int output_length;

  EVP_DecryptUpdate(&ctx,
                    buffer_pointer,
                    &output_length,
                    encrypted_bytes_uc.c_str(),
                    encrypted_bytes_uc.length());
  buffer_pointer += output_length;
  EVP_DecryptFinal_ex(&ctx, buffer_pointer, &output_length);
  buffer_pointer += output_length;

  std::basic_string<unsigned char> decrypted_uc(buffer, buffer_pointer - buffer);
  return std::string(decrypted_uc.begin(), decrypted_uc.end());
  }

}  // namespace decryptaesecbmode
