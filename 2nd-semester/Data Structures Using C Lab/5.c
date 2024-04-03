#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
char val;
char infix[100], postfix[100];
void push(char val) {
    if(top==max-1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top]=val;
    }
}
char pop() {
    if(top==-1) {
        printf("Stack Underflow\n");
    } else {
        val=stack[top];
        top--;
        return val;
    }
}
int precedence(char ch) {
    if(ch=='^') {
        return 3;
    } else if(ch=='*' || ch=='/') {
        return 2;
    } else if(ch=='+' || ch=='-') {
        return 1;
    } else {
        return 0;
    }
}
void infixToPostfix(char infix[], char postfix[]) {
    int i=0, j=0;
    char ch;
    push('(');
    strcat(infix, ")");
    while(infix[i]!='\0') {
        if(infix[i]=='(') {
            push(infix[i]);
            i++;
        } else if(isalnum(infix[i])) {
            postfix[j]=infix[i];
            j++;
            i++;
        } else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^') {
            while(precedence(stack[top])>=precedence(infix[i])) {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
            i++;
        } else if(infix[i]==')') {
            while(stack[top]!='(') {
                postfix[j]=pop();
                j++;
            }
            val=pop();
            i++;
        }
    }
    postfix[j]='\0';
}
void reverse(char str[]) {
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
int main() {
    int choice;
    printf("Enter 1 for postfix\n2 for prefix : ");
    scanf("%d", &choice);
    if(choice==1) {
        printf("Enter the infix expression: ");
        gets(infix);
        gets(infix);
        infixToPostfix(infix, postfix);
        printf("The postfix expression is: ");
        puts(postfix);
    } else if(choice==2) {
        printf("Enter the infix expression: ");
        gets(infix);
        gets(infix);
        infixToPostfix(infix, postfix);
        reverse(postfix);
        printf("The prefix expression is: ");
        puts(postfix);
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}