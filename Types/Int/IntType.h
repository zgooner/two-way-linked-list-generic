#ifndef INTTYPE_H
#define INTTYPE_H

#include "../Type.h"

bool compareInt(void* a, void* b);
void printInt(void * a);
void deleteInt(void* a);

static const Type IntType = {compareInt, deleteInt, printInt};

#endif //INTTYPE_H
