#pragma once

#include "vector.h"
#include "scalar.h"


#define VECTOR_STR_START "Vector: ("
#define VECTOR_STR_END ")"
#define VECTOR_STR_SEP ", "


typedef struct _Vector {
    void* data;
    Vtable* base;
    size_t dimension;
} Vector;
