#include "vector.h"
#include "linear_form.h"
#include "integer.h"
#include "_float.h"
#include "number.h"

int main (){

    int vecarr[5] = {0,12,3,4,5};
    Vector* vec = create_vector(get_int_base(), &vecarr, 5);
    Linear_form* lf = create_linear_form(get_int_base(), vec, 5);
    
    return 0;
}