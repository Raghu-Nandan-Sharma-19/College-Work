// Write a program to check if a given expression is correctly parenthesized using Stacks
#include<stdio.h>
#include<string.h>
char str[1000]; 
int max, top=-1;
char stack[1000];
void push(char c) {
    if(top==max-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=c;
}
void pop() {
    if(top==-1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}
void checkParenthesis() {
    max=strlen(str);
    for(int i=0; i<max; i++) {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
            push(str[i]);
        } else if(str[i]==')' || str[i]=='}' || str[i]==']') {
            if(top==-1) {
                printf("Unbalanced Parenthesis\n");
                return;
            } else if((str[i]==')' && stack[top]=='(') || (str[i]=='}' && stack[top]=='{') || (str[i]==']' && stack[top]=='[')) {
                pop();
            } else {
                printf("Unbalanced Parenthesis\n");
                return;
            }
        }
    }
    if(top==-1) {
        printf("Balanced Parenthesis\n");
    } else {
        printf("Unbalanced Parenthesis\n");
    }
}
int main() {
    printf("Enter the expression : ");
    gets(str);
    checkParenthesis();
    return 0;
}