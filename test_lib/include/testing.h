#include <stdlib.h>

#include "_assert.h"

#define TEST(test_name)	\
    static void test_name##_test();	\
    static void __attribute__((constructor))    \
    __##test_name##_test() {	\
        register_test(#test_name, test_name##_test);    \
    }                                                   \
    static void test_name##_test()

#define TEST_ENTRY_POINT\
    int main(){\
        run_tests();\
        return get_fail_count();\
    }

    
typedef struct _Test Test;
    
typedef struct _Test {
    void (*test)();
    char* name;
    Test* next;
} Test;

void run_tests();
void register_test(char* test_name, void (*test)());


