// Implement a priority queue using linked list and develop functions to perform enqueue and dequeue operations
#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;
// Define a structure for the priority queue
typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;
// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
// Function to create an empty priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* priorityQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (priorityQueue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    priorityQueue->front = NULL;
    return priorityQueue;
}
// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* priorityQueue) {
    return priorityQueue->front == NULL;
}
// Function to perform enqueue operation
void enqueue(PriorityQueue* priorityQueue, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (isEmpty(priorityQueue) || priority < priorityQueue->front->priority) {
        newNode->next = priorityQueue->front;
        priorityQueue->front = newNode;
    } else {
        Node* current = priorityQueue->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("%d enqueued to the priority queue with priority %d\n", data, priority);
}
// Function to perform dequeue operation
int dequeue(PriorityQueue* priorityQueue) {
    if (isEmpty(priorityQueue)) {
        printf("Priority queue is empty, cannot dequeue\n");
        exit(1);
    }
    int data = priorityQueue->front->data;
    Node* temp = priorityQueue->front;
    priorityQueue->front = priorityQueue->front->next;
    free(temp);
    return data;
}
int main() {
    // Create a new priority queue
    PriorityQueue* priorityQueue = createPriorityQueue();
    // Enqueue some elements with priorities
    enqueue(priorityQueue, 30, 3);
    enqueue(priorityQueue, 20, 2);
    enqueue(priorityQueue, 10, 1);
    // Dequeue and print dequeued elements
    printf("%d dequeued from the priority queue\n", dequeue(priorityQueue));
    printf("%d dequeued from the priority queue\n", dequeue(priorityQueue));
    printf("%d dequeued from the priority queue\n", dequeue(priorityQueue));
    // Try to dequeue from an empty priority queue
    // dequeue(priorityQueue);
    return 0;
}