#pragma once

#include "result.h"

typedef enum {
    OK, 
    ERROR
} res_type;

typedef struct _Result{
    res_type type;
    union {
        void* value;
        Error_code err_code;
    }data;
} Result;
