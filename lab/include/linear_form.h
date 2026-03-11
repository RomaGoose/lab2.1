#pragma once 

#include "vector.h"

typedef struct _Linear_form Linear_form;


Linear_form* create_linear_form(Vector* coefficients);
Linear_form_errors linear_form_add(Linear_form* left, Linear_form* right, Linear_form* result);
Linear_form_errors linear_form_scale(Linear_form* l_form, Scalar* scalar, Linear_form* result);
Linear_form_errors linear_form_evaluate(Linear_form* l_form, Vector* arguments, Scalar* result);
void free_linear_form(Linear_form* l_form);