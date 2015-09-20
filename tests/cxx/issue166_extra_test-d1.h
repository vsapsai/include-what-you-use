#include "tests/cxx/issue166_extra_test-i1.h"

template<typename T>
class NonContainer {
 public:
  typedef Container<T> value;
  typedef value& reference;

  value container_;
  reference getContainer() { return container_; }
};
