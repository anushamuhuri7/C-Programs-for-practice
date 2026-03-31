#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node (-1 to stop): ");
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        free(temp);
        return NULL;
    }
    temp->data = data;
    printf("Enter left child of %d:\n", data);
    temp->left = newnode();
    printf("Enter right child of %d:\n", data);
    temp->right = newnode();
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
int main()
{
    struct node *root = NULL;
    printf("Creating binary tree\n");
    root = newnode();
    /*root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);*/
    printf("Height of tree is %d", calcd(root));
    return 0;
}