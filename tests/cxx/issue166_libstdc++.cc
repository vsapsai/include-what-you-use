//===--- issue166_libstdc++.cc - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Failing test case for issue #166 that mimics libstdc++.

#include "tests/cxx/issue166_libstdc++-d1.h"
#include "tests/cxx/direct.h"

void referenceUsage() {
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  Container<IndirectClass> c;
  c.getContent().Method();
}

/**** IWYU_SUMMARY

tests/cxx/issue166_libstdc++.cc should add these lines:
#include "tests/cxx/indirect.h"

tests/cxx/issue166_libstdc++.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/issue166_libstdc++.cc:
#include "tests/cxx/indirect.h"  // for IndirectClass
#include "tests/cxx/issue166_libstdc++-d1.h"  // for Container

***** IWYU_SUMMARY */
