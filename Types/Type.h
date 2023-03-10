//
// Created by gigakox on 3/10/2023.
//

#ifndef PRLAB1_TYPE_H
#define PRLAB1_TYPE_H

#include <stdbool.h>
typedef bool (*compare)(void*, void*);
typedef void (*delete)(void*);
typedef void (*print)(void*);

typedef struct Type {
    compare CompareFunc;
    delete DeleteFunc;
    print PrintFunc;
} Type;

#endif //PRLAB1_TYPE_H
