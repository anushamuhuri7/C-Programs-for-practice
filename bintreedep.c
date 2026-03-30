#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int calcd(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int ldepth = calcd(root->left);
        int rdepth = calcd(root->right);
        if (ldepth > rdepth)
            return (ldepth + 1);
        else
            return (rdepth + 1);
    }
}