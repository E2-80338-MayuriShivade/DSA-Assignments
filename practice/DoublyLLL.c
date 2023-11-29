#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node *create_node(int data);
void forward_display();
void backward_display();
void add_first(int data);
void delete_last();
void delete_first();
void add_last(int data);

int main()
{
    add_first(50);
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(10);
    delete_first();
    forward_display();
    backward_display();

    return 0;
}

struct node *create_node(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Malloc is failed");
    }
    else{
        ptr->data=data;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    return ptr;
}

void forward_display()
{
   if(head==NULL)
   {
    printf("List is empty");
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

void backward_display()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else 
    {
        struct node *trav=tail;
        printf("Tail");
        while(trav!=NULL)
        {
            printf("->%1d",trav->data);
            trav=trav->prev;
        }
        printf("\n");
    }
}
void add_first(int data)
{
    struct node *ptr=create_node(data);
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else
    {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}

void delete_first()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
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
    tail=ptr;
   }
   else
   {
    tail->next=ptr;
    ptr->prev=tail;
    tail=ptr;
   }

}


