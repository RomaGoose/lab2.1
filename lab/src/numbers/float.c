#include <stdio.h>

#include "vector.h"

static Vtable* FLOAT_VTABLE = NULL;


void float_add(void* left, void* right, void* result){
    *((float*)result) = *((float*)left) + *((float*)right);
    return;
}

void float_multiply(void* left, void* right, void* result){    
    *((float*)result) = *((float*)left) * *((float*)right);
    return;
}

void float_to_string(char* buff, size_t buff_size, void* value) {
    snprintf(buff, buff_size, "%f", *((float*)value));
    return;
}

Vtable* get_float_base() {
    if (FLOAT_VTABLE == NULL){
        FLOAT_VTABLE = create_vtable();
        vtable_set_add(FLOAT_VTABLE, float_add);
        vtable_set_multiply(FLOAT_VTABLE, float_multiply);
        vtable_set_to_sring(FLOAT_VTABLE, float_to_string);
        vtable_set_size(FLOAT_VTABLE, sizeof(float));
    }
    return FLOAT_VTABLE;
}
