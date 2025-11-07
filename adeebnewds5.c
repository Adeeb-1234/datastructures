#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
int data;
struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
struct Node* newNode = createNode(value);
newNode->next = *head;
*head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int value) {
struct Node* newNode = createNode(value);
if (*head == NULL) {
*head = newNode;
return;
}

struct Node* temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}

// Insert at any posiƟon (1-based index)
void insertAtPosition(struct Node** head, int value, int position) {
struct Node* newNode = createNode(value);

if (position == 1) {
newNode->next = *head;
*head = newNode;
return;
}

struct Node* temp = *head;
for (int i = 1; i < position - 1 && temp != NULL; i++) {
temp = temp->next;
}

if (temp == NULL) {
printf("Position out of bounds.\n");
free(newNode);
return;
}

newNode->next = temp->next;
temp->next = newNode;
}

// Display the list
void displayList(struct Node* head) {
struct Node* temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

// Main funcƟon
int main() {
struct Node* head = NULL;

// Create and insert nodes
insertAtBeginning(&head, 10); // List: 10
insertAtEnd(&head, 20); // List: 10 -> 20
insertAtPosition(&head, 15, 2); // List: 10 -> 15 -> 20
insertAtPosition(&head, 5, 1); // List: 5 -> 10 -> 15 -> 20
insertAtPosition(&head, 25, 5); // List: 5 -> 10 -> 15 -> 20 -> 25

// Display final list
displayList(head);

return 0;
}