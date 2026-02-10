/*struct dll_node{
    struct dll_node *prev;
    struct dll_node *next;
    int data;
};*/
/*void fib(int n){
    int a,b,c;
    a=1;
    b=a+1;
    c=a+b;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int roll;
    float cgpa;
} stud;

struct dll_node {
    stud data;
    struct dll_node *next;
    struct dll_node *prev;
};

typedef struct dll_node node;
node *head = NULL;

void disp(node *h) {
    node *mover = h;
    int cnt = 0;
    if (h == NULL) {
        printf("Empty List\n");
        return; 
    }
    while (mover != NULL) {
        printf("Item %d: %s, Roll: %d, CGPA: %.2f\n", cnt++, mover->data.name, mover->data.roll, mover->data.cgpa);
        mover = mover->next;
    }
}

void add_node() {
node *new = (node*)malloc(sizeof(node));
new->data.name = (char*)malloc(50 * sizeof(char));
node *temp=head;
printf("Enter your name, roll and cgpa\n");
scanf("%s %d %f", new->data.name, &new->data.roll, &new->data.cgpa);
if (head == NULL) {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return;
    }
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=new;
new->prev=temp;
new->next=NULL;
temp=head->next->prev;
}

int main() {
  node *n1;
  n1=malloc(sizeof(node));
  n1->prev=n1->next=NULL;
   head=n1;
  n1->data.name="Anusha";
  n1->data.roll=1;
  n1->data.cgpa=9.51;
  
  add_node();
  disp(head);
  return 0;
}