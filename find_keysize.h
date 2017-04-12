// Copyright 2017 <felipeamp>
#ifndef FIND_KEYSIZE_H_
#define FIND_KEYSIZE_H_

#include <vector>

namespace findkeysize {

std::vector<size_t> FindKeysize(const std::vector<unsigned char>& bytes,
                                size_t num_ret);

}  // namespace findkeysize

#endif  // FIND_KEYSIZE_H_
