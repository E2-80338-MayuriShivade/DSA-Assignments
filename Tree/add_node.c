#include"bst.h"
#include<stdlib.h>

node_t *create_node(int data)
{
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    if(newnode != NULL)
    {
     newnode->data=data;
     newnode->left=NULL;
     newnode->right=NULL;   
    }
    return newnode;
}

void add_node_bst(bst_t *bst,int data)
{
    //create node
    node_t *newnode =create_node(data);
    //if tree is empty
    if(is_empty(bst))
    {
         bst->root=newnode;
    //add node into root itself
    }
    else
    {
        node_t *trav = bst->root;
        while(1)
        {
            if(data < trav->data)
            {
                if(trav->left==NULL)
                {
                    trav->left=newnode;
                    break;
                }
                else
                {
                    trav=trav->left;
                }
            }
            else
            {
                if(trav->right==NULL)
                {
                    trav->right=newnode;
                    break;
                }
                else
                {
                    trav=trav->right;
                }
            }
                 

        }
    }
}