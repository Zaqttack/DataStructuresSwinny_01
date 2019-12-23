#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

Node * insert(LinkedList * list, Node * after, int data) {
    if(after == NULL) after = list->last; //if null we will insert at the head of the list

    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(after == NULL) { //we are creating a new linked list
        newNode->next = NULL;
        list->head = newNode;
        list->last = newNode;
        list->size = 1;
    }
    else if(after->next == NULL) { //we are at the end of the list
        newNode->next = NULL;
        list->last = newNode;
        list->size++;

        after->next = newNode;
    }
    else { // we are somewhere in the middle
        list->size++;

        newNode->next = after->next;
        after->next = newNode;
    }

    return newNode;
}

void removeNode(LinkedList * list, Node * node) {
    //check if node is the first node
    if(list->head == node) {
        list->head = node->next;
        free(node);
        list->size--;
        return;
    }

    Node * iter = list->head;
    while(iter->next != NULL && iter->next != node) { //makes iter the node before "node"
        iter = iter->next;
    }

    if(iter == list->last) return; //the node we are removing is not in the list

    iter->next = node->next; //remove node from the list

    //check if node is the last node
    if(list->last == node) list->last = iter;

    //delete node from memory
    free(node);
    list->size--;
}

Node * find(LinkedList * list, int data) {
    Node * iter = list->head;
    while(iter != NULL && iter->data != data) {
        iter = iter->next;
    }
    return iter;
}

void clear(LinkedList * list) {

}

void printList(LinkedList * list) {
    Node * iter = list->head;
    while(iter != NULL) {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("NULL \n");
}