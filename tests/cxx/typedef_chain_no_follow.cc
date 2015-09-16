//===--- typedef_chain_no_follow.cc - test input file for iwyu ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Tests cases when IWYU should not follow typedef chain and should not suggest
// to include a file for underlying typedef type.

#include "tests/cxx/typedef_chain_no_follow-d1.h"
#include "tests/cxx/typedef_chain_no_follow-d2.h"
#include "tests/cxx/typedef_chain_no_follow-d3.h"
// Unused include to trigger IWYU summary telling what symbols are used from
// every file.
#include "tests/cxx/direct.h"

void typedefDeclaredInGlobalNamespace() {
  TypedefChainTypedef tct;
  tct.Method();
}

// Tests how we handle a typedef declared in a class.  Main purpose is to make
// sure we handle typedefs in templates the same way as typedefs in classes
// when typedef does not depend on template argument.
void typedefDeclaredInClass() {
  NonContainer1 nc;
  nc.getTypedefChainClass().Method();
}

// Tests that we don't follow typedef chain and don't suggest to use
// TypedefChainClass directly.
void typedefDeclaredInTemplate() {
  NonContainer2<int> nc;
  nc.getTypedefChainClass().Method();
}

/**** IWYU_SUMMARY

tests/cxx/typedef_chain_no_follow.cc should add these lines:

tests/cxx/typedef_chain_no_follow.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/typedef_chain_no_follow.cc:
#include "tests/cxx/typedef_chain_no_follow-d1.h"  // for TypedefChainTypedef
#include "tests/cxx/typedef_chain_no_follow-d2.h"  // for NonContainer1, NonContainer1::value
#include "tests/cxx/typedef_chain_no_follow-d3.h"  // for NonContainer2, NonContainer2::value

***** IWYU_SUMMARY */
