//
// Created by gigakox on 3/10/2023.
//

#include "HouseType.h"

House* createHouse(int value) {
    House* newHouse = (House*) malloc(sizeof (House));
    newHouse->value = value;
    newHouse->name = (char *)malloc(MAX_BUFFER_SIZE);
    printf("Choose name for the house\n");
    scanf("%s",newHouse->name);
    return newHouse;
}

bool compareHouse(void* a, void* b) {
    return ((House*)a)->value < ((House*)b)->value;
}

void deleteHouse(void* a) {
    free(((House*)a)->name);
    free(((House*)a));
}

void printHouse(void* a) {
    printf("\nHouse name: %s\nHouse value: %d\n", ((House*)a)->name, ((House*)a)->value);
}
