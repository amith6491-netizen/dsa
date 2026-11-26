#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *head = NULL;
struct Node* getNode() {
struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
if (temp == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
return temp;
}
void insertAtBeginning(int value) {
struct Node *newNode = getNode();
newNode->data = value;
newNode->next = head;
head = newNode;
printf("%d inserted at beginning\n", value);
}
void insertAtEnd(int value) {
struct Node *newNode = getNode();
struct Node *temp = head;
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
printf("%d inserted at end\n", value);
return;
}
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
printf("%d inserted at end\n", value);
}
void deleteFromBeginning() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node *temp = head;
printf("%d deleted from beginning\n", temp->data);
head = head->next;
free(temp);
}
void deleteFromEnd() {
if (head == NULL) {
printf("List is empty\n");
return;
}
if (head->next == NULL) {
printf("%d deleted from end\n", head->data);
free(head);
head = NULL;
return;
}
struct Node *temp = head;
while (temp->next->next != NULL)
temp = temp->next;
printf("%d deleted from end\n", temp->next->data);
free(temp->next);
temp->next = NULL;
}
void insertAfterNode(int key, int value) {
struct Node *temp = head;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp == NULL) {
printf("Node %d not found\n", key);
return;
}
struct Node *newNode = getNode();
newNode->data = value;
newNode->next = temp->next;
temp->next = newNode;
printf("%d inserted after node %d\n", value, key);
}
void deleteAfterNode(int key) {
struct Node *temp = head;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp == NULL) {
printf("Node %d not found\n", key);
return;
}
if (temp->next == NULL) {
printf("No node exists after %d\n", key);
return;
}
struct Node *del = temp->next;
printf("%d deleted after node %d\n", del->data, key);
temp->next = del->next;
free(del);
}
void display() {
struct Node *temp = head;
if (head == NULL) {
printf("List is empty\n");
return;
}
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
int choice, value, key;
while (1) {
printf("\n1. Insert at Beginning");
printf("\n2. Insert at End");
printf("\n3. Delete from Beginning");
printf("\n4. Delete from End");
printf("\n5. Insert after a given node p");
printf("\n6. Delete after a given node p");
printf("\n7. Display");
printf("\n8. Exit\n");
printf("Enter your choice: ");
if (scanf("%d", &choice) != 1)
break;
switch (choice) {
case 1:
printf("Enter element to insert: ");
scanf("%d", &value);
insertAtBeginning(value);
break;
case 2:
printf("Enter element to insert: ");
scanf("%d", &value);
insertAtEnd(value);
break;
case 3:
deleteFromBeginning();
break;
case 4:
deleteFromEnd();
break;
case 5:
printf("Enter existing value : ");
scanf("%d", &key);
printf("Enter element to insert: ");
scanf("%d", &value);
insertAfterNode(key, value);
break;
case 6:
printf("Enter the existing value: ");
scanf("%d", &key);
deleteAfterNode(key);
break;
case 7:
printf("The list is: ");
display();
break;
case 8:
printf("Program terminated\n");
return 0;
default:
printf("Invalid choice\n");
}
}
return 0;
}
