#include <stdio.h>

#include "vector.h"


static Vtable* INT_VTABLE = NULL;

void int_add(void* left, void* right, void* result){
    *((int*)result) = *((int*)left) + *((int*)right);
    return;
}

void int_multiply(void* left, void* right, void* result){    
    *((int*)result) = *((int*)left) * *((int*)right);
    return;
}

void int_to_string(char* buff, size_t buff_size, void* value) {
    snprintf(buff, buff_size, "%d", *((int*)value));
    return;
}

Vtable* get_int_base() {
    if (INT_VTABLE == NULL){
        INT_VTABLE = create_vtable();
        vtable_set_add(INT_VTABLE, int_add);
        vtable_set_multiply(INT_VTABLE, int_multiply);
        vtable_set_to_sring(INT_VTABLE, int_to_string);
        vtable_set_size(INT_VTABLE, sizeof(int));
    }
    return INT_VTABLE;
}
