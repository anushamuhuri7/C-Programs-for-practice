#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *ptr;
}node;
node* newlist(node* head, int data[],int n){
    node* p;
    for(int i = 0; i<n;i++){
        if(head == NULL){
            p = head = (node*)malloc(sizeof(node));
            p->data = data[i];
            p->ptr = NULL;
        }
        else{
            p->ptr = (node*)malloc(sizeof(node));
            p->ptr->data = data[i];
            p = p->ptr;
            p->ptr = NULL;
        }
    }
    return head;
}
void print(node* head){
    node* p = head;
    for(;p != NULL; p=p->ptr){
        printf("data is: %d\n", p->data);
    }
}
int findmid(node* head){
    node* p = head;                       
    node* q = head;                        
    while(q != NULL && q->ptr != NULL){
        p = p->ptr;
        q = q->ptr->ptr;
    }
    return p->data;
}
int main(){
    node* head = NULL;
    printf("Enter the size of linked list: ");
    int size;
    scanf("%d", &size);
    int data[size];
    printf("Enter the elements in the linked list: ");
    for(int i=0;i<size;i++){
        scanf("%d", &data[i]);
    }
    head = newlist(head, data, size);
    int middle = findmid(head);
    printf("Middle element is %d\n\n",middle);
}