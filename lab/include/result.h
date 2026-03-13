typedef struct _Result Result;

Result* err(char* err_msg);
Result* ok(void* value);

void* unwrap(Result* res);