#include <stdio.h>
#include <stdlib.h>

struct LL {
    int item;
    struct LL *link;
};

// Helper function to create a new node
struct LL* create_node(int val) {
    struct LL *newNode = malloc(sizeof(struct LL));
    if (newNode != NULL) {
        newNode->item = val;
        newNode->link = NULL;
    }
    return newNode;
}

struct LL* add_at_pos(struct LL *fst, int ins, int pos) {
    struct LL *newNode = create_node(ins);
    
    // Case 1: Insert at the very beginning (Position 0)
    if (pos == 0) {
        newNode->link = fst;
        return newNode;
    }

    struct LL *temp = fst;
    // Move temp to the node at (pos - 1)
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->link;
    }

    // Case 2: Position is out of bounds (beyond the end of the list)
    if (temp == NULL) {
        printf("Position out of range. Node not added.\n");
        free(newNode);
        return fst;
    }

    // Case 3: Standard middle or end insertion
    newNode->link = temp->link; // Link new node to the rest of the list
    temp->link = newNode;       // Link previous node to the new node
    
    return fst;
}

void print_list(struct LL *node) {
    while (node != NULL) {
        printf("%d -> ", node->item);
        node = node->link;
    }
    printf("NULL\n");
}

int main() {
    struct LL *front = NULL;

    // 1. Add to empty list (Position 0)
    front = add_at_pos(front, 10, 0); 
    // 2. Add to front (Position 0)
    front = add_at_pos(front, 5, 0);  
    // 3. Add to end (Position 2)
    front = add_at_pos(front, 20, 2); 
    // 4. Add to middle (Position 1)
    front = add_at_pos(front, 15, 1); 

    printf("Final List: ");
    print_list(front);

    return 0;
}