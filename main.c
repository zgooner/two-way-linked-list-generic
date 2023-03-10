#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Utils/List.h"
#include "Types/Int/IntType.h"
#include "Utils/Constants.h"
#include "Types/House/HouseType.h"

int main() {
    char command[MAX_BUFFER_SIZE];
    list_t *head = createNode();
    int helperInt;
    House* helperHouse;

    printf("Welcome to simple program showing two-sided sorted list.\n Options: \n1. Create int list. \n2. Create complex list.\n");
    scanf("%s", command);
    if (strcmp("1", command) == 0) {
        while(true) {
            printf("\nInt list.\nOptions: \n1. Add element. \n2. Delete element.\n3. Print list.\n4. Exit\n");
            scanf("%s", command);
            if (strcmp("1", command) == 0) {
                printf("Insert number\n");
                scanf("%d", &helperInt);
                insertNode(head, (void *) helperInt, IntType.CompareFunc);
            } else if (strcmp("2", command) == 0) {
                printf("Insert index\n");
                scanf("%d", &helperInt);
                removeNode(&head, helperInt, IntType.DeleteFunc);
            } else if (strcmp("3", command) == 0) {
                printList(head, IntType.PrintFunc);
            } else if (strcmp("4", command) == 0) {
                deleteList(head, IntType.DeleteFunc);
                break;
            }
        }
    } else {
        while(true) {
            printf("\nComplex house list.\nOptions: \n1. Add element. \n2. Delete element.\n3. Print list.\n4. Exit\n");
            scanf("%s", command);
            if (strcmp("1", command) == 0) {
                printf("Insert value of the house\n");
                scanf("%d", &helperInt);
                helperHouse = createHouse(helperInt);
                insertNode(head, (void *) helperHouse, HouseType.CompareFunc);
            } else if (strcmp("2", command) == 0) {
                printf("Insert index\n");
                scanf("%d", &helperInt);
                removeNode(&head, helperInt, HouseType.DeleteFunc);
            } else if (strcmp("3", command) == 0) {
                printList(head, HouseType.PrintFunc);
            } else if (strcmp("4", command) == 0) {
                deleteList(head, HouseType.DeleteFunc);
                break;
            }
        }
    }

    return 0;
}
