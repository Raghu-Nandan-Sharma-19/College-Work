#include <stdio.h>
int main() {
    int a, b, *p, *q;
    printf("Enter A and B : ");
    scanf("%d%d", &a, &b);
    p=&a, q=&b;
    printf("A value is : %d\n", *p);
    printf("B value is : %d\n", *q);
    printf("Sum of two numbers is : %d\n", *p+*q);
    return 0;
}