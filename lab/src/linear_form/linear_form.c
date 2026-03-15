#include <string.h>
#include <stdio.h>

#include "linear_form_internal.h"

Result* create_linear_form(Result* coefficients_vector){
    null_check(coefficients_vector);
    switch (get_res_type(coefficients_vector)) {
        case OK:
            Linear_form* l_form = malloc(sizeof(Linear_form));
            l_form->coeff_vector = unwrap(coefficients_vector);
            return ok(l_form);
        case ERROR:
            return coefficients_vector;
        }
} 
Result* linear_form_set_elem(Linear_form* l_form, size_t index, Scalar* elem){
    null_check(l_form);
    return vector_set_elem(l_form->coeff_vector, index, elem);
}
Result* linear_form_get_elem(Linear_form* l_form, size_t index){
    null_check(l_form);
    return vector_get_elem(l_form->coeff_vector, index);
}
Result* linear_form_add(Linear_form* left, Linear_form* right){
    null_check(left, right);
    return create_linear_form(vector_add(left->coeff_vector, right->coeff_vector));
}
Result* linear_form_scale(Linear_form* l_form, Scalar* scalar){
    null_check(l_form);
    return create_linear_form(vector_scale(l_form->coeff_vector, scalar));
}
Result* linear_form_evaluate(Linear_form* l_form, Vector* arguments){
    null_check(l_form);
    return vector_dot(l_form->coeff_vector, arguments);
}
Result* linear_form_eq(Linear_form* lf1, Linear_form* lf2){
    return vector_eq(lf1->coeff_vector, lf2->coeff_vector);
}
static size_t coeffs_strlen(size_t dimension){
    size_t len = LFORM_STR_SEP_LEN * dimension - LFORM_STR_LAST_PLUS;
    for(size_t i = 0; i < dimension; ++i){
        len += snprintf(NULL, 0, "%zu", i);
    }
    return len;
}
Result* linear_form_to_string(Linear_form* lf){
    null_check(lf); 

    size_t elem_buffers_size = 0;
    char** elem_buffers = scalars_to_string(lf->coeff_vector, &elem_buffers_size);
    size_t lform_buff_size = LFORM_STR_START_LEN + coeffs_strlen(lf->coeff_vector->dimension) + elem_buffers_size + 1;

    char* lform_buff = calloc(lform_buff_size, sizeof(char));

    char sep[16];
    strcat(lform_buff, LFORM_STR_START);
    for(size_t i = 0; i < lf->coeff_vector->dimension - 1; ++i){
        strcat(lform_buff, elem_buffers[i]);
        sprintf(sep, "*x%zu + ", i+1);
        strcat(lform_buff, sep);
        free(elem_buffers[i]);
    }
    strcat(lform_buff, elem_buffers[lf->coeff_vector->dimension - 1]);
    sprintf(sep, "*x%zu", lf->coeff_vector->dimension);
    strcat(lform_buff, sep);

    free(elem_buffers);

    return ok(lform_buff);
}
void free_linear_form(Linear_form* l_form){
    if(!l_form) return;
    free_vector(l_form->coeff_vector);
    free(l_form);
}