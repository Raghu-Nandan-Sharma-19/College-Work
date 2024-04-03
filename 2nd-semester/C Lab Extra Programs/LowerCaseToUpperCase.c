// C Program to convert lower case letter to uppercase letters using bitwise operator
#include<stdio.h>
int main() {
    char ch;
    printf("Enter any letter : ");
    scanf("%c", &ch);
    printf("Character in uppercase is %c", ch&(~32));
    return 0;
}