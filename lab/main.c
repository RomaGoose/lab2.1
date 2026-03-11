#include "vector.h"
#include "linear_form.h"
#include "integer.h"
#include "_float.h"

#include <stdio.h>

int main (){

    int coeffs[3]= {1,2,3};
    Vector* coeff_v = create_vector(get_int_base(), coeffs, 3);
    Linear_form* lf = create_linear_form(coeff_v);

    int scal = 5;
    int nul[3] = {0};
    
    Vector* nul_v = create_vector(get_int_base(), nul, 3);
    Linear_form* nulf = create_linear_form(nul_v);
    Scalar* scla = create_scalar(get_int_base(), &scal);
    linear_form_scale(lf, scla, nulf);
    
    int res = 0;
    Scalar* res_scla = create_scalar(get_int_base(), &res);
    linear_form_evaluate(nulf, coeff_v, res_scla);
    
    printf("result: %d", res);
    
    return 0;
}