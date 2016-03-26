//===--- macro_mapping_heuristic.cc - test input file for iwyu ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "tests/cxx/macro_mapping_heuristic-d1.h"

MacroMappingHeuristicI1 mmh1;


#define TYPE int
#include "tests/cxx/macro_mapping_heuristic-d2.h"
#undef TYPE
#define TYPE double
#include "tests/cxx/macro_mapping_heuristic-d2.h"
#undef TYPE
int main()
{
  f(3);
  f(3.1);
}

/**** IWYU_SUMMARY

(tests/cxx/macro_mapping_heuristic.cc has correct #includes/fwd-decls)

***** IWYU_SUMMARY */
