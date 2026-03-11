#pragma once
#include <stdio.h>
#include <stdlib.h>

int print_stats();
int get_fail_count();

#define assert(expression) ((void)(\
            (!!(expression))\
            ? assert_success(#expression, __FILE__, __LINE__)\
            : assert_fail(#expression, __FILE__, __LINE__)))