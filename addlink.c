#include<stdio.h>
#include<stdlib.h>
struct LL{
int item;
struct LL *link;
};
struct LL *create_node(int val){
struct LL *newNode=malloc(sizeof(struct LL));
if(newNode!=NULL){
newNode->item=val;
newNode->link=NULL;
}
return newNode;
}
struct LL *add_at_pos(struct LL *fst, int ins, int pos){
struct LL *newNode=create_node(ins);
if(pos==0){
newNode->link=fst;
return newNode;
}
if(pos==-1){
struct LL *temp=fst;
while(temp->link!=NULL){
temp=temp->link;
}
temp->link=newNode;
newNode->link=NULL;
return fst;
}
if(pos>0){
struct LL *temp=fst;
for(int i=0;i<(pos-1) && temp!=NULL;i++){
temp=temp->link;
}
if(temp==NULL){
printf("Position out of range\n");
return fst;
}
newNode->link=temp->link;
temp->link=newNode;
return fst;
}
}
void print_list(struct LL *node){
while(node!=NULL){
printf("%d-> ",node->item);
node=node->link;
}
printf("NULL\n");
}
int main(){
struct LL *front=NULL;
int choice, val, pos;
while(1){
printf("Choose an option:\n");
printf("1.Add to linked list\n");
printf("2.Add to last position in linked list\n");
printf("3. Print linked list\n");
printf("4. Exit the program\n");
printf("Enter choice:\n");
scanf("%d",&choice);
switch(choice){
case 1:  printf("Enter the value to add: ");
            scanf("%d", &val);
            printf("Enter the position to add in: ");
            scanf("%d", &pos);
            front=add_at_pos(front,val,pos);
            printf("%d added at position %d \n", val, pos);
            break;
case 2: printf("Enter the value to add: ");
           scanf("%d", &val);
           front=add_at_pos(front,val,-1);
           printf("%d added at last position\n", val);
           break;
case 3: printf("Final list: ");
           print_list(front);
           break;
case 4: exit(0); break;
default: printf("INVALID INPUT!\n");
}
}
return 0;
}
