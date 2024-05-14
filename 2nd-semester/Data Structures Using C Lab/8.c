// Implement a doubly linked list and develop functions and develop functions to 
// perform insertion, deletion and linear search operations
#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
    printf("%d inserted at the beginning.\n", data);
}
// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", data);
}
// Function to delete the first occurrence of a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    // If the key was not found in the list
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }
    // If the node to be deleted is the head node
    if (temp == *headRef) {
        *headRef = temp->next;
    }
    // Adjust the pointers of neighboring nodes
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    // Free the memory of the deleted node
    free(temp);
    printf("%d deleted from the list.\n", key);
}
// Function to perform linear search in the list
struct Node* linearSearch(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // Return the node containing the key
        }
        current = current->next;
    }
    return NULL; // Key not found
}
// Function to print the elements of the list
void printList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Main function
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printList(head);
    struct Node* searchResult = linearSearch(head, 30);
    if (searchResult != NULL) {
        printf("%d found in the list.\n", searchResult->data);
    } else {
        printf("30 not found in the list.\n");
    }
    deleteNode(&head, 20);
    printList(head);
    return 0;
}