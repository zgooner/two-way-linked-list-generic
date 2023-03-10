//
// Created by gigakox on 3/10/2023.
//

#include "List.h"

list_t* createNode() {
    list_t* node = (list_t*) malloc(sizeof(list_t));
    node->next = NULL;
    node->previous = NULL;
    node->value = NULL;

    return node;
}

list_t* cloneNode(list_t* node) {
    list_t* newNode = (list_t *) malloc(sizeof(list_t));
    newNode->next = node->next;
    newNode->previous = node->previous;
    newNode->value = node->value;

    return newNode;
};

void insertNode(list_t* head, void* value, bool (*compare)(void*, void*) ) {
    if (head == NULL) {
        head = createNode();
        head->value = value;
        return;
    };
    if (head->value == NULL) {
        head->value = value;
        return;
    }

    list_t* newNode;
    list_t *end;

    while(head != NULL) {
        end = head; // Magic way to save end of list after while loop
        if((*compare)(value, end->value)) {
            newNode = cloneNode(end);

            newNode->value = end->value;
            end->value = value;

            end->next = newNode;
            newNode->previous = end;
            if (newNode->next != NULL) newNode->next->previous = newNode;

            return;
        } else head = head->next;
    }

    newNode = createNode();
    end->next = newNode;
    newNode->previous = end;
    newNode->value = value;
};

bool removeNode(list_t** head, int index, void (*delete)(void*)) {
    list_t* temp;

    for (int i = 0; i < index; i++) {
        head = &(*head)->next;
        if ((*head) == NULL) return false;

    }
    if ((*head)->next != NULL && (*head)->previous != NULL) {
        temp = (*head);

        //Between nodes
        (*head)->previous->next = (*head)->next;
        (*head)->next->previous = (*head)->previous;
        head = &temp;

    } else if ((*head)->previous != NULL) {
        temp = (*head);

        // On the end of the list
        (*head)->previous->next = NULL;
        head = &temp;

    } else if ((*head)->next != NULL) {
        //Node is first and it is not the only element
        (*head) = (*head)->next;
        head = &(*head)->previous; // Changing pointer on pointer to delete head
    }

    (*delete)((*head)->value);
    free((*head));
    (*head) = NULL;

    return true;
}

void deleteList(list_t*head, void (*delete)(void*)) {
    if (head == NULL) return;

    while(head != NULL) {
        removeNode(&head, 0, delete);
    }
}


void printList(list_t* head, void (*print)(void*)) {
    if (head == NULL || head->value == NULL) return;

    do {
        (*print)(head->value);
        head = head->next;
    } while (head != NULL);
}