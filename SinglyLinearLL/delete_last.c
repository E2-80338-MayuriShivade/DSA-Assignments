#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

};
struct node *head=NULL;
struct node* create_node(int data);
void add_first(int data);
void display();
void delete_last();
void free_list();
int count_nodes();
void delete_first();
void delete_at_specific(int pos);

int main(){
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(50);
    add_first(60);
    add_first(70);
    display();
    delete_last();
    display();
    //free_list();
    delete_first();
    display();
    delete_at_specific(2);
    display();
    return 0;
}

struct node* create_node(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
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

void display()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    struct node *trav=head;
    printf("Head");
    while(trav!=NULL)
    {
        printf("->%d",trav->data);
        trav=trav->next;
    }
    printf("\n");
}

void delete_last()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else if(head->next==NULL)    //for single node
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *trav=head;
        while(trav->next->next != NULL)
        {
            trav=trav->next;
        }
        free(trav->next);
        trav->next=NULL;
    }
}

void free_list()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        struct node *trav=head;
        struct node *temp=NULL;
        do{
            temp=trav;
            trav=trav->next;
            free(temp);
        }while(trav!=NULL);
         head=NULL;
        temp=NULL; 
    }
    printf("List is free now!\n");
}

int count_nodes()
{
    int count = 0;
    if(head==NULL)
       printf("List is empty!\n");
    else
    {
        struct node *trav=head;

        while(trav!=NULL)
        {
            count++;
            trav=trav->next;
        }
    }   return count;
}

void delete_at_specific(int pos)
{
  if(head==NULL)
     printf("List is empty!\n");
  else if(pos==1)
     delete_first();
  else if(pos==count_nodes())
      delete_last();
  else if(pos < 1 || pos>count_nodes())
      printf("Invalid position\n");
  else
  {
    struct node *trav=head;

    for(int i = 1;i<pos;i++)
    {
        trav = trav->next;
    }
    struct node *temp = trav->next;
    trav->next=temp->next;
    //trav->next=trav->next->next;
    free(temp);
    temp=NULL;
  }           
    
}

void delete_first()
{
    if(head==NULL)
    {
        printf("List is empty!");
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
        temp = NULL;
    }
}


