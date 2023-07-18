#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void add_node(struct node* head,int data)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(head->data=='\0')
    {
        head->data=new_node->data;
        return;
    }
    struct node* current_node=head;
    while(current_node->next!=NULL)
    {
        current_node=current_node->next;
    }
    current_node->next=new_node;
}
int main()
{
    int a,x,i=0;
    struct node* head=malloc(sizeof(struct node));
    head->data='\0';
    head->next=NULL;
    printf("Enter the number of nodes:\n");
    scanf("%d",&x);
    printf("Enter the data:\n");
    while(i<x)
    {
        scanf("%d",&a);
        add_node(head,a);
        i++;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp=temp-2;
    temp->next=NULL;
    i=0;
    while(head!=NULL)
    {
        printf("%d,",head->data);
        head=head->next;
    }
    printf("\b.\n");
    return 0;
}
