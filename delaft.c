#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node *temp, *ttemp, *p, *first, *q;
void create_first(int value)
{
    first = (node *)malloc(sizeof(node));
    first->data = value;
    first->next = NULL;
}
void add_nodes(int value)
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = value;
    ttemp->next = NULL;
    temp->next = ttemp;
}
void delete_after(int a)
{
    temp = first;
    while (temp->data != a)
    {
        temp = temp->next;
    }
    p = temp->next;
    q = p->next;
    temp->next = q;
    p->next = NULL;
}
void display()
{
    temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int x;
    int a;
    printf("Enter the number of nodes you want to create\n ");
    scanf("%d", &x);
    printf("Enter the value of first node\n ");
    scanf("%d", &a);
    create_first(a);
    for (int i = 1; i < x; i++)
    {
        printf("Enter the value of node %d\n ", i + 1);
        scanf("%d", &a);
        add_nodes(a);
    }
    printf("Enter the value where you want to delete after\n ");
    scanf("%d", &a); // after value = a

    delete_after(a);
    display();

    return 0;
}