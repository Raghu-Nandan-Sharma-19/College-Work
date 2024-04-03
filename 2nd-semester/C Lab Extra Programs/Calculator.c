// Program to make calculator using function and switch case.
#include<stdio.h>
int addition(int num1, int num2) {
    return num1 + num2;
}
int subtraction(int num1, int num2) {
    return num1 - num2;
}
int multiplication(int num1, int num2) {
    return num1 * num2;
}
int division(int num1, int num2) {  
    return num1 / num2;    // --> returning floor value --> 5/2 = 2
}
int main() {
    int num1, num2;
    int operation;
    printf("Enter two numbers : ");
    scanf("%d%d", &num1, &num2);
    printf("Enter 1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n");
    printf("Enter an operation : ");
    scanf("%d", &operation);
    switch(operation) {
        case 1 :
        printf("Sum is %d", addition(num1, num2));
        break;
        case 2 :
        printf("Difference is %d", subtraction(num1, num2));
        break;
        case 3 :
        printf("Product is %d", multiplication(num1, num2));
        break;
        case 4 :
        printf("Quotient is %d", division(num1, num2));
        break;
        default:
        printf("Please enter a valid operation.");
    }
    return 0;
}