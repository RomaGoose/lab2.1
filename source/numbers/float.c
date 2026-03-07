#include <stdio.h>

#include "float_internal.h"
#include "number.h"


static Number FLOAT_BASE = {.vtable = NULL};


void float_add(void* left, void* right, void* result){
    ((Float*)result)->value = ((Float*)left)->value + ((Float*)right)->value;
    return;
}

void float_multiply(void* left, void* right, void* result){    
    ((Float*)result)->value = ((Float*)left)->value * ((Float*)right)->value;
    return;
}

void float_print(void* value) {
    printf("%f", ((Float*)value)->value);
    return;
}

Number get_float_base() {
    if (FLOAT_BASE.vtable == NULL){
        FLOAT_BASE.vtable = malloc(sizeof(Vtable));
        FLOAT_BASE.vtable->add = float_add;
        FLOAT_BASE.vtable->mulitply = float_multiply;
        FLOAT_BASE.vtable->print = float_print;
        FLOAT_BASE.vtable->size = sizeof(float);
    }
    return FLOAT_BASE;
}
