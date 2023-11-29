#include"bst.h"

void init_bst(bst_t *bst)
{
    bst->root=NULL;
}

int is_empty(bst_t *bst)
{
    return bst->root==NULL;
}

node_t *search_node(bst_t *bst,int key)
{
    //start from root
    node_t *trav=bst->root;
    while(trav!=NULL)
    {
        if(key == trav->data)
        {
            return trav;
        }
        else if(key < trav->data)
        {
            trav=trav->left;
        }
        else{
            trav=trav->right;
        }
    }
    return NULL;
}