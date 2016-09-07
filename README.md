## What?

A tiny C testing library, inspired by [these](https://github.com/siu/minunit)
[versions](http://www.jera.com/techinfo/jtns/jtn002.html) of MinUnit.

## Why?

Partially to write some tests, mostly to learn how to (ab)use macros.

## How?

The following code:

```c
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
```

If you check it out and run:

```bash
gcc example.c && ./a.out
```

Should produce (a colorized version of) the following output:

```
About to run 4 tests...

.FFF

TEST_THAT(zero_is_truthy) failed with:
	assertion error

TEST_THAT(one_is_zero) failed with:
	expected 1 to equal 0

TEST_THAT(malloc_returns_null) failed with:
	expected 0x7fa03a401a80 to equal 0x0

Total failures: 3
```
