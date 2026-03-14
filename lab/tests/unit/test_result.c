#include "../../src/result/result_internal.h"
#include "result.h"
#include "testing.h"
#include "mock_abort.h"

#include <string.h>

TEST(result_err){
    
    Result* err_res = err(INDEX_OUT_OF_RANGE);

    assert_eq(err_res->type, ERROR);
    assert_eq(err_res->data.err_code, INDEX_OUT_OF_RANGE);
    assert_eq(err_res->data.err_code, INDEX_OUT_OF_RANGE);

    free(err_res);
}
TEST(result_ok){
    int v = 123;

    Result* ok_res = ok(&v);

    assert(ok_res->type == OK);
    assert(ok_res->data.value == &v);
    assert(*(int*)(ok_res->data.value) == v);

    free(ok_res);
}
TEST(result_unwrap_ok){
    int v = 123;

    Result* ok_res = ok(&v);

    assert_eq(unwrap(ok_res), &v);

    free(ok_res);
}
TEST(result_unwrap_abort){
    
    Result* err_res = err(NULL_POINTER);

    expect_abort();

    free(err_res);
}
TEST(result_get_err_abort){
    
    Result* ok_res = ok(NULL);

    get_err(ok_res);

    expect_abort();

    free(ok_res);
}