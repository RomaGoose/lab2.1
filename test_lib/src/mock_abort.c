
static int abort_called = 0;
static int old_abort_called = 0;

int abort_check(){
    if (abort_called != old_abort_called) {
        int ret = abort_called - old_abort_called;
        old_abort_called = abort_called;
        return ret;
    }
    return 0;
}

void __wrap_abort(){
    abort_called++;
}