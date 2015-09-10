//===--- issue166_naive_fix.cc - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Tests that when we use a typedef, IWYU doesn't suggest to include file for
// underlying type.

#include "tests/cxx/issue166_naive_fix-d1.h"

void directUsage() {
  IndirectClassTypedef ict;
  ict.Method();
}

/**** IWYU_SUMMARY

(tests/cxx/issue166_naive_fix.cc has correct #includes/fwd-decls)

***** IWYU_SUMMARY */
