#include "number.h"

typedef struct {
    Vector* data;
}Linear_form;

typedef enum {
    OK,
    OPERANDS_OR_RESULT_NOT_FOUND,
    DIFFERENT_TYPES_OF_LFORM,
    OPERATION_NOT_DEFINED,
    DIFFERENT_SIZES_OF_LFORM
}Linear_form_errors;

Linear_form* create_linear_form(Number base, Vector* coefficients, size_t dimension);
Linear_form_errors linear_form_add(Linear_form* left, Linear_form* right, Linear_form* result);
Linear_form_errors linear_form_scale(Linear_form* l_form, Number* scalar, Linear_form* result);
Linear_form_errors linear_form_evaluate(Linear_form* l_form, Vector* arguments, Number* result);
void free_linear_form(Linear_form* l_form);