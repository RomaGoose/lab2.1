typedef enum {
    OK, 
    ERROR
} res_type;

typedef struct _Result{
    res_type type;
    union {
        void* value;
        char* err_msg;
    }data;
} Result;
