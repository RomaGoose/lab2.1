#pragma once

#include "vector.h"
#include "vector_internal.h"

#define LFORM_STR_START "Linear form F(X) = "
#define LFORM_STR_SEP(index) "*x"#index" + "
#define LFORM_STR_SEP_LEN 5
#define INT_TO_STR(x) #x
#define LFORM_STR_START_LEN 19
#define LFORM_STR_LAST_PLUS 3

typedef struct _Linear_form {
    Vector* coeff_vector;
}Linear_form;

char** scalars_to_string(Vector* vec, size_t* return_buff_size);