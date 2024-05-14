#include <stdio.h>

void enqueueCircular(int);
int dequeueCircular();
void displayQueue();

int queue[100], max, rear = -1, front = -1;

void enqueueCircular(int number) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    if (rear == max - 1)
        rear = 0;
    else
        rear = rear + 1;
        queue[rear] = number;
}

int dequeueCircular() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == max - 1)
        front = 0;
    else
        front = front + 1;
    return data;
}

void displayQueue() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        printf("Elements in the queue are: ");
        int i;
        if (rear >= front) {
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        } else {
            for (i = front; i < max; i++)
                printf("%d ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int num, del, choice;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &max);
    while (1) {
        printf("\nEnter 1 to enqueue, 2 to dequeue, and 3 to display the queue: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &num);
                enqueueCircular(num);
                break;
            case 2:
                del = dequeueCircular();
                if (del != -1)
                    printf("Removed element from the queue: %d\n", del);
                break;
            case 3:
                displayQueue();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}