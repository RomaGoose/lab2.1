#pragma once

#include "vector.h"
#include "scalar.h"

typedef struct _Vector {
    void* data;
    Vtable* base;
    size_t dimension;
} Vector;
