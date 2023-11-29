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
void add_first(int data);
void delete_first();
void add_last(int data);
void delete_last();
void add_at_specific(int data,int pos);
void delete_at_specific(int pos);
int count_nodes();

int main()
{
    add_first(50);
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(10);
    display();
    delete_first();
    display();
    add_last(90);
    display();
    delete_last();
    display();
    add_at_specific(80,3);
    display();
    delete_at_specific(3);
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
        while(trav!=NULL)
        {
            printf("->%1d",trav->data);
            trav=trav->next;
        }
        
    }
    printf("\n");
}

void add_first(int data)
{
    struct node *ptr=create_node(data);
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
}

void delete_first()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        head=head->next;
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
    }
    else
    {
        struct node *trav=head;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next=ptr;

    }
}

void delete_last()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else if(head->next==NULL)
    {
       free(head);
       head=NULL;
    }
    else
    {
      struct node *trav=head;
      while(trav->next->next!=NULL)
      {
        trav=trav->next;
      }
      free(trav->next);
      trav->next=NULL;
    }
   
}

int count_nodes()
{
    int count=0;
    if(head==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        struct node *trav=head;
        while(trav!=NULL)
        {
            count++;
            trav=trav->next;
        }
    }
    return count;
}

void add_at_specific(int data,int pos)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(pos==1)
    {
        add_first(data);
    }
    else if(pos==count_nodes()+1)
    {
        add_last(data);
    }
    else if(pos<1 || pos > count_nodes()+1)
    {
        printf("Invalid position\n");
    }
    else
    {
       struct node *ptr=create_node(data);
       struct node *trav=head;
       for(int i=1;i<pos-1;i++)
       {
        trav=trav->next;
       }
       ptr->next=trav->next;
       trav->next=ptr;
    }
}

void delete_at_specific(int pos)
{
    if(head==NULL)
    {
        printf("List is empty");

    }
    else if(pos==1)
    {
        delete_first();
    }
    else if(pos==count_nodes())
    {
        delete_last();
    }
    else if(pos<1 || pos>count_nodes())
    {
        printf("Invalid position");
    }
    else{
        struct node *trav=head;
        
        for(int i=1;i<pos-1;i++)
        {
            trav=trav->next;
        }
        struct node *temp=trav->next;
        trav->next=trav->next->next;
        free(temp);
        temp=NULL;
    }
}
