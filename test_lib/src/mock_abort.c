#include <stdio.h>


static int abort_called = 0;
static int old_abort_called = 0;
static int is_expected = 0;

int abort_check(){
    if (abort_called != old_abort_called) {
        int ret = abort_called - old_abort_called;
        old_abort_called = abort_called;
        return ret;
    }
    return 0;
}

void listen(){
    is_expected = 1;
}

void __real_abort();

void __wrap_abort(){
    if (is_expected){
        abort_called++;
        is_expected = 0;
    }
    else {
        fprintf(stderr, "ABORT called");
        __real_abort();
    }
}