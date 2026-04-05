#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert_at_beginning(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");
}
void insert_at_end(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    printf("Node inserted at end.\n");
}
void insert_after_key(int key, int data)
{
   struct Node* curr = head;
    while (curr != NULL && curr->data != key)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = curr->next;
    curr->next = newNode;

    printf("Node inserted after %d.\n", key);
}
void traverse()
{
    struct Node* curr = head;

    if (curr == NULL)
    {
        printf("List is empty.\n");
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
    int choice, data, key;
    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Key\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insert_after_key(key, data);
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
