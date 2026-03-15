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
    void* v = res->data.value;
    free(res);
    return v;
}
Error_code unwrap_err(Result* res){
    if (res->type == OK) abort();
    Error_code ec = res->data.err_code;
    free(res); 
    return ec;
}
