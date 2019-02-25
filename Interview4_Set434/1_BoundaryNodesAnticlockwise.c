//Boundary Traversal of binary tree
//https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
//Bacially we need to print left most path and right most path nodes along with leaf node in anticlockwise direction.
//print left path from using iteration from root exept the leaf node. 
//then print leaf nodes, first left leaf and then right leaf. 
//recursively print right most path except the leaf and root node.

#include "../../../COMMON/common.h"

typedef struct node
{
    int data;
    struct node *left, *right;
}TREE;

TREE *NewNode(int data)
{
    TREE *temp = malloc(sizeof(TREE));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

//print all nodes in left path except the left leaf
void PrintLeftPath(TREE *root)
{
    TREE *temp = root;
    while(temp && temp->left)
    {
        printf("%d ", temp->data);
        temp = temp->left;
    }
    return;
}

void PrintLeafNodes(TREE *root)
{
    if(root)
    {
        if(!root->left && !root->right)
            printf("%d ", root->data);

        PrintLeafNodes(root->left);
        PrintLeafNodes(root->right);
    }
    return;
}
void PrintRightPath(TREE *root)
{
    if(root && (root->right))
    {
        PrintRightPath(root->right);
        printf("%d ", root->data);
    }
    return;
}

void PrintBoudaryNodes(TREE *root)
{
    PrintLeftPath(root);
    PrintLeafNodes(root);
    PrintRightPath(root->right);
    printf("\n");
    return;
}

int main()
{
    TREE *root = NewNode(20);
    root->left = NewNode(8);;
    root->right = NewNode(22);
    root->right->right = NewNode(25);
    root->left->left = NewNode(4);
    root->left->right = NewNode(12);
    root->left->right->left = NewNode(10);
    root->left->right->right = NewNode(14);

    PrintBoudaryNodes(root);
    return 0;
}
