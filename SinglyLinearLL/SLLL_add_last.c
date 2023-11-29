#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create_node(int data);
void display();
void add_last(int data);
void add_first(int data);

int main()
{
    add_first(10);
    add_first(20);
    display();
    add_last(40);
    add_last(50);
    display();
    
   return 0;
}

struct node *create_node(int data)
{
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Malloc is failed !!\n");
    }
    else
    {
        ptr->data=data;
        ptr->next=NULL;
    }
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

void add_last(int data)
{
    struct node *ptr=create_node(data);
    if(head==NULL)
    {
        head=ptr;
    }
    else{
        struct node *trav= head;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next=ptr;
    }

}
void display()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else{
        struct node *trav=head;
        printf("Head");
        while(trav!=NULL)
        {
            printf("->%d",trav->data);
            trav=trav->next;
        }
    }
    printf("\n");
}