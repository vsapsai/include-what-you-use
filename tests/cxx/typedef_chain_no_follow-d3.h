//===--- typedef_chain_no_follow-d3.h - test input file for iwyu ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Declares typedef inside a template, typedef does not depend on template
// argument.

#include "tests/cxx/typedef_chain_class.h"

template<typename T>
class NonContainer2 {
 public:
  typedef TypedefChainClass value;
  typedef value& reference;

  value tcc_;
  reference getTypedefChainClass() { return tcc_; }
};
