#include <stdio.h>

#include "number.h"
#include "integer.h"


static Number* INT_BASE = NULL;


void int_add(void* left, void* right, void* result){
    ((Int*)result)->value = ((Int*)left)->value + ((Int*)right)->value;
    return;
}

void int_multiply(void* left, void* right, void* result){    
    ((Int*)result)->value = ((Int*)left)->value * ((Int*)right)->value;
    return;
}

void int_print(void* value) {
    printf("%d", ((Int*)value)->value);
    return;
}


Number* get_int_type_info() {
    if (INT_BASE == NULL){
        INT_BASE = malloc(sizeof(Number));
        INT_BASE->vtable->add = int_add;
        INT_BASE->vtable->mulitply = int_multiply;
        INT_BASE->vtable->print = int_print;
        INT_BASE->vtable->size = sizeof(Int);
    }
    return INT_BASE;
}
