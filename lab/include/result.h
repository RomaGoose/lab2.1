#pragma once

#define null_check(...) do {\
    void* ptrs[] = {__VA_ARGS__, (void*)1};\
    for (int i = 0; ptrs[i] != (void*)1; ++i)\
        if(!ptrs[i]) return err(NULL_POINTER);\
} while(0);

typedef enum {
    OK, 
    ERROR
} res_type;

typedef enum {
    NULL_POINTER,
    INCOMPATABLE_TYPES,
    INDEX_OUT_OF_RANGE,
    OPERATION_NOT_DEFINED,
    INCOMPATABLE_SIZES
} Error_code;

typedef struct _Result Result;

Result* err(Error_code err_code);
Result* ok(void* value);

void* unwrap(Result* res);
Error_code unwrap_err(Result* res);

res_type get_res_type(Result* res);