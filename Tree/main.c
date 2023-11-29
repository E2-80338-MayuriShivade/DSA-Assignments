#include"bst.h"


int main(void)
{
    bst_t bst;
    init_bst(&bst);

    add_node_bst(&bst,8);
    add_node_bst(&bst,3);
    add_node_bst(&bst,10);
    add_node_bst(&bst,1);
    add_node_bst(&bst,6);
    add_node_bst(&bst,14);
    add_node_bst(&bst,4);
    add_node_bst(&bst,7);
    add_node_bst(&bst,13);

    printf("Preorder:  ");
    preorder(bst.root);
    printf("\n");

    printf("Inorder:   ");
    inorder(bst.root);
    printf("\n");

    printf("Postorder: ");
    postorder(bst.root);
    printf("\n");

    node_t *temp=search_node(&bst,15);
    if(temp!=NULL)
    {
        printf("%d key is found\n",temp->data);
    }
    else
    {
        printf("Key is not found\n");
    }
    return 0;
}