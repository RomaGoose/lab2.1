#include "scalar.h"
#include <string.h>

Vtable* create_vtable(){
    Vtable* new = malloc(sizeof(Vtable));
    return new;
}

Scalar* create_scalar(Vtable* vtable, void* value){
    Scalar* new_scalar = malloc(sizeof(Scalar));
    new_scalar->vtable = vtable;
    new_scalar->value = malloc(vtable->size);

    memcpy(new_scalar->value, value, vtable->size);

    return new_scalar;
}
Scalar* create_null_scalar(Vtable* vtable){
    Scalar* new_scalar = malloc(sizeof(Scalar));
    new_scalar->vtable = vtable;
    new_scalar->value = calloc(1, vtable->size);

    return new_scalar;
}

void free_scalar(Scalar* scalar){
    free(scalar->value);
    free(scalar);
}

void vtable_set_add(Vtable* vt, void (*add)(void* left, void* right, void* result)){
    vt->add = add;
}
void vtable_set_multiply(Vtable* vt, void (*multiply)(void* left, void* right, void* result)){
    vt->mulitply = multiply;
}
void vtable_set_to_sring(Vtable* vt, size_t (*to_string)(char* buff, size_t buff_size, void* value)){
    vt->to_string = to_string;
}
void vtable_set_size(Vtable* vt, size_t size){
    vt->size = size;
}

