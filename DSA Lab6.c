#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void insert_at_beginning(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}
void insert_after_key(int key, int data)
{
    struct Node* curr = head;
    while (curr != NULL && curr->data != key)
        curr = curr->next;
    if (curr == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    /* CASE 1: If key node is the LAST node */
    if (curr->next == NULL)
    {
        curr->next = new_node;
        new_node->prev = curr;
        new_node->next = NULL;
    }
    /* CASE 2: If key node is NOT the last node */
    else
    {
        new_node->next = curr->next;
        new_node->prev = curr;
        curr->next->prev = new_node;
        curr->next = new_node;
    }
}
void insert_at_end(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = new_node;
    new_node->prev = curr;
}
void traverse_forward()
{
    struct Node* curr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (curr != NULL)
    {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(" <-> ");
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);

    printf("Original list (Forward):\n");
    traverse_forward();

    insert_at_beginning(5);
    printf("\nAfter inserting 5 at beginning:\n");
    traverse_forward();

    insert_after_key(20, 25);
    printf("\nAfter inserting 25 after key 20:\n");
    traverse_forward();
    
    insert_after_key(50, 60);  /* Key not present */
    return 0;
}