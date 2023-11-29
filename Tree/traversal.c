#include"bst.h"

void preorder(node_t *trav)
{
    if(trav==NULL)
     return;
    //visit current node
    printf("%-4d",trav->data);
    
    //go into into left node
    preorder(trav->left);

    //go into right node
    preorder(trav->right);
}

void inorder(node_t *trav)
{
    if(trav==NULL)
     return;
    //left node
    inorder(trav->left);

    //visit current node
    printf("%-4d",trav->data);

    //right node
    inorder(trav->right);
}

void postorder(node_t *trav)
{
    if(trav==NULL)
     return;
    //left node
    postorder(trav->left);

    //right node
    postorder(trav->right);

    //visit current node
    printf("%-4d",trav->data);
}

// void DFS_traversal(node_t *trav)
// {
    
// }