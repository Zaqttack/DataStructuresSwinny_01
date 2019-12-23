#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList * list = (LinkedList*)malloc(sizeof(LinkedList));
    
    insert(list, NULL, 1);
    insert(list, NULL, 3);
    insert(list, NULL, 4);
    insert(list, NULL, 6);
    printList(list);

    insert(list, list->head, 2);
    printList(list);

    insert(list, find(list, 4), 5);
    printList(list);

    Node * node69 = insert(list, NULL, 69);
    printList(list);
    removeNode(list, node69);
    printList(list);

    return 0;
}