//
// Created by gigakox on 3/10/2023.
//

#include "IntType.h"
#include <stdio.h>

bool compareInt(void* a, void* b) {
    return (int*) a < (int*) b;
}

void printInt(void * a) {
    printf("%d ", (int *) a);
}

void deleteInt(void* a) {

}

