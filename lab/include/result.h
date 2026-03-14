#pragma once

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
Error_code get_err(Result* res);