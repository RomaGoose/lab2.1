#include "_assert.h"
#include "mock_abort.h"

static int succes_count = 0;
static int fail_count = 0;


int assert_fail(const char* expr, const char* file, size_t line) {
    fprintf(stderr, "%s:%llu:\t %s FAILED \n", file, line, expr);
    ++fail_count;
    return 0;
}
int assert_success(const char* expr, const char* file, size_t line) {
    fprintf(stderr, "%s:%llu:\t %s PASSED \n", file, line, expr);
    ++succes_count;
    return 0;
}

int get_fail_count(){
    return fail_count;
}

void print_stats(){
    if(succes_count + fail_count > 0)
        fprintf(stderr, "%d tests out of %d succeeded. %f%%  SUCCEED \n", 
            succes_count, succes_count + fail_count, succes_count/(succes_count + fail_count)*100.0);
    else
        fputs("No tests were ran", stderr);
}
