#include "../../src/result/result_internal.h"
#include "result.h"
#include "testing.h"
#include "mock_abort.h"

#include <string.h>

TEST(result_err){
    char* err_msg = "error message";
    Result* err_res = err(err_msg);

    assert(err_res->type == ERROR);
    assert(err_res->data.err_msg == err_msg);
    assert(strncmp(err_res->data.err_msg, err_msg, strlen(err_msg))==0);

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
    
    Result* err_res = err("abort me");

    expect_abort();

    free(err_res);
}