//===--- iterator_indirect.cc - test input file for iwyu ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Test to which files iterators are attributed to and in what cases iterator
// use is considered to be full.

#include "tests/cxx/iterator_indirect-d1.h"

void foo() {
  // Make sure we don't claim set::iterator is defined in map.
  // IWYU: std::set is...*<set>
  std::set<int> localset;
  // IWYU: std::set is...*<set>
  // IWYU: std::set<.*>::iterator is...*<set>
  std::set<int>::iterator it_set = localset.begin();

  // Lots of weird stuff can happen with iterators, especially regarding const.
  // IWYU: std::vector is...*<vector>
  std::vector<float> float_vector;
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  std::vector<float>::const_iterator float_it = float_vector.begin();
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  const std::vector<float>::const_iterator float_constit = float_vector.begin();
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  (void)(float_it == float_constit);
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  (void)(float_constit == float_it);
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  std::vector<float>::const_iterator float_forit;
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  for (float_forit = float_vector.begin(); ;) ;
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  for (std::vector<float>::const_iterator it = float_vector.begin(); ;) ;
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_iterator is...*<vector>
  for (const std::vector<float>::const_iterator it = float_vector.begin(); ;) ;
  // We special-case vector<>::iterator.  Make sure it holds for
  // reverse_iterator too.
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::reverse_iterator is...*<vector>
  for (std::vector<float>::reverse_iterator
         // IWYU: std::vector is...*<vector>
         float_reverse_it = float_vector.rbegin();
     // IWYU: std::vector is...*<vector>
     // IWYU: std::vector<.*>::reverse_iterator is...*<vector>
     float_reverse_it != float_vector.rbegin();
     // IWYU: std::vector is...*<vector>
     // IWYU: std::vector<.*>::reverse_iterator is...*<vector>
     ++float_reverse_it) ;
  // IWYU: std::vector is...*<vector>
  // IWYU: std::vector<.*>::const_reverse_iterator is...*<vector>
  for (std::vector<float>::const_reverse_iterator
         // We need const_reverse_iterator here because of the
         // conversion from reverse_iterator (from rbegin()).
         // IWYU: std::vector<.*>::const_reverse_iterator is...*<vector>
         // IWYU: std::vector is...*<vector>
         float_const_reverse_it = float_vector.rbegin();
     // IWYU: std::vector is...*<vector>
     // IWYU: std::vector<.*>::const_reverse_iterator is...*<vector>
     float_const_reverse_it != float_vector.rend();
     // IWYU: std::vector is...*<vector>
     // IWYU: std::vector<.*>::const_reverse_iterator is...*<vector>
     ++float_const_reverse_it) ;
}

/**** IWYU_SUMMARY

tests/cxx/iterator_indirect.cc should add these lines:
#include <set>
#include <vector>

tests/cxx/iterator_indirect.cc should remove these lines:
- #include "tests/cxx/iterator_indirect-d1.h"  // lines XX-XX

The full include-list for tests/cxx/iterator_indirect.cc:
#include <set>  // for set, set<>::iterator
#include <vector>  // for allocator, vector, vector<>::const_iterator, vector<>::const_reverse_iterator, vector<>::reverse_iterator

***** IWYU_SUMMARY */


