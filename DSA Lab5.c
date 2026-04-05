#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}
void delete_from_the_beginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = head;
    head = head->next;
    free(curr);
    printf("First node deleted\n");
}
void delete_the_end_node()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;
    free(curr);
    printf("Last node deleted\n");
}
void delete_node_with_givenData(int data)
{
    struct Node* curr = head;
    struct Node* prev = NULL;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (curr->data == data)
    {
        head = curr->next;
        free(curr);
        printf("Node deleted\n");
        return;
    }
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Data not found\n");
        return;
    }
    prev->next = curr->next;
    free(curr);
    printf("Node deleted successfully\n");
}
void traverse()
{
    struct Node* curr = head;
    if (curr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    traverse();
    delete_from_the_beginning();
    traverse();
    delete_the_end_node();
    traverse();
    delete_node_with_givenData(20);
    traverse();
    return 0;
}