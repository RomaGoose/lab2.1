#pragma once 

#include "number.h"

typedef struct _Int Int;

void int_add(void* left, void* right, void* result);
void int_multiply(void* left, void* right, void* result);
void int_print(void* value);
Number get_int_base();