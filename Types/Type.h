#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>
typedef bool (*compare)(void*, void*);
typedef void (*delete)(void*);
typedef void (*print)(void*);

typedef struct Type {
    compare CompareFunc;
    delete DeleteFunc;
    print PrintFunc;
} Type;

#endif //TYPE_H
