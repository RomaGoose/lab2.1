#pragma ocne 

#include "number.h"

typedef struct {
    Number base;
    int value;
}Float;

void float_add(void* left, void* right, void* result);
void float_multiply(void* left, void* right, void* result);
void float_print(void* value);
Number* get_float_base();
