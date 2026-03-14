#include <string.h>
#include <stdio.h>

#include "vector_internal.h"
#include "linear_form.h"
#include "linear_form_internal.h"

#include "result.h"

Result* vector_get_elem(Vector* vec, size_t index){
    if (vec == NULL) return err(NULL_POINTER);
    if (index >= vec->dimension || index < 0) return err(INDEX_OUT_OF_RANGE);

    return ok((char*)vec->data + index*vec->base->size);
};
Result* vector_set_elem(Vector* vec, size_t index, Scalar* elem){
    if (vec == NULL || elem == NULL) return err(NULL_POINTER);
    if (index >= vec->dimension || index < 0) return err(INDEX_OUT_OF_RANGE);
    if (vec->base != elem->vtable) return err(INCOMPATABLE_TYPES);

    memcpy((char*)vec->data + index*vec->base->size, elem->value, elem->vtable->size);

    return ok(NULL);
};
// Result* vector_copy_from(Vector* vec);
// Result* vector_copy_to(Vector* vec, Vtable* base, void* data, size_t dimension);

Result* vector_add(Vector* vec1, Vector* vec2){    
    if(!vec1 || !vec2) return err(NULL_POINTER);
    if(!vec1->base->add) return err(OPERATION_NOT_DEFINED);
    if(vec1->base != vec2->base) return err(INCOMPATABLE_TYPES);
    if(vec1->dimension != vec2->dimension) return err(INCOMPATABLE_SIZES);
    
    Vector* result = create_empty_vector(vec1->base, vec1->dimension);

    Vtable base = *(Vtable*)vec1->base;

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
    return ok(result);
}
Result* vector_dot(Vector* vec1, Vector* vec2){
    if(!vec1 || !vec2) return err(NULL_POINTER);
    if(!vec1->base->add) return err(OPERATION_NOT_DEFINED);
    if(vec1->base != vec2->base) return err(INCOMPATABLE_TYPES);
    if(vec1->dimension != vec2->dimension) return err(INCOMPATABLE_SIZES);
    
    Scalar* result = create_null_scalar(vec1->base);

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
    return ok(result);
}

Result* vector_scale(Vector* vec, Scalar* scalar){
    if(!vec || !scalar) return err(NULL_POINTER);
    if(!vec->base->add) return err(OPERATION_NOT_DEFINED);
    if(vec->base != scalar->vtable) return err(INCOMPATABLE_TYPES);

    Vector* result = create_empty_vector(vec->base, vec->dimension);
    
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
    return ok(result);
}

Result* vector_to_string(Vector* vec){
    if (!vec || !vec->base || !vec->data) return err(NULL_POINTER);
    size_t elements_string_size = 0;
    size_t element_size = 0;

    char** buffers = calloc(vec->dimension, sizeof(char*));
    for(size_t i = 0; i < vec->dimension; ++i){
        element_size = vec->base->to_string(NULL, 0, unwrap(vector_get_elem(vec,  i))) + 1;
        buffers[i]=calloc(element_size, sizeof(char));
        vec->base->to_string(buffers[i], element_size, unwrap(vector_get_elem(vec, i)));
        elements_string_size += element_size - 1;
    }

    size_t buff_size = strlen(VECTOR_STR_START VECTOR_STR_END) + 
                       strlen(", ") * (vec->dimension - 1) + 
                       elements_string_size + 1;
    char* buff = calloc(buff_size, 1);
    
    strcat(buff, VECTOR_STR_START);
    for(size_t i = 0; i < vec->dimension - 1; ++i){
        strcat(buff, buffers[i]);
        strcat(buff, VECTOR_STR_SEP);
        free(buffers[i]);
    }
    strcat(buff, buffers[vec->dimension-1]);
    strcat(buff, VECTOR_STR_END);
    free(buffers);

    return ok(buff);
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

int vector_eq(Vector* vec1, Vector* vec2){
    if(vec1->base!=vec2->base || vec1->dimension != vec2->dimension) return 0;

    char* data1 = vec1->data;
    char* data2 = vec2->data;
    size_t size = vec1->base->size;
    for (size_t i = 0; i < vec1->dimension; ++i){
        if(strncmp(data1 + i*size, data2 + i*size, size) != 0) 
            return 0;
    }
    return 1;
}

Vector* create_empty_vector(Vtable* base, size_t dimension){
    Vector* new_vec = malloc(sizeof(Vector));

    new_vec->base = base;
    new_vec->dimension = dimension;

    new_vec->data = calloc(dimension, base->size);

    return new_vec;
}

void free_vector(Vector* vec){
    free(vec->data);
    free(vec);
}