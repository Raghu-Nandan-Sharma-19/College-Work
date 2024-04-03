// Program to convert upper case to lowercase using bitwise operators
#include <stdio.h>
int main() {
    char ch;
    printf("Enter any letter : ");
    scanf("%c", &ch);
    printf("Character in lower case is : %c", ch | 32);
    return 0;
}