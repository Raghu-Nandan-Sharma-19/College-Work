// Question 7 Reverse integer
#include<stdio.h>
int main() {
    int n;
    printf("Enter any number : ");
    scanf("%d", &n);
    int ans = 0;
    while(n>0) {
        int digit = n%10;
        ans = (ans*10) + digit;
        n=n/10;
    }
    printf("Reverse of the given number : %d\n", ans);
    return 0;
}