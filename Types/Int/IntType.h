//
// Created by gigakox on 3/10/2023.
//

#ifndef PRLAB1_INTTYPE_H
#define PRLAB1_INTTYPE_H

#include "../Type.h"

bool compareInt(void* a, void* b);
void printInt(void * a);
void deleteInt(void* a);

static const Type IntType = {compareInt, deleteInt, printInt};

#endif //PRLAB1_INTTYPE_H
