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
    int a,x,i=0,c;
    struct node* head=malloc(sizeof(struct node));
    struct node* mid_node=NULL;
    struct node* mid=head;
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
    printf("Enter the position:\n");
    scanf("%d",&c);
    c--;
    while(c!=1)
    {
        mid=mid->next;
        c--;
    }
    mid_node=mid->next;
    mid->next=mid_node->next;
    mid_node->next=NULL;
    printf("%d\n",mid_node->data);
    i=0;
    while(i<x)
    {
        printf("%d,",head->data);
        head=head->next;
        i++;
    }
    return 0;
}
