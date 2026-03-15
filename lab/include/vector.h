#pragma once 

#include <stdlib.h>

#include "result.h"

typedef struct _Vtable Vtable;
typedef struct _Scalar Scalar;
typedef struct _Vector Vector;


Vtable* create_vtable();
Result* create_scalar(Vtable* vtable, void* value);
Result* create_null_scalar(Vtable* vtable);
void free_scalar(Scalar* scalar); 

void vtable_set_add(Vtable* vt, void (*add)(void* left, void* right, void* result));
void vtable_set_multiply(Vtable* vt, void (*multiply)(void* left, void* right, void* result));
void vtable_set_to_sring(Vtable* vt, size_t (*to_string)(char* buff, size_t buff_size,void* value));
void vtable_set_size(Vtable* vt, size_t size);

Result* vector_get_elem(Vector* vec, size_t index);
Result* vector_set_elem(Vector* vec, size_t index,Scalar* elem);
Result* vector_eq(Vector* vec1, Vector* vec2);
// Result* vector_copy_from(Vector* vec);
// Result* vector_copy_to(Vector* vec, Vtable* base, void* data, size_t dimension);

Result* vector_add(Vector* vec1, Vector* vec2);
Result* vector_dot(Vector* vec1, Vector* vec2);
Result* vector_scale(Vector* vec, Scalar* scalar);

Result* vector_to_string(Vector* vec);

Result* create_vector(Vtable* base, void* data, size_t dimension);
Result* create_empty_vector(Vtable* base, size_t dimension);
void free_vector(Vector* vec);