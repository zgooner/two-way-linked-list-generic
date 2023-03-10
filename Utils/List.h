#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Types/Type.h"

typedef struct list_t {
    struct list_t* next;
    struct list_t* previous;
    void* value;
} list_t;

list_t* createNode();
list_t* cloneNode(list_t* node);
void insertNode(list_t* head, void* value, bool (*func)(void*, void*));
bool removeNode(list_t** head, int index, void (*delete)(void*));

void deleteList(list_t* head, void (*delete)(void*));
void printList(list_t* head, void (*print)(void*));

#endif //LIST_H
