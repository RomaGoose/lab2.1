#include <string.h>

#include "testing.h"
#include "linear_form.h"
#include "_float.h"
#include "integer.h"

TEST(lin_form_to_string){

    float coef_arr[] = {1.0, 2.0, 3.6, 4.6};
    Linear_form* lf = unwrap(create_linear_form(create_vector(get_float_base(), coef_arr, 4)));
    char* buff = unwrap(linear_form_to_string(lf));

    assert_eq(strcmp(buff, "Linear form F(X) = 1.00*x1 + 2.00*x2 + 3.60*x3 + 4.60*x4"), 0);

    assert_eq(unwrap_err(linear_form_to_string(NULL)), NULL_POINTER);

    free_linear_form(lf);
    free(buff);
}