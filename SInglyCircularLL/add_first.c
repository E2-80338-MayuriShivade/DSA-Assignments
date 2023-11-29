#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

};

struct node *head=NULL;
void add_first();
struct node *create_node(int data);
void display();
void delete_first();
void delete_last();

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    display();
    delete_first();
    delete_last();
    display();
    return 0;
}

struct node *create_node(int data)
{
    struct node *new_node =(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Malloc is failed\n");
    }
    else
    {
        new_node->data=data;
        new_node->next=NULL;

    }
    return new_node;
}

void add_first(int data)
{
    struct node *new_node = create_node(data);
    if(head==NULL)
    {
       head=new_node;
       new_node->next = head;
    }
    else{
        struct node *trav=head;
        while(trav->next != head)
        {
            trav=trav->next;
        }
        new_node->next=head;
        head=new_node;
        trav->next = head;
    }
}

void delete_first()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *trav=head;
        while(trav->next!=head)
        {
            trav=trav->next;
        }
        //store the address of 1st node
        struct node *temp=head;
        head =head->next;
        trav->next=head;
        free(temp);
        temp=NULL;
    }
}

void delete_last()
{
    if(head==NULL)
    {
        printf("List is Empty!\n");
    }
    else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else{
        struct node *trav=head;
        while(trav->next->next!=head)
        {
            trav=trav->next;
        } 
        free(trav->next);
        trav->next=head;
    }

}

void display()
{
    if(head==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        struct node *trav= head;
        printf("Head");
        do{
            printf("->%d",trav->data);
            trav=trav->next;
        }while(trav!=head);
        printf("\n");
    }
}

