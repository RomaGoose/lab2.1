#pragma ocne 

#include "number.h"
#include "linear_form.h"

typedef struct {
    void* data;
    size_t dimension;
    Number base;
} Vector;

Linear_form_errors vector_add(Vector* vec1, Vector* vec2, Vector* result);
Linear_form_errors vector_dot(Vector* vec1, Vector* vec2, Number* result);
Linear_form_errors vector_scale(Vector* vec, Number* scalar, Vector* result);
Vector* create_vector(Number base, void* data, size_t dimension);
void free_vector(Vector* vec);