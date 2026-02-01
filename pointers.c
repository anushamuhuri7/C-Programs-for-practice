#include <stdio.h>
#include <stdlib.h>

struct LL {
    int item;
    struct LL *link;
};


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
    
   
    if (pos == 0) {
        newNode->link = fst;
        return newNode;
    }

    struct LL *temp = fst;
 
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->link;
    }

   
    if (temp == NULL) {
        printf("Position out of range. Node not added.\n");
        free(newNode);
        return fst;
    }

    newNode->link = temp->link; 
    temp->link = newNode;       
    
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

  
    front = add_at_pos(front, 10, 0); 
 
    front = add_at_pos(front, 5, 0);  

    front = add_at_pos(front, 20, 2); 

    front = add_at_pos(front, 15, 1); 

    printf("Final List: ");
    print_list(front);

    return 0;
}