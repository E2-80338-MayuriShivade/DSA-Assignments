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
void delete_first();
void add_last(int data);
void delete_last();
void display();

int main()
{
    add_first(50);
    add_first(40);
    add_first(30);
    add_first(20);
    display();
    add_last(90);
    display();
    delete_first();
    display();
    delete_last();
    display();
    return 0;
}

struct node *create_node(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
       printf("Malloc is failed\n");
    }
    else
    {
       ptr->data=data;
       ptr->next=NULL;
    }
    return ptr;
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        struct node *trav=head;
        printf("Head");
        do{
            printf("->%1d",trav->data);
            trav=trav->next;
        }while(trav!=head);
    }
    printf("\n");
}

void add_first(int data)
{
    struct node *ptr=create_node(data);
    if(head==NULL)
    {
       head=ptr;
       ptr->next=head;
    }
    else
    {
      struct node *trav=head;
      while(trav->next!=head)
      {
        trav=trav->next;
      }
      ptr->next=head;
      head=ptr;
      trav->next=head;
    }
}

void delete_first()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==head)
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
        struct node *temp=head;
        head=head->next;
        trav->next=head;
        free(temp);
        temp=NULL;
    }
}

void add_last(int data)
{
    struct node *ptr=create_node(data);
    if(head==NULL)
    {
        head=ptr;
        ptr->next=head;
    }
    else
    {
        struct node *trav=head;
        while(trav->next!=head)
        {
            trav=trav->next;
        }
        trav->next=ptr;
        ptr->next=head;
    }
}
void delete_last()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *trav=head;
        while(trav->next->next!=head)
        {
            trav=trav->next;
        }
        free(trav->next);
        trav->next=head;
    }
}