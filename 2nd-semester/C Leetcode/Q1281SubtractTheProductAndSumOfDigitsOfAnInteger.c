// Question 1281 : Subtract the product and sum of digits of an integer

#include<stdio.h>
int main() {
    int n, sum=0, product=1;
    printf("Enter any number : ");
    scanf("%d", &n);
    while(n>0) {
        int digit = n%10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    printf("After subtracting the product and sum of digits of an integer : %d\n", product-sum);
    return 0;
}