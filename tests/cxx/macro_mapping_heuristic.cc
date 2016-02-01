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
