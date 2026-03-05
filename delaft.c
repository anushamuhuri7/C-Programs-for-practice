#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data ;
    struct linked_list *next;
}node ;

node *temp,*ttemp,*p,*first,*q;
void create_first(int value)
{
    first=(node*)malloc(sizeof (node));
    first->data = value;
    first->next=NULL;
}
void add_nodes(int value)
{
    temp=first;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
}
