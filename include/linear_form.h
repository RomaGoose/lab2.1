#pragma once 

#include "number.h"
#include "vector.h"

typedef struct _Linear_form Linear_form;

typedef enum _Linear_form_errors Linear_form_errors;

Linear_form* create_linear_form(Number base, Vector* coefficients, size_t dimension);
Linear_form_errors linear_form_add(Linear_form* left, Linear_form* right, Linear_form* result);
Linear_form_errors linear_form_scale(Linear_form* l_form, Number* scalar, Linear_form* result);
Linear_form_errors linear_form_evaluate(Linear_form* l_form, Vector* arguments, Number* result);
void free_linear_form(Linear_form* l_form);