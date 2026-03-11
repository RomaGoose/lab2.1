#include <stdlib.h>

#include "testing.h"
#include "_assert.h"

static Test* first_test_ptr = NULL;

void register_test(char* test_name, void (*test)()){
    Test* new = malloc(sizeof(Test));
    new->test = test;
    new->name = test_name;
    if(first_test_ptr == NULL){
        first_test_ptr = new;
        new->next = NULL;
        return;
    }
    new->next = first_test_ptr;
    first_test_ptr = new;
}

void run_tests(){
    for(Test* test = first_test_ptr; test!= NULL; test = test->next){
        test->test();
    }
    print_stats();
}