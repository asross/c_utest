#include <stdlib.h>
#include "c_utest.h"

void one_is_one_and_not_two() {
  ASSERT_EQUAL_INTS(1, 1);
  ASSERT_DIFFN_INTS(1, 0);
}

void zero_is_truthy() {
  ASSERT(0);
}

void one_is_zero() {
  ASSERT_EQUAL_INTS(1, 0);
}

void malloc_returns_null() {
  char* a = malloc(sizeof(char));
  ASSERT_EQUAL_PTRS(a, NULL);
}

int main(void) {
  TEST_THAT(one_is_one_and_not_two);
  TEST_THAT(zero_is_truthy);
  TEST_THAT(one_is_zero);
  TEST_THAT(malloc_returns_null);
  RUN_TESTS();
}
