#include <stdio.h>

#include "vector.h"

static Vtable* float_vtable = NULL;


void float_add(void* left, void* right, void* result){
    *((float*)result) = *((float*)left) + *((float*)right);
    return;
}

void float_multiply(void* left, void* right, void* result){    
    *((float*)result) = *((float*)left) * *((float*)right);
    return;
}

size_t float_to_string(char* buff, size_t buff_size, void* value) {
    return snprintf(buff, buff_size, "%f", *((float*)value));
}

Vtable* get_float_base() {
    if (float_vtable == NULL){
        float_vtable = create_vtable();
        vtable_set_add(float_vtable, float_add);
        vtable_set_multiply(float_vtable, float_multiply);
        vtable_set_to_sring(float_vtable, float_to_string);
        vtable_set_size(float_vtable, sizeof(float));
    }
    return float_vtable;
}
