// Max of three numbers using nested if 
#include<stdio.h>
void maximumOfThreeNumbers(int num1, int num2, int num3) {
    if(num1>num2 || num2>num3 || num3>num2) {
        if(num1>num2 && num1>num3) {
            printf("%d is greatest.", num1);
        } else if(num2>num1 && num2>num3) {
            printf("%d is greatest.", num2);
        } else if (num3>num1 && num3>num2) {
            printf("%d is greatest.", num3);
        } else {
            printf("All numbers are equal.");
        }
    }
}
int main() {
    int num1, num2, num3;
    printf("Enter three numbers : \n");
    scanf("%d%d%d", &num1, &num2, &num3);
    maximumOfThreeNumbers(num1, num2, num3);
    return 0;
}