#include<stdio.h>
int additionOfTwoNumbers(int a, int b) {
    return a+b;
}
int main() {
    int a, b;
    printf("Enter a and b : ");
    scanf("%d %d", &a, &b);
    printf("Sum is : %d", additionOfTwoNumbers(a, b));
    return 0;
}