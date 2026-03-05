#pragma ocne 

#include <stdlib.h>

typedef void (*binary_operation)(void* left, void* right, void* result); 

typedef struct {
    size_t size;
    binary_operation add;
    binary_operation mulitply;
    void (*print)(void* value);
} Vtable;

typedef struct _Number{
    Vtable* vtable;    
}Number;