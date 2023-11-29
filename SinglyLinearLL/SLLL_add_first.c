#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    
};

struct node *head=NULL;
struct node *create_node(int data);
void add_first(int data);
void display();


int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    display();
    
    return 0;
}
struct node *create_node(int data)
{
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
       printf("Malloc is failed!\n");
    }
    else
    {
       ptr->data=data;
       ptr->next=NULL;
    }
    return ptr;
      
}

void add_first(int data)
{
    struct node *ptr= create_node(data);
    //check if node is empty
    if(head==NULL)
    {
        head=ptr;
    }
    else{
        ptr->next=head;
        head = ptr;
    }
    
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else{
        struct node *trav = head;
        printf("Head");
        while(trav!=NULL)
        {
            printf("->%d",trav->data);
            trav=trav->next;
        }
    }
    printf("\n");
}