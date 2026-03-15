#pragma once 

#include "vector.h"

typedef struct _Linear_form Linear_form;

Result* create_linear_form(Result* coefficients);
Result* linear_form_add(Linear_form* left, Linear_form* right);
Result* linear_form_scale(Linear_form* l_form, Scalar* scalar);
Result* linear_form_evaluate(Linear_form* l_form, Vector* arguments);
Result* linear_form_eq(Linear_form* lf1, Linear_form* lf2);
Result* linear_form_to_string(Linear_form* lf);
void free_linear_form(Linear_form* l_form);