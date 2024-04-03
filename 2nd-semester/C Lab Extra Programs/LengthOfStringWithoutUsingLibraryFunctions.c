// Program to get the length of string without using string library functions
#include<stdio.h>
int main() {
    char str[100];
    int length=0;
    printf("Enter anything : ");
    gets(str);
    for(int i=0; str[i] != '\0'; i++) {
        length++;
    }
    printf("Length of string is %d", length);
    return 0;
}