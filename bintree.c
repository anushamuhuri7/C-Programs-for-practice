#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *createnode(char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
int cnt_leaves(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return cnt_leaves(root->left) + cnt_leaves(root->right) + 1;
}
int main()
{
    struct node *root = createnode('A');
    root->left = createnode('B');
    root->right = createnode('C');
    root->left->left = createnode('D');
    root->left->right = createnode('E');
    root->right->left = createnode('F');
    root->right->right = createnode('G');
    root->right->right->left = createnode('L');
    root->right->right->right = createnode('M');
    root->left->left->left = createnode('H');
    root->left->left->right = createnode('I');
    root->left->right->left = createnode('J');
    root->left->right->right = createnode('K');
    root->left->left->left->left = createnode('N');
    root->left->left->left->right = createnode('O');
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nNumber of leaves: %d\n", cnt_leaves(root));
    return 0;
}
