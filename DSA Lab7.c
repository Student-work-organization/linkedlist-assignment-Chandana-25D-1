#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
void insert_at_end(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = newnode;
    newnode->prev = curr;
}
void delete_node(int data)
{
    struct Node* curr = head;
    while(curr != NULL && curr->data != data)
        curr = curr->next;
    if(curr == NULL)
    {
        printf("Data not found\n");
        return;
    }
    if(curr == head)
    {
        head = curr->next;
        if(head != NULL)
            head->prev = NULL;
        free(curr);
        return;
    }
    if(curr->next != NULL)
        curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    free(curr);
}
void delete_the_end_node()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    if(curr == head)
        head = NULL;
    else
        curr->prev->next = NULL;
    free(curr);
}
void delete_node_with_givenData(int key, int data)
{
    struct Node* curr = head;
    while(curr != NULL && curr->data != key)
        curr = curr->next;
    if(curr == NULL)
    {
        printf("Key not found\n");
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = curr->next;
    newnode->prev = curr;
    if(curr->next != NULL)
        curr->next->prev = newnode;
    curr->next = newnode;
}
void traverse_backward()
{
    if(head == NULL)
        return;
    struct Node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}
void display()
{
    struct Node* curr = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);
    printf("Original List:\n");
    display();

    delete_node(20);
    printf("After deleting node with data 20:\n");
    display();

    delete_the_end_node();
    printf("After deleting end node:\n");
    display();

    delete_node_with_givenData(10,15);
    printf("After inserting 15 after 10:\n");
    display();

    printf("Backward Traversal:\n");
    traverse_backward();
    return 0;
}