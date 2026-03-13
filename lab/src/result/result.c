#include <stdlib.h>

#include "result_internal.h"


Result* err(char* err_msg){
    Result* error = malloc(sizeof(Result));
    error->type = ERROR;
    error->data.err_msg = err_msg;
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
