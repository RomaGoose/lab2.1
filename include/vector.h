#pragma once 

#include "linear_form.h"


typedef struct _Vtable Vtable;
typedef struct _Scalar Scalar;
typedef struct _Vector Vector;

Vtable* create_vtable();
void vtable_set_add(Vtable* vt, void (*add)(void* left, void* right, void* result));
void vtable_set_multiply(Vtable* vt, void (*multiply)(void* left, void* right, void* result));
void vtable_set_to_sring(Vtable* vt, char* (*to_string)(char* buff, size_t buff_size,void* value));
void vtable_set_size(Vtable* vt, size_t size);

Linear_form_errors vector_add(Vector* vec1, Vector* vec2, Vector* result);
Linear_form_errors vector_dot(Vector* vec1, Vector* vec2, Scalar* result);
Linear_form_errors vector_scale(Vector* vec, Scalar* scalar, Vector* result);
Vector* create_vector(Vtable* base, void* data, size_t dimension);
void free_vector(Vector* vec);