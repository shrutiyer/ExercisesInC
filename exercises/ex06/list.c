/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node *node_to_remove = *list;
    int val_to_remove = node_to_remove->val;

    if (node_to_remove == NULL) {
        return -1;
    }

    if (node_to_remove->next != NULL) {
        **list = *node_to_remove->next;
    }
    return val_to_remove;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *original_head = *list;
    Node *new_head = make_node(val, original_head);
    *list = new_head;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *next_node = *list;
    int nodes_removed = 0;

    while (next_node != NULL && next_node->next != NULL) {
        if (next_node->val == val) {
            next_node->val = next_node->next->val;
            next_node->next = next_node->next->next;
            nodes_removed += 1;
        }
        next_node = next_node->next;
    }
    return nodes_removed;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node *current_node = *list;
    Node *next_node = NULL;
    Node *prev_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *list = prev_node;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
