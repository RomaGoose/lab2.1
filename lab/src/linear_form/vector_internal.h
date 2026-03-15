#pragma once

#include "vector.h"
#include "scalar.h"


#define VECTOR_STR_START "Vector = {"
#define VECTOR_STR_END "}"
#define VECTOR_STR_SEP ", "
#define VECTOR_STR_START_LEN 10
#define VECTOR_STR_END_LEN 1
#define VECTOR_STR_SEP_LEN 2



typedef struct _Vector {
    void* data;
    Vtable* base;
    size_t dimension;
} Vector;
