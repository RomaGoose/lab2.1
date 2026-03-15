#include <string.h>

#include "scalar.h"
#include "result.h"


Vtable* create_vtable(){
    Vtable* new = malloc(sizeof(Vtable));
    return new;
}

Result* create_scalar(Vtable* vtable, void* value){
    null_check(vtable, value);

    Scalar* new_scalar = malloc(sizeof(Scalar));
    new_scalar->vtable = vtable;
    new_scalar->value = malloc(vtable->size);

    memcpy(new_scalar->value, value, vtable->size);

    return ok(new_scalar);
}
Result* create_null_scalar(Vtable* vtable){
    null_check(vtable);

    Scalar* new_scalar = malloc(sizeof(Scalar));
    new_scalar->vtable = vtable;
    new_scalar->value = calloc(1, vtable->size);

    return ok(new_scalar);
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

