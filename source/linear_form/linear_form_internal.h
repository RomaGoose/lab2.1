#include "vector.h"

typedef struct _Linear_form {
    Vector* coeff_vector;
}Linear_form;

typedef enum {
    OK,
    OPERANDS_OR_RESULT_NOT_FOUND,
    DIFFERENT_TYPES_OF_LFORM,
    OPERATION_NOT_DEFINED,
    DIFFERENT_SIZES_OF_LFORM
}Linear_form_errors;
