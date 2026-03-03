#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list{
    int data;
    struct linked_list *next;
}node;
node *temp,*first,*ttemp,*p,*q;

void create_first(int value)
{
    first=(node*)malloc(sizeof (node));
    first->data=value;
    first->next=NULL;
}
void add_nodes(int value)
{
    temp=first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    ttemp=(node*)malloc(sizeof (node));
    ttemp->data=value;
    ttemp->next=NULL;
    temp->next=ttemp;
}
void delete_before(int b)
{
    temp=first;
    while(temp->next->data!=b)
    {
        p=temp;
        temp=temp->next;
    }
    q=temp->next;
    p->next=q;
    temp->next=NULL;
    free(temp);

}
void display()
{
    temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int b;
    printf("Enter the number of nodes you want to create\n");
    int n;
    scanf("%d",&n);
    printf("Enter the data for node 1\n");
    int value;
    scanf("%d",&value);
    create_first(value);
    for(int i=2;i<=n;i++)
    {
        printf("Enter the data for node %d\n",i);
        scanf("%d",&value);
        add_nodes(value);
    }
    display();

    printf("Enter the data from before which you want to delete\n");
    scanf("%d",&b);

    printf("Update linked list is \n\n");
    delete_before(b);
    display();
    return 0;
}
