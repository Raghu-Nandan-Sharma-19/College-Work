#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the head node
    struct Node* head = NULL;

    // Create three nodes
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the nodes
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Set the head of the linked list
    head = node1;

    // Print the linked list
    printLinkedList(head);

    // Free the memory allocated for the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
