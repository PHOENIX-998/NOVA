#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void add_node(struct node *head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head->data == '\0')
    {
        head->data = new_node->data;
        return;
    }
    struct node *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}
void past(struct node * head)
{
    struct node *curr=head;
    while (curr != NULL)
    {
        printf("%d,", curr->data);
        curr = curr->next;
    }
}
void addmid(struct node *head,struct node* newnod,int point)
{
    struct node *next = NULL;
    struct node *mid = head;
    while (point != 1)
    {
        mid = mid->next;
        point--;
    }
    next = mid->next;
    newnod->next = next;
    mid->next = newnod;
}
int main()
{
    int a, x, i = 0, c;
    int d;
    struct node *head = malloc(sizeof(struct node));
    head->data = '\0';
    head->next = NULL;
    printf("Enter the number of nodes:\n");
    scanf("%d", &x);
    printf("Enter the data:\n");
    while (i < x)
    {
        scanf("%d", &a);
        add_node(head, a);
        i++;
    }
    printf("The list before adding the node:\n");
    past(head);
    printf("\nEnter the new node data:\n");
    scanf("%d", &d);
    struct node *newnod = malloc(sizeof(struct node));
    newnod->data = d;
    newnod->next = NULL;
    printf("Enter the position to add the node after:\n");
    scanf("%d", &c);
    addmid(head,newnod,c);
    printf("\nThe list after adding the node\n");
    past(head);
    return 0;
}
