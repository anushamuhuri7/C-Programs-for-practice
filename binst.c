#include <stdio.h>
#include <stdlib.h>

void lookup(struct node *root, int target)
{
    if (root == NULL)
        return;
    if (root->data == target)
    {
        printf("Found\n");
        return;
    }
    lookup(root->left, target);
    lookup(root->right, target);
}