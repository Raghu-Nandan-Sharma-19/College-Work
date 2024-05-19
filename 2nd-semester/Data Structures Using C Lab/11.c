// Implement a queue using linked list and develop functions to perform enqueue and dequeue operations
#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Define a structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}
// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}
// Function to perform enqueue operatio
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue\n", data);
}
// Function to perform dequeue operation
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        exit(1);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}
int main() {
    // Create a new queue
    Queue* queue = createQueue();
    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    // Dequeue and print dequeued elements
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));
    // Try to dequeue from an empty queue
    // dequeue(queue);
    return 0;
}