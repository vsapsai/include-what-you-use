//===--- issue166_libc++.cc - test input file for iwyu --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Failing test case for issue #166 that mimics libc++.  Note that bug is
// reproduced by test only when you have a list of symbols per file.  So it is
// important that you #include "tests/cxx/direct.h" to achieve imperfect
// includes.

#include "tests/cxx/issue166_libc++-d1.h"
#include "tests/cxx/direct.h"

void referenceUsage() {
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  Container<IndirectClass> c;
  c.getContent().Method();
}

/**** IWYU_SUMMARY

tests/cxx/issue166_libc++.cc should add these lines:
#include "tests/cxx/indirect.h"

tests/cxx/issue166_libc++.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/issue166_libc++.cc:
#include "tests/cxx/indirect.h"  // for IndirectClass
#include "tests/cxx/issue166_libc++-d1.h"  // for Container

***** IWYU_SUMMARY */
