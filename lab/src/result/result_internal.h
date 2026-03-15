#pragma once

#include "result.h"


typedef struct _Result{
    res_type type;
    union {
        void* value;
        Error_code err_code;
    }data;
} Result;
