#pragma once

#include "number.h"

typedef struct _Float Float;

void float_add(void* left, void* right, void* result);
void float_multiply(void* left, void* right, void* result);
void float_print(void* value);
Number get_float_base();
