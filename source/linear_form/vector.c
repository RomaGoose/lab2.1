#include "vector_internal.h"
#include "linear_form.h"
#include "linear_form_internal.h"

Linear_form_errors vector_add(Vector* vec1, Vector* vec2, Vector* result){
    if(!vec1 || !vec2 || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    if(!vec1->base.vtable->add) return OPERATION_NOT_DEFINED;
    if(vec1->base.vtable != vec2->base.vtable && vec1->base.vtable != result->base.vtable) return DIFFERENT_TYPES_OF_LFORM;
    if(vec1->dimension != vec2->dimension && vec1->dimension != result->dimension) return DIFFERENT_SIZES_OF_LFORM;
    


    // Number base1 = vec1->base;
    Number base = *(Number*)&vec1->base;

    char* v1_data = (char*)vec1->data;
    char* v2_data = (char*)vec2->data;
    char* res_data = (char*)result->data;
    for(size_t i = 0; i < vec1->dimension; ++i){
        base.vtable->add(
            v1_data + i*base.vtable->size, 
            v2_data + i*base.vtable->size, 
            res_data + i*base.vtable->size
        );
    }
    return OK;
}
Linear_form_errors vector_dot(Vector* vec1, Vector* vec2, Number* result){
    if(!vec1 || !vec2 || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    if(!vec1->base.vtable->add || !vec1->base.vtable->mulitply) return OPERATION_NOT_DEFINED;
    if(vec1->base.vtable != vec2->base.vtable && vec1->base.vtable != result->vtable) return DIFFERENT_TYPES_OF_LFORM;
    if(vec1->dimension != vec2->dimension) return DIFFERENT_SIZES_OF_LFORM;
    


    // Number base1 = vec1->base;
    Number base = *(Number*)&vec1->base;

    char* v1_data = (char*)vec1->data;
    char* v2_data = (char*)vec2->data;
    void* sum = malloc(base.vtable->size);
    for(size_t i = 0; i < vec1->dimension; ++i){
        base.vtable->mulitply (
                v1_data + i*base.vtable->size, 
                v2_data + i*base.vtable->size,
                sum
            );
        base.vtable->add(
            result,
            sum,
            result
        );
    }
    return OK;
}

Linear_form_errors vector_scale(Vector* vec, Number* scalar, Vector* result){
    if(!vec || !scalar || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    if(!vec->base.vtable->mulitply) return OPERATION_NOT_DEFINED;
    if(vec->base.vtable != result->base.vtable || vec->base.vtable != scalar->vtable) return DIFFERENT_TYPES_OF_LFORM;
    if(vec->dimension != result->dimension) return DIFFERENT_SIZES_OF_LFORM;
    
    Number base = *(Number*)&vec->base;

    char* vec_data = (char*)vec->data;
    char* res_data = (char*)result->data;
    for(size_t i = 0; i < vec->dimension; ++i){
        base.vtable->mulitply(
            vec_data + i*base.vtable->size, 
            scalar, 
            res_data + i*base.vtable->size
        );
    }
    return OK;
}

Vector* create_vector(Number base, void* data, size_t dimension){
    Vector* new_vec = malloc(sizeof(Vector));

    new_vec->base.vtable = base.vtable;
    new_vec->dimension = dimension;
    new_vec->data = data;

    return new_vec;
}

void free_vector(Vector* vec){
    for(size_t i = 0; i < vec->dimension; ++i) 
        free((char*)vec->data + i*vec->base.vtable->size);
    free(vec);
}