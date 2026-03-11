#include "_assert.h"

static size_t succes_count = 0;
static size_t fail_count = 0;


static int assert_fail(const char* expr, const char* file, size_t line) {
    fprintf(stderr, "%s:%llu:\t %s FAILED \n", file, line, expr);
    ++fail_count;
    return 0;
}
static int assert_success(const char* expr, const char* file, size_t line) {
    fprintf(stderr, "%s:%llu:\t %s SUCCEED \n", file, line, expr);
    ++succes_count;
    return 0;
}

int get_fail_count(){
    return fail_count;
}

int print_stats(){
    if(fail_count != 0)
        fprintf(stderr, "%llu tests out of %llu succeeded. %f\%  SUCCEED \n", 
            succes_count, succes_count+fail_count, succes_count/(succes_count+fail_count)*100.0);
    else
        fputs("No tests were ran", stderr);
        return 0;
}
