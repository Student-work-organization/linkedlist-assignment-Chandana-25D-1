#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert_at_beginning(int data)
{
    struct Node *newnode, *curr;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        struct Node *curr = head;
        while(curr->next != head)
        {
            curr = curr->next;
        }

        newnode->next = head;
        curr->next = newnode;
        head = newnode;
    }
}

void traverse()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *curr = head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    while(curr != NULL && curr != head);
        printf("%d ", curr->data);
        curr = curr->next;
}
int main()
{
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);
    printf("Circular Linked List: ");
    traverse();
    return 0;
}