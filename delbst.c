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
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    int choice, val;
    printf("--- Binary Search Tree ---\n");
    printf("Enter values for BST. Enter -1 to stop.\n");
    while (1)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        if (val == -1)
            break;
        root = insert(root, val);
    }
    printf("\nCurrent Inorder sequence: ");
    inorder(root);
    printf("\n");
    printf("\nEnter target value to delete: ");
    scanf("%d", &val);
    root = deleteNode(root, val);
    printf("Inorder sequence after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}