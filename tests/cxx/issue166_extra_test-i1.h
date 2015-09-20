#ifndef DEVTOOLS_MAINTENANCE_INCLUDE_WHAT_YOU_USE_TESTS_ISSUE166_EXTRA_TEST_I1_H_
#define DEVTOOLS_MAINTENANCE_INCLUDE_WHAT_YOU_USE_TESTS_ISSUE166_EXTRA_TEST_I1_H_

template<typename T>
class Container {
 public:
  typedef T value;
  typedef value& reference;

  value content_;
  reference getContent() { return content_; }
};

#endif  // DEVTOOLS_MAINTENANCE_INCLUDE_WHAT_YOU_USE_TESTS_ISSUE166_EXTRA_TEST_I1_H_
