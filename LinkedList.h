#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node * next;
} Node;

typedef struct {
    Node * head;
    Node * last;
    int size;
} LinkedList;

Node * insert(LinkedList * list,Node * after, int data);
void removeNode(LinkedList * list, Node * node);
Node * find(LinkedList * list, int data);
void clear(LinkedList * list);
void printList(LinkedList * list);

#endif