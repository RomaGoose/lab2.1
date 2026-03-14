#include <stdlib.h>

#include "result_internal.h"


Result* err(Error_code err_code){
    Result* error = malloc(sizeof(Result));
    error->type = ERROR;
    error->data.err_code = err_code;
    return error;
}
Result* ok(void* value){
    Result* res = malloc(sizeof(Result));
    res->type = OK;
    res->data.value = value;
    return res;
}
void* unwrap(Result* res){
    if (res->type == ERROR) abort();
    return res->data.value;
}
Error_code get_err(Result* res){
    if (res->type == OK) abort();
    return res->data.err_code;
}
