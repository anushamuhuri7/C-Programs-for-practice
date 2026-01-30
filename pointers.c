#include <stdio.h>
#include <stdlib.h>

struct LL {
    int item;
    struct LL *link;
};

struct LL *add_node_front(struct LL *fst, int ins) {
    
    struct LL *n1 = malloc(sizeof(struct LL));
    if (n1 == NULL) {
        printf("Memory allocation failed!\n");
        return fst;
    }

    n1->item = ins;
    
    // The new node's link should point to the current 'first' node
    n1->link = fst; 
    
    printf("Node added with value %d\n", ins);
    
    // The new node is now the front of the list
    return n1;
}

int main() {
    // Crucial: Initialize to NULL
    struct LL *front = NULL; 

    // Adding nodes
    front = add_node_front(front, 5);
    front = add_node_front(front, 10);

    // Let's print to verify
    printf("Front item is: %d\n", front->item);

    return 0;
}