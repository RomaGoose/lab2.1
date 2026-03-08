#include <string.h>

#include "vector_internal.h"
#include "linear_form.h"
#include "linear_form_internal.h"

Linear_form_errors vector_add(Vector* vec1, Vector* vec2, Vector* result){
    // if(!vec1 || !vec2 || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    // if(!vec1->base.vtable->add) return OPERATION_NOT_DEFINED;
    // if(vec1->base.vtable != vec2->base.vtable && vec1->base.vtable != result->base.vtable) return DIFFERENT_TYPES_OF_LFORM;
    // if(vec1->dimension != vec2->dimension && vec1->dimension != result->dimension) return DIFFERENT_SIZES_OF_LFORM;
    


    Vtable base = *(Vtable*)&vec1->base;

    char* v1_data = (char*)vec1->data;
    char* v2_data = (char*)vec2->data;
    char* res_data = (char*)result->data;
    for(size_t i = 0; i < vec1->dimension; ++i){
        base.add(
            v1_data + i*base.size, 
            v2_data + i*base.size, 
            res_data + i*base.size
        );
    }
    return OK;
}
Linear_form_errors vector_dot(Vector* vec1, Vector* vec2, Scalar* result){
    // if(!vec1 || !vec2 || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    // if(!vec1->base.vtable->add || !vec1->base.vtable->mulitply) return OPERATION_NOT_DEFINED;
    // if(vec1->base.vtable != vec2->base.vtable && vec1->base.vtable != result->vtable) return DIFFERENT_TYPES_OF_LFORM;
    // if(vec1->dimension != vec2->dimension) return DIFFERENT_SIZES_OF_LFORM;
    


    // Number base1 = vec1->base;
    Vtable base = *(Vtable*)vec1->base;

    char* v1_data = (char*)vec1->data;
    char* v2_data = (char*)vec2->data;
    void* sum = malloc(base.size);
    for(size_t i = 0; i < vec1->dimension; ++i){
        base.mulitply (
                v1_data + i*base.size, 
                v2_data + i*base.size,
                sum
            );
        base.add(
            result->value,
            sum,
            result->value
        );
    }
    return OK;
}

Linear_form_errors vector_scale(Vector* vec, Scalar* scalar, Vector* result){
    // if(!vec || !scalar || !result) return OPERANDS_OR_RESULT_NOT_FOUND;
    // if(!vec->base.vtable->mulitply) return OPERATION_NOT_DEFINED;
    // if(vec->base.vtable != result->base.vtable || vec->base.vtable != scalar->vtable) return DIFFERENT_TYPES_OF_LFORM;
    // if(vec->dimension != result->dimension) return DIFFERENT_SIZES_OF_LFORM;
    
    Vtable base = *(Vtable*)vec->base;

    char* vec_data = (char*)vec->data;
    char* res_data = (char*)result->data;
    for(size_t i = 0; i < vec->dimension; ++i){
        base.mulitply(
            vec_data + i*base.size, 
            scalar->value, 
            res_data + i*base.size
        );
    }
    return OK;
}

Vector* create_vector(Vtable* base, void* data, size_t dimension){
    Vector* new_vec = malloc(sizeof(Vector));

    new_vec->base = base;
    new_vec->dimension = dimension;

    size_t vec_size = base->size*dimension;
    new_vec->data = malloc(vec_size);
    memcpy(new_vec->data, data, vec_size);

    return new_vec;
}

void free_vector(Vector* vec){
    free(vec->data);
    free(vec);
}