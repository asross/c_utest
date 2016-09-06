#include <stdlib.h>
#include "c_utest.h"

void a_success() {
  ASSERT_EQUAL_INTS(1, 1);
}

void a_failure() {
  ASSERT(0);
}

void another_failure() {
  ASSERT_EQUAL_INTS(1, 0);
}

void yet_another_failure() {
  char * a = malloc(sizeof(char));
  ASSERT_EQUAL_PTRS(a, NULL);
}

int main(void) {
  TEST(a_success);
  TEST(a_failure);
  TEST(another_failure);
  TEST(yet_another_failure);
  RUN_TESTS();
  return 0;
}
