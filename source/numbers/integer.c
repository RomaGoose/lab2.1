#include <stdio.h>

#include "number.h"
#include "integer_internal.h"


static Number INT_BASE = {.vtable = NULL};


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


Number get_int_base() {
    if (INT_BASE.vtable == NULL){
        INT_BASE.vtable = malloc(sizeof(Vtable));
        INT_BASE.vtable->add = int_add;
        INT_BASE.vtable->mulitply = int_multiply;
        INT_BASE.vtable->print = int_print;
        INT_BASE.vtable->size = sizeof(Int);
    }
    return INT_BASE;
}

int main() {
    Number num = get_int_base();
}
