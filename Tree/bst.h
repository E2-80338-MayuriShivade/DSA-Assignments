#ifndef _BST_H
#define _BST_H
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef struct bst
{
    node_t *root;

}bst_t;

void init_bst(bst_t *bst);
int is_empty(bst_t *bst);

node_t *create_node(int data);
void add_node_bst(bst_t *bst,int data);

void postorder(node_t *trav);
void inorder(node_t *bst);
void preorder(node_t *trav);

node_t *search_node(bst_t *bst,int key);


#endif