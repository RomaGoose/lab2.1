#include <string.h>

#include "linear_form_internal.h"

Linear_form* create_linear_form(Number base, Vector* coefficients, size_t dimension){
    Linear_form* l_form = malloc(sizeof(Linear_form));
    l_form->coeff_vector = coefficients;

    return l_form;
} 

Linear_form_errors linear_form_add(Linear_form* left, Linear_form* right, Linear_form* result){
    vector_add(left->coeff_vector, right->coeff_vector, result->coeff_vector);
}

Linear_form_errors linear_form_scale(Linear_form* l_form, Number* scalar, Linear_form* result){
    vector_scale(l_form->coeff_vector, scalar, result->coeff_vector);
}

Linear_form_errors linear_form_evaluate(Linear_form* l_form, Vector* arguments, Number* result){
    vector_dot(l_form->coeff_vector, arguments, result);
}

void free_linear_form(Linear_form* l_form){
    free_vector(l_form->coeff_vector);
    free(l_form);
}