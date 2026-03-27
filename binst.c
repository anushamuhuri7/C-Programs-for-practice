#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void lookup1(struct node *root, int target)
{
    if (root == NULL)
        return;
    if (root->data == target)
    {
        printf("Found\n");
        return;
    }
    lookup1(root->left, target);
    lookup1(root->right, target);
}
void lookup2(struct node *root, int target)
{
    while (root != NULL)
    {
        if (root->data == target)
        {
            printf("Found\n");
            return;
        }
        if (root->data > target)
            root = root->left;
        else
            root = root->right;
    }
    printf("Not Found\n");
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}