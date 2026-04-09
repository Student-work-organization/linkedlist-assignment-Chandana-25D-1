#include <stdio.h>
#include <stdlib.h>

struct CircularNode
{
    int data;
    struct CircularNode *next;
};

struct CircularNode *head = NULL;

void insert_at_end(int data)
{
    struct CircularNode *newnode, *curr;

    newnode = (struct CircularNode *)malloc(sizeof(struct CircularNode));
    newnode->data = data;

    /* If list is empty */
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        curr = head;

        /* Traverse till last node */
        while (curr->next != head)
        {
            curr = curr->next;
        }

        curr->next = newnode;
        newnode->next = head;
    }
}

void delete_node(int data)
{
    struct CircularNode *curr, *prev;

    /* If list is empty */
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    curr = head;
    prev = NULL;

    /* If head node contains data */
    if (head->data == data)
    {
        /* Only one node */
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            curr = head;

            /* Find last node */
            while (curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = head->next;
            free(head);
            head = curr->next;
        }
        return;
    }

    prev = head;
    curr = head->next;

    /* Traverse list */
    while (curr != head && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    /* If node found */
    if (curr->data == data)
    {
        prev->next = curr->next;
        free(curr);
    }
    else
    {
        printf("Element not found\n");
    }
}

/* Traverse circular list */
void traverse()
{
    struct CircularNode *curr;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    curr = head;

    do
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("HEAD\n");
}

/* Main function */
int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);

    printf("Circular Linked List:\n");
    traverse();

    delete_node(20);

    printf("After deleting 20:\n");
    traverse();

    return 0;
}