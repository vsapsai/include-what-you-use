#include "tests/cxx/issue166_extra_test-d1.h"
#include "tests/cxx/indirect.h"

void usage() {
  NonContainer<IndirectClass> nc;
  nc.getContainer().getContent().Method();
}
