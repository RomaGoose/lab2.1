#pragma once

#include <stdlib.h>

typedef void (*binary_operation)(void* left, void* right, void* result); 

typedef struct _Vtable {
    size_t size;
    binary_operation add;
    binary_operation mulitply;
    char* (*to_string)(void* value);
} Vtable;

typedef struct _Scalar {
    Vtable* vtable;
    void* data;
} Scalar;