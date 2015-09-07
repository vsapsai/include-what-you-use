//===--- issue166_libstdc++-d1.h - test input file for iwyu ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This header mimics std::vector in libstdc++.

#include "tests/cxx/issue166_libstdc++-i1.h"

template<typename T>
class Container {
private:
  T content_;
public:
  typedef typename TypedefWrapper<T>::reference reference;
  reference getContent() { return content_; }
};
