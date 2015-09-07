//===--- issue166_libstdc++-i1.h - test input file for iwyu ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This header mimics ext/alloc_traits.h in libstdc++.

template<typename T>
struct TypedefWrapper {
	typedef T value;
	typedef value& reference;
};
