#pragma once
#include <stdio.h>
#include <stdlib.h>

int print_stats();
int get_fail_count();

int assert_fail(const char* expr, const char* file, size_t line);
int assert_success(const char* expr, const char* file, size_t line);

#define assert(expression) ((void)(\
            (!!(expression))\
            ? assert_success(#expression, __FILE__, __LINE__)\
            : assert_fail(#expression, __FILE__, __LINE__)))

#define assert_eq(expression, expectation) ((void)(\
            (!!(expression == expectation))\
            ? assert_success(#expression "=" #expectation, __FILE__, __LINE__)\
            : assert_fail(#expression "!=" #expectation, __FILE__, __LINE__)))

#define expect_abort() ((void)(\
            (!!(abort_check))\
            ? assert_success("abort expected", __FILE__, __LINE__)\
            : assert_fail("abort expected", __FILE__, __LINE__)))

