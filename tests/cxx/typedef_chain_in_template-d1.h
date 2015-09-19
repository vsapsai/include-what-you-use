//===--- typedef_chain_in_template-d1.h - test input file for iwyu --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This header mimics std::vector in libstdc++.

#include "tests/cxx/typedef_chain_in_template-i1.h"

template<typename T>
class ContainerAsLibstdcpp {
 private:
  T content_;
 public:
  typedef typename TypedefWrapper<T>::reference reference;
  reference getContent() { return content_; }
};
