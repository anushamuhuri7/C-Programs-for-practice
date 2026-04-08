#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insert(struct node *root)
{
    printf("Enter value to insert: ");
    int value;
    scanf("%d", &value);
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
    {
        root->left = insert(root->left);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right);
    }
    return root;
}
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

int main()
{
    struct node *root = NULL;
    printf("Create Binary Tree: ");
    root = insert(root);
    return 0;
}