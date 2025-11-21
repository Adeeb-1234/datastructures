#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// FuncƟon to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end (for iniƟal creaƟon or adding nodes)
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert a new node to the left of a given node (by value)
void insertLeft(struct Node **head, int target, int data)
{
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        *head = newNode; // inserƟng before the first node

    temp->prev = newNode;
    printf("Inserted %d to the left of %d\n", data, target);
}

// Delete a node based on a specific value
void deleteNode(struct Node **head, int target)
{
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node with value %d not found!\n", target);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; // deleƟng the first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", target);
}

// Display the list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu-driven main funcƟon
int main()
{

    struct Node *head = NULL;
    int choice, value, target;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert to the left of a Node\n");
        printf("3. Delete a Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 2:
            printf("Enter target node value: ");
            scanf("%d", &target);
            printf("Enter new value to insert: ");
            scanf("%d", &value);
            insertLeft(&head, target, value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;

        case 4:
            displayList(head);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}