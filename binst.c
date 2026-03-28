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
struct node *newNode()
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node: ");
    scanf("%d", &node->data); // Assuming the user will input an integer for
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main()
{
    struct node *root = NULL;
    /*root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(12);
    root->right->right = newNode(18);*/
    printf("Create Binary Tree:\n");
    root = newNode();

    int target = 7;
    printf("Using lookup1:\n");
    lookup1(root, target);

    printf("Using lookup2:\n");
    lookup2(root, target);

    return 0;
}