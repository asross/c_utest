# `c_utest`

## What?

A tiny C testing library, inspired by [these](https://github.com/siu/minunit)
[versions](http://www.jera.com/techinfo/jtns/jtn002.html) of MinUnit.

## Why?

Partially to write some tests, mostly to learn how to use macros.

## How?

The following code:

```c
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
```

Should produce something like the following output:

```
About to run 4 tests...

.FFF

a_failure failed with:
	assertion error

another_failure failed with:
	expected 1 to equal 0

yet_another_failure failed with:
	expected 0x7fb300c03230 to equal 0x0

Total failures: 3
```
