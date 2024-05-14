#include<stdio.h>
#define max 10
int queue[max], frontA = -1, rearA = -1, frontB = max, rearB = max;
int enqueueA(int val) {
    if(rearA == rearB-1) {
        printf("Overflow");
    } else {
        if((rearA == -1) && (frontA == -1)) {
            rearA = 0, frontA = 0;
            queue[rearA] = val;
        } else {
            queue[++rearA] = val;
        }
    }
}
int dequeueA() {
    int val;
    if(frontA == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        val = queue[frontA];
        frontA++;
        if(frontA > rearA) {
            rearA = -1;
            frontA = -1;
        }
    }
    return val;
}
int enqueueB(int val) {
    if(rearB == rearA+1) {
        printf("Overflow");
    } else {
        if((rearB == max) && (frontB == max)) {
            rearA = max-1, frontA = max-1;
            queue[rearB] = val;
        } else {
            queue[--rearB] = val;
        }
    }
}
int dequeueB() {
    int val;
    if(frontB == max) {
        printf("Underflow\n");
        return -1;
    } else {
        val = queue[frontB];
        frontB--;
        if(frontB < rearB) {
            rearB = max;
            frontB = max;
        }
    }
    return val;
}
void display() {
    if(frontA == -1) {
        printf("Queue A is empty\n");
    } else {
        printf("Queue A is :\n");
        for(int i=frontA; i<=rearA; i++) {
            printf("%d\t", queue[i]);
        }
    }
    if(frontB == max) {
        printf("Queue B is empty\n");
    } else {
        printf("Queue B is :\n");
        for(int i=frontB; i>=rearB; i--) {
            printf("%d\t", queue[i]);
        }
    }
}
int main() {
    int choice, val;
    while(1) {
        printf("1. Enqueue in Queue A\n2. Dequeue in Queue A\n3. Enqueue in Queue B\n4. Dequeue in Queue B\n5. Display\n6. Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued in Queue A : \n");
                scanf("%d", &val);
                enqueueA(val);
                break;
            case 2:
                val = dequeueA();
                if(val != -1) {
                    printf("The value dequeued from Queue A is %d\n", val);
                }
                break;
            case 3:
                printf("Enter the value to be enqueued in Queue B : \n");
                scanf("%d", &val);
                enqueueB(val);
                break;
            case 4:
                val = dequeueB();
                if(val != -1) {
                    printf("The value dequeued from Queue B is %d\n", val);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}