// Implement a circular linked list and develop functions 
// and develop functions to perform insertion, deletion and linear search operations
#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Circular link to itself
    } else {
        newNode->next = head->next;
        head->next = newNode; // Update previous head node's next pointer
    }
    head = newNode; // Update head pointer to the new node
    return head;
}
// Function to delete a node from the circular linked list
Node* deleteNode(Node *head, int key) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        if (temp->data == key) {
            if (prev == NULL) {
                Node *lastNode = temp;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                lastNode->next = temp->next;
                head = temp->next;
                free(temp);
                return head;
            } else {
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    // Check if the key is in the last node
    if (temp->data == key) {
        if (temp == head) {
            free(temp);
            return NULL;
        } else {
            prev->next = head;
            free(temp);
            return head;
        }
    }
    return head;
}
// Function to perform linear search in the circular linked list
int search(Node *head, int key) {
    if (head == NULL) {
        return 0;
    }
    Node *temp = head;
    do {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);
    return 0;
}
// Function to print the circular linked list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    Node *head = NULL;
    // Insertion
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);
    display(head);
    // Deletion
    head = deleteNode(head, 20);
    display(head);
    // Search
    int key = 30;
    if (search(head, key)) {
        printf("%d found in the list.\n", key);
    } else {
        printf("%d not found in the list.\n", key);
    }
    key = 50;
    if (search(head, key)) {
        printf("%d found in the list.\n", key);
    } else { 
        printf("%d not found in the list.\n", key);
    }
    return 0;
}