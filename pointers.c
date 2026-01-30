#include<stdio.h>
#include<stdlib.h>
struct LL{
int item;
struct LL *link;
};
struct LL *add_node_front(struct LL *fst,int ins){
if(fst==NULL){
struct LL *n1;
n1=malloc(sizeof(struct LL));
n1->item=ins;
n1->link=NULL;
printf("Node is added with value %d \n",ins );
return n1;
}
}
int main(){
 struct LL *front;
front=add_node_front(front,5);
return 0;
}