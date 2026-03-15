#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "linear_form.h"
#include "integer.h"
#include "_float.h"

Linear_form* scan_lform(){
    fputs("Выберите тип данных для хранения: (0 - цел, 1 - вещ) ", stdout);
    Vtable* vt;
    char* fmt;
    int type; 
    scanf("%d", &type);
    if(type == 0){
        vt = get_int_base();
        fmt = "%d";
    }
    else if(type == 1){
        vt = get_float_base();
        fmt = "%f";
    }
    else exit(1);
    
    size_t dimension = 0;
    fputs("Введите размерность линейной формы: ", stdout);
    if(scanf("%d",&dimension) != 1 || dimension == 0) exit(1);
    
    void* coeffs = calloc(dimension, vtable_get_size(vt));
    for (size_t i = 0; i < dimension; ++i){
        printf("Введите коэффициент %zu: ", i + 1);
        scanf(fmt, coeffs + vtable_get_size(vt)*i);
    }

    Result* lf_res = create_linear_form(create_vector(vt, coeffs, dimension));
    Linear_form* lf;
    switch (get_res_type(lf_res)){
        case OK:{
            lf = unwrap(lf_res);
            break;
        }
        case ERROR:{
            fprintf(stderr, "%d", unwrap_err(lf_res));
            exit(1);
        }
    }
}

void process_input(){
    
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Linear_form* lf1 = scan_lform();
    Result* str1_res = linear_form_to_string(lf1);
    
    switch (get_res_type(str1_res)){
        case(OK):{
            printf("Ваша 1-ая линейная форма: %s\n", unwrap(str1_res));
            break;
        }
        case(ERROR):{
            printf("Ошибка. Код ошибки: %d", unwrap_err(str1_res));
            return;
        }
    }
    
    Linear_form* lf2= scan_lform();
    Result* str2_res = linear_form_to_string(lf2);
    
    switch (get_res_type(str2_res)){
        case(OK):{
            printf("Ваша 2-ая линейная форма: %s\n", unwrap(str2_res));
            break;
        }
        case(ERROR):{
            printf("Ошибка. Код ошибки: %d", unwrap_err(str2_res));
            return;
        }
    }
    
    Result* sum_res = linear_form_add(lf1, lf2);
    
    switch (get_res_type(sum_res)){
        case(OK):{
            Result* str_res = linear_form_to_string(unwrap(sum_res));
                switch (get_res_type(str2_res)){
                case(OK):{
                    printf("Сумма линейных форм: %s", unwrap(str_res));
                    break;
                }
                case(ERROR):{
                    printf("Ошибка. Код ошибки: %d", unwrap_err(str_res));
                    return;
                }
            }
            break;
        }
        case(ERROR):{
            printf("Ошибка. Код ошибки: %d", unwrap_err(sum_res));
            return;
        }
    }
}