#include <string.h>

#include "linear_form.h"
#include "vector.h"

Linear_form* create_linear_form(Number base, Vector* coefficients, size_t dimension){
    Linear_form* l_form = malloc(sizeof(Linear_form));

    l_form->base = base;
    l_form->dimension = dimension;
    l_form->data = coefficients;

    return l_form;
} 

Linear_form_errors linear_form_add(Linear_form* left, Linear_form* right, Linear_form* result){
    vector_add(left->data, right->data, result->data);
}

Linear_form_errors linear_form_scale(Linear_form* l_form, Number* scalar, Linear_form* result){
    vector_scale(l_form->data, scalar, result->data);
}

Linear_form_errors linear_form_evaluate(Linear_form* l_form, Vector* arguments, Number* result){
    vector_dot(l_form->data, arguments, result);
}

void free_linear_form(Linear_form* l_form){
    free_vector(l_form->data);
    free(l_form);
}