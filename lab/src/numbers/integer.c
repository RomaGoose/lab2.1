#include <stdio.h>

#include "vector.h"


static Vtable* int_vtable = NULL;

void int_add(void* left, void* right, void* result){
    *((int*)result) = *((int*)left) + *((int*)right);
    return;
}

void int_multiply(void* left, void* right, void* result){    
    *((int*)result) = *((int*)left) * *((int*)right);
    return;
}

size_t int_to_string(char* buff, size_t buff_size, void* value) {
    return snprintf(buff, buff_size, "%d", *((int*)value));
}

Vtable* get_int_base() {
    if (int_vtable == NULL){
        int_vtable = create_vtable();
        vtable_set_add(int_vtable, int_add);
        vtable_set_multiply(int_vtable, int_multiply);
        vtable_set_to_sring(int_vtable, int_to_string);
        vtable_set_size(int_vtable, sizeof(int));
    }
    return int_vtable;
}
