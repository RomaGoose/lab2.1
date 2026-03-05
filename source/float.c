#include <stdio.h>

#include "_float.h"
#include "number.h"


static Number* FLOAT_BASE = NULL;


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

Number* get_float_base() {
    if (FLOAT_BASE == NULL){
        FLOAT_BASE = malloc(sizeof(Number));
        FLOAT_BASE->vtable->add = float_add;
        FLOAT_BASE->vtable->mulitply = float_multiply;
        FLOAT_BASE->vtable->print = float_print;
        FLOAT_BASE->vtable->size = sizeof(float);
    }
    return FLOAT_BASE;
}
