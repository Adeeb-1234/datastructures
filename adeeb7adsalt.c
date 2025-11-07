#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
int data;
struct Node* next;
};

// FuncƟon to insert at end
void insertEnd(struct Node** head, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;

if (*head == NULL) {
*head = newNode;
} else {
struct Node* temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}

// FuncƟon to display list
void display(struct Node* head) {
printf("List: ");
while (head != NULL) {
printf("%d -> ", head->data);
head = head->next;

}
printf("NULL\n");
}

// FuncƟon to sort the list (Bubble Sort)
void sortList(struct Node* head) {
if (head == NULL) return;
struct Node* i, *j;
for (i = head; i->next != NULL; i = i->next) {
for (j = i->next; j != NULL; j = j->next) {
if (i->data > j->data) {
int temp = i->data;
i->data = j->data;
j->data = temp;
}
}
}
printf("List sorted in ascending order.\n");
}

// FuncƟon to reverse the list
void reverseList(struct Node** head) {
struct Node* prev = NULL;
struct Node* current = *head;
struct Node* next = NULL;

while (current != NULL) {
next = current->next;
current->next = prev;
prev = current;
current = next;

}
*head = prev;
printf("List reversed.\n");
}

// FuncƟon to concatenate two lists
void concatenate(struct Node** head1, struct Node* head2) {
if (*head1 == NULL) {
*head1 = head2;
return;
}
struct Node* temp = *head1;
while (temp->next != NULL)
temp = temp->next;
temp->next = head2;
printf("Lists concatenated.\n");
}

// Main funcƟon
int main() {
struct Node* list1 = NULL;
struct Node* list2 = NULL;
int choice, value;

while (1) {
printf("\n1. Insert into List1\n2. Insert into List2\n3. Display List1\n4. Display List2\n");
printf("5. Sort List1\n6. Reverse List1\n7. Concatenate List2 to List1\n8. Exit\nEnter choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:

printf("Enter value to insert into List1: ");
scanf("%d", &value);
insertEnd(&list1, value);
break;
case 2:
printf("Enter value to insert into List2: ");
scanf("%d", &value);
insertEnd(&list2, value);
break;
case 3:
display(list1);
break;
case 4:
display(list2);
break;
case 5:
sortList(list1);
break;
case 6:
reverseList(&list1);
break;
case 7:
concatenate(&list1, list2);
break;
case 8:
exit(0);
default:
printf("Invalid choice\n");
}
}

return 0;
}