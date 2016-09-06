#include <stdio.h>
#include <string.h>
#define MAX_TEST_COUNT 100
#define MAX_NAME_CHARS 256
#define MAX_MSG_CHARS 1024
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"

static char _test_names[MAX_TEST_COUNT][MAX_NAME_CHARS];
static char _failure_msgs[MAX_TEST_COUNT][MAX_MSG_CHARS];
typedef void (*UnitTest)(void);
static UnitTest _test_funcs[MAX_TEST_COUNT];
static int _failed_tests[MAX_TEST_COUNT];
static int _test_count = 0;
static int _fail_count = 0;
static int _test_status = 0;
static int _current_test = 0;

#define RUN_TESTS() do {\
  printf("About to run %d tests...\n\n", _test_count);\
  _fail_count = 0;\
  while (_current_test < _test_count) {\
    _test_status = 0;\
    _test_funcs[_current_test]();\
    if (_test_status) \
      printf("%sF", KRED);\
    else \
      printf("%s.", KGRN);\
    _current_test++;\
  }\
  printf("%s\n", KNRM);\
  for (int i = 0; i < _fail_count; i++) {\
    printf("\n%s%s %sfailed with:\n\t%s\n",\
        KYEL, _test_names[_failed_tests[i]], KNRM, _failure_msgs[i]);\
  }\
  if (_fail_count) {\
    printf("\nTotal failures: %d\n\n", _fail_count);\
  } else {\
    printf("\nAll tests passed!\n\n");\
  }\
  return _fail_count;\
} while (0)

#define FAIL_WITH(...) do {\
  _test_status = 1;\
  _failed_tests[_fail_count] = _current_test;\
  char _failure_msg[MAX_MSG_CHARS];\
  sprintf(_failure_msg, ##__VA_ARGS__);\
  strcpy(_failure_msgs[_fail_count], _failure_msg);\
  _fail_count++;\
  return;\
} while(0)

#define ASSERT(a) \
  if (!a) \
    FAIL_WITH("assertion error");

#define ASSERT_EQUAL_INTS(a, b) \
  if (a != b) \
    FAIL_WITH("expected %d to equal %d", a, b);

#define ASSERT_EQUAL_PTRS(a, b) \
  if (a != b) \
    FAIL_WITH("expected %p to equal %p", a, b);

#define TEST(name) do {\
  _test_funcs[_test_count] = name;\
  strcpy(_test_names[_test_count], #name);\
  _test_count++;\
} while(0)
