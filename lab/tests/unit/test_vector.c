#include "vector.h"
#include "integer.h"
#include "_float.h"
#include "testing.h"
#include "string.h"

TEST(add_vectors){
    int nul[5] = {0};
    int left[5] = {1,2,3,4,5};
    int right[5] = {6,7,8,9,10};
    int answer[5] = {7,9,11,13,15};
    
    Vector* left_v = create_vector(get_int_base(), left, 5);
    Vector* rigth_v = create_vector(get_int_base(), right, 5);

    Result* res = vector_add(left_v, rigth_v);


    Vector* res_v = (Vector*)unwrap(res);
    Vector* answer_v = create_vector(get_int_base(), answer, 5);
    
    Vector* fake1_v = create_vector(get_float_base(), nul, 5);
    Vector* fake2_v = create_vector(get_int_base(), nul, 3);
    Result* err1_v = (vector_add(left_v, fake1_v));
    Result* err2_v = (vector_add(left_v, fake2_v));

    assert(vector_eq(res_v, answer_v));
    assert_eq(get_err(err1_v), INCOMPATABLE_TYPES);
    assert_eq(get_err(err2_v), INCOMPATABLE_SIZES);


    free_vector(left_v);
    free_vector(rigth_v);
    free_vector(fake1_v);
    free_vector(fake2_v);
    free_vector(res_v);
    free_vector(answer_v);
}

TEST(vector_get_elem_ok){

    int vec_arr[3]={1,2,3};

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);

    Result* res1 = (vector_get_elem(vec, 0));;
    Result* res2 = (vector_get_elem(vec, 1));;
    Result* res3 = (vector_get_elem(vec, 2));;

    int get_elem_arr[3]={*(int*)unwrap(res1),
                         *(int*)unwrap(res2),
                         *(int*)unwrap(res3)};

    assert_eq(strncmp((char*)vec_arr, (char*)get_elem_arr, 3*sizeof(int)), 0);

    free(res1);
    free(res2);
    free(res3);
    free_vector(vec);
}
TEST(vector_get_elem_index_out){

    int vec_arr[3]={1,2,3};

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);

    Result* res1 = (vector_get_elem(vec, -1));
    Result* res2 = (vector_get_elem(vec, 5));

    assert_eq(get_err(res1), INDEX_OUT_OF_RANGE);
    assert_eq(get_err(res2), INDEX_OUT_OF_RANGE);

    free(res1);
    free(res2);
    free_vector(vec);
}
TEST(vector_get_elem_null){

    
    Result* res1 = (vector_get_elem(NULL, 0));

    assert_eq(get_err(res1), NULL_POINTER);

    free(res1);
}

TEST(vector_set_elem_ok){

    int vec_arr[3]={1,2,3};

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);
    Scalar* sc = create_scalar(get_int_base(), vec_arr+1);

    Result* res1 = (vector_set_elem(vec, 0, sc));
    
    assert_eq(*(int*)unwrap(vector_get_elem(vec, 0)), *(int*)vec_arr+1);

    free(res1);
    free_vector(vec);
}
TEST(vector_set_elem_incompat){

    int vec_arr[3]={1,2,3};
    float f = 0.0;

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);
    Scalar* sc = create_scalar(get_float_base(), &f);

    Result* res1 = (vector_set_elem(vec, 0, sc));
    
    assert_eq(get_err(res1), INCOMPATABLE_TYPES);

    free(res1);
    free_vector(vec);
}
TEST(vector_set_elem_index_out){

    int vec_arr[3]={1,2,3};

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);

    
    Scalar* sc = create_scalar(get_int_base(), vec_arr+1);

    Result* res1 = (vector_set_elem(vec, -1, sc));
    Result* res2 = (vector_set_elem(vec, 5, sc));

    assert_eq(get_err(res1), INDEX_OUT_OF_RANGE);
    assert_eq(get_err(res2), INDEX_OUT_OF_RANGE);

    free(res1);
    free(res2);
    free_vector(vec);
}
TEST(vector_set_elem_null){

    
    int vec_arr[3]={1,2,3};

    Vector* vec = create_vector(get_int_base(), vec_arr, 3);

    
    Scalar* sc = create_scalar(get_int_base(), vec_arr+1);
    
    Result* res1 = (vector_set_elem(NULL, 0, sc));
    Result* res2 = (vector_set_elem(vec, 0, NULL));

    assert_eq(get_err(res1), NULL_POINTER);
    assert_eq(get_err(res2), NULL_POINTER);

    free(res1);
    free(res2);
    free(vec);
}

TEST(vector_to_string_ok){

    int arr[5]={1,2,3,4,5};
    Vector* vec = create_vector(get_int_base(), arr, 5);
    Result* res = vector_to_string(vec);

    assert_eq(strcmp((char*)unwrap(res), "Vector: (1, 2, 3, 4, 5)"), 0);

    free_vector(vec);
    free(res);
}