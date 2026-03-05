#include "number.h"

typedef struct {
    Number base;
    int value;
}Int;

void int_add(void* left, void* right, void* result);
void int_multiply(void* left, void* right, void* result);
void int_print(void* value);
Number* get_int_base();