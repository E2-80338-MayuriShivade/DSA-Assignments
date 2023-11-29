#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *create_node(int data);
void add_at_specific(int data,int pos);
int count_nodes();
void add_first(int data);
void display();

int main(){
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(50);
    display();
    add_at_specific(60,3);
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

void add_at_specific(int data,int pos)
{
    if(head==NULL)
    {
        if(pos==1)
        {
            add_first(data);
        }
        else
        {
            printf("List is empty!\n");
        }
    }
    else if(pos==1)
    {
        add_first(data);
    }
    else if(pos ==count_nodes()+1)
    { 
        printf("Invalid position\n");
    }
    else
    {
        struct node *ptr=create_node(data);
        struct node *trav = head;
        for(int i=1;i<pos-1;i++)
        {
            trav=trav->next;
        }
        ptr->next=trav->next;
        trav->next=ptr;
    }
}
int count_nodes()
{
    int count=0;
    if(head==NULL)
       printf("List is empty!\n");
    else
    {
        struct node *trav =head;

        while(trav!=NULL)
        {
            count++;
            trav=trav->next;
        }
    }   
    return count;
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



