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
struct LL *add_at_pos(struct LL *fst, int ins, int pos){      //adds at required position
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
struct LL *del_at_pos(struct LL *fst, int pos){             //deletes at required position
if(fst==NULL){
printf("List is empty can't delete\n");
return fst;
}
if(pos==0){
struct LL *temp=fst;
fst=fst->link;
temp=NULL;
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
struct LL *temp1=temp->link->link;
temp->link->link=NULL;
temp->link=temp1;
temp1=NULL;
return fst;
}
if(pos==-1){
struct LL *temp=fst;
while(temp->link->link!=NULL){
temp=temp->link;
}
temp->link=NULL;
return fst;
}
}
struct LL *add_by_val(struct LL *fst){                    //adds before or after a certain value
if(fst==NULL){
printf("List is empty\n");
return fst;
}
struct LL *temp=fst;
int key,c=-1;
printf("Enter the value to be searched for: ");
scanf("%d",&key);
while(temp!=NULL){
c++;
if(temp->item==key){
printf("Value found at %d position\n", c);
break;
}
else if(temp->link==NULL){
printf("Value not present\n");
return fst;
}
temp=temp->link;
}
int dat, ch;
printf("Enter the data for new node: ");
scanf("%d",&dat);
printf("Press 1 to add before press 2 to add after: ");
scanf("%d", &ch);
if(ch==1){
add_at_pos(fst, dat, c);
}
else if(ch==2){
add_at_pos(fst, dat, c+1);
}
else{
printf("Error\n");
}
return fst;
}
struct LL *del_by_val(struct LL *fst){                //deletes a certain node by searching for its value
if(fst==NULL){
printf("List is empty can't delete\n");
return fst;
}
struct LL *temp=fst;
int key,c=-1;
printf("Enter the value to be searched for: ");
scanf("%d",&key);
while(temp!=NULL){
c++;
if(temp->item==key){
printf("Value found at %d position\n", c);
break;
}
else if(temp->link==NULL){
printf("Value not present\n");
return fst;
}
temp=temp->link;
}
del_at_pos(fst, c);
printf("Value deleted\n");
return fst;
}
void display(struct LL *node){
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
printf("3. Delete from linked list\n");
printf("4.Delete from last position in linked list\n");
printf("5.Add to linked list by specific linked list\n");
printf("6.Delete from linked list by specific value\n");
printf("7. Print linked list\n");
printf("8. Exit the program\n");
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
case 3: printf("Enter the position to delete node from: ");
            scanf("%d", &pos);
            front=del_at_pos(front,pos);
            printf("Node deleted at position %d \n", pos);
            break;
case 4: front=del_at_pos(front,-1);
            printf("Node deleted at last position \n");
            break;
case 5: front=add_by_val(front); break;
case 6:front=del_by_val(front); break;
case 7: printf("Final list: ");
           display(front);
           break;
case 8: exit(0); break;
default: printf("INVALID INPUT!\n");
}
}
return 0;
}