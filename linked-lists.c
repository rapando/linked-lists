#include <stdio.h>
#include <stdlib.h>

#include "linked-lists.h"


// traverse:
// print all the values in the linked list until you reach the tail
// takes the head pointer as the parameter and uses it to get the next node
// this is repeated until we reach the end (tail)
void traverse(struct node *n) {
    printf("traverse\t");
    while (n) {
        printf("%d->", n->val);
        n = n->next;
    }
    printf("NULL\n\n");
}

// addNode
// takes in the head node and a value to be added to the end of the linked list.
// we use the traverse logic to reach the tail.
// we then allocate memory for the new node and attach it to the tail.
void addNode(struct node *n, int val) {
    printf("addNode\t\tadd %d to the end of linked list\n\n", val);
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->val = val;
   
    while (n) {
        if (n->next == NULL) {
            n->next = newNode;
            break;
        }
        n = n -> next;
    }
}

// search
// takes the head node and the value to be searched for
// traverses the linked list and if it finds a value equal to the passed parameter
// it prints it out.
// if the value being searched for is not found, it prints (invalid position)
// this is made possible by a 'found` variable that is 0 by default and is set
// to 1 when the value is found.
// the position variable holds the position of the current node,
// starting with 1 (head) and is incremented every time we move to the next node.
void search(struct node *n, int val) {
    printf("search\t\tsearch for %d in linked list :: ", val);
    int position = 1;
    int found = 0;
    while (n) {
        if (n->val == val) {
            found = 1;
            printf("Found at position %d!\n\n", position);
            break;
        }
        n = n->next;
        position++;
    }
    if (found == 0) {
        printf("%d not found!\n\n", val);
    }
}

// replace
// takes in the head, position to be replaced and the new value for the new node.
// this function uses the logic of traverse and search
// we always check for the position before the position we need to replace,
// this is basically the node to the left of the position we need to replace.
// we then replace the node to the right of the left node with the new node.
// we also need to set the address of the right of position to be newNode->next
void replace(struct node *n, int position, int newValue) {
    printf("replace\t\tposition: %d, new value: %d : ", position, newValue);
    int p = 1;
    int found = 0;
    while (n) {
        if (p == position - 1) {
            found = 1;
            // we are going to replace the next node
            struct node *newNode = (struct node *) malloc(sizeof(struct node));
            newNode -> val = newValue;
            newNode-> next = n->next->next;
            n->next = newNode;
            printf("replaced!\n\n");
            break;
        }
        n = n -> next;
        p++;
    }
    if (found == 0) {
        printf("Invalid position!\n\n");
    }
}

// deleteNode
// using the logic in replace, we can delete the next node.
void deleteNode(struct node *n, int position) {
    printf("delete\t\tposition %d :", position);
     if (position == 1) {
        printf("can't delete head.\n\n");
        return;
    }

    int p = 1;
    int found = 0;
    while(n) {
        if (p == position - 1) {
            found = 1;
            // we are going to delete the next node from memory
            // therefore we save it in a temporary variable
            struct node* nextNode = n->next;

            // we replace the pointer n->next with n->next->next,
            // we no longer have the address of n->next
            // that's why we saved it in `newNode`
            n->next = n->next->next;

            // we now delete nextNode from memory
            free(nextNode);
            printf("deleted!\n\n");
            break;
        }
        n = n->next;
        p++;
    }

    if (found == 0) {
        printf("Invalid position!\n\n");
    }
}

// insert
// insert a new node in the position given.
void insert(struct node *n, int position, int val) {
    printf("insert\t\tval : %d at position %d: ", val, position);
    if (position == 1) {
        printf("can't replace head\n\n");
        return;
    }
    int p = 1;
    int found = 0;

    while (n) {
        if (p == position - 1) {
            found = 1;

            // n is the node on the left
            // n->next is the node on the right
            // we need to place the new node in between
            struct node* newNode = (struct node*) malloc(sizeof(struct node));
            newNode->val = val;
            // we start by setting newNode->next to be the value of the rigth node
            newNode->next = n->next;
            // we then set the left node's next value to be the newNode
            n->next = newNode;
            printf("inserted!\n\n");
            break;
        }

        n = n->next;
        p++;
    }
    if (found == 0) {
        printf("Invalid position!\n\n");
    }
}

