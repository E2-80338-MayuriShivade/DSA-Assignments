#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *create_node(int data);
void display();
void add_first(int data);
void delete_first();


int main()
{
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(50);
    display();
    delete_first();
    display();
    return 0;
}

struct node *create_node(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
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
        printf("List is empty\n");
    }
    else
    {
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

void delete_first()
{
    if(head==NULL)
      printf("List is empty!\n");
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
