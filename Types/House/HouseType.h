//
// Created by gigakox on 3/10/2023.
//

#ifndef PRLAB1_HOUSETYPE_H
#define PRLAB1_HOUSETYPE_H
#include <malloc.h>
#include <stdio.h>
#include "../Type.h"
#include "../../Utils/Constants.h"

typedef struct House {
    char* name;
    int value;
} House;

House* createHouse(int value);

bool compareHouse(void* a, void* b);
void deleteHouse(void* a);
void printHouse(void* a);

static const Type HouseType = {compareHouse, deleteHouse, printHouse};

#endif //PRLAB1_HOUSETYPE_H
