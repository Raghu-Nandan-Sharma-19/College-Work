// Implement a stack using linked list and develop functions to perform push and pop operations.
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
// Structure to represent the stack
typedef struct Stack {
    Node *top;
} Stack;
// Function to initialize an empty stack
Stack* initializeStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}
// Function to push an element onto the stack
void push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}
// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop.\n");
        return -1;
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}
// Function to print the elements of the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Stack *stack = initializeStack();
    // Pushing elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);
    // Popping an element from the stack
    int poppedValue = pop(stack);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }
    display(stack);
    // Popping another element
    poppedValue = pop(stack);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }
    display(stack);
    // Popping from an empty stack
    poppedValue = pop(stack);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }
    display(stack);
    return 0;
}