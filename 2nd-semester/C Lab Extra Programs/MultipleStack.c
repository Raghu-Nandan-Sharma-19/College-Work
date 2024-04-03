#include<stdio.h>
#define max 10
int stack[max],topB=max, noOfStacks, top=-1, choice;
void display() {
    if(top==-1) {
        printf("Stack A is empty\n");
    } else if(topB==max) {
        printf("Stack B is empty\n");
    } else {
        for(int i=0; i<max; i++) {
            if(i<=top) {
                printf("%d\t", stack[top-i]);
            } else if(i>=topB) {
                printf("%d\t", stack[i]);
            }
        }
    }
}
void push() {
    int value;
    if(top==max/noOfStacks-1) {
        printf("Stack A is full\n");
    } else {
        printf("Push elements into stack A :\n");
        while(top<max/noOfStacks-1) {
            top++;
            printf("Enter the %d index value : \n", top);
            scanf("%d", &value);
            stack[top]=value;
        } 
    }
    printf("The elements in stack A are :\n");
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
}
void pushB() {
    int value;
    if(topB==max/noOfStacks) {
        printf("Stack B is full\n");
    } else {
        printf("Push elements into stack B :\n");
        while(topB>max/noOfStacks) {
            topB--;
            printf("Enter the %d index value : \n", topB);
            scanf("%d", &value);
            stack[topB]=value;
        } 
    }
    printf("The elements in stack B are :\n");
    for(int i=topB; i<max; i++) {
        printf("%d\n", stack[i]);
    }
}
void pop() {
    int value;
    if(top==max) {
        printf("Underflow\n");
    } else {
        int popElements;
        printf("Enter the number of elements you want to pop : \n");
        scanf("%d", &popElements);
        for(int i=max; i>popElements; i--) {
            value=stack[topB];
            topB--;
            printf("The popped element is : %d\n", value);
        }
        
    }
    printf("The stack is : \n");
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
}
void popB() {
    int value;
    if(topB==-1) {
        printf("Underflow\n");
    } else {
        int popElements;
        printf("Enter the number of elements you want to pop : \n");
        scanf("%d", &popElements);
        for(int i=0; i<popElements; i++) {
            value=stack[topB];
            topB++;
            printf("The popped element is : %d\n", value);
        }
    }
    printf("The stack B is : \n");
    for(int i=topB; i<max; i++) {
        printf("%d\n", stack[i]);
    }
}
int main() {
    printf("Enter the number of stacks :\n");
    scanf("%d", &noOfStacks);
    while(1) {
        printf("1. Push in stack A\n2. Pop from stack A\n3. Push in stack B\n4. Pop from stack b\n5. Display both stacks\n6. Exit");
        printf("\nEnter your choice : \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                pushB();
                break;
            case 4 :
                popB();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting\n");
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }
    
    return 0;
}