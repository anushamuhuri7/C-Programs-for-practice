#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data ;
    struct linked_list *next;
}node ;

node *temp,*ttemp,*p,*first,*q;
