#include <stdio.h>
#include <stdlib.h>

#include "linked-lists.h"

int main() {

    // allocate memory space for the head
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->val = 1;

    addNode(head, 10);    
    addNode(head, 12);    
    addNode(head, 14);    
    traverse(head);
    search(head, 12);
    replace(head, 4, 3);
    traverse(head);
    insert(head, 3, 45);
    traverse(head);
    deleteNode(head, 2);
    traverse(head);
    traverse(head);
    return 0;
}
