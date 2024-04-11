// Write a program to convert an infix expression to its corresponding postfix and prefix expressions and vice versa.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
char val;
char infix[100], postfix[100], temp[100], prefix[100];
void push(char stack[], char val) {
    if(top==max-1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top]=val;
    }
}
char pop(char stack[]) {
    if(top==-1) {
        printf("Stack Underflow\n");
    } else {
        val=stack[top];
        top--;
    }
    return val;
}
int precedence(char ch) {
    if(ch=='^') {
        return 2;
    } else if(ch=='*' || ch=='/' || ch=='%') {
        return 1;
    } else if(ch=='+' || ch=='-') {
        return 0;
    }
}
void infixToPostfix(char source[], char target[]) {
    int i=0, j=0;
    char t;
    strcpy(target, "");
    while(source[i]!='\0') {
        if(source[i]=='(') {
            push(stack, source[i]);
            i++;
        } else if((isdigit(source[i])) || (isalpha(source[i]))) {
            target[j]=source[i];
            i++;
            j++;
        } else if(source[i]==')') {
            while((top!=-1) && (stack[top]!='(')) {
                target[j] = pop(stack);
                j++;
            }
            if(top==-1) {
                printf("Invalid expression\n");
            }
            t = pop(stack);
            i++;
        } else if((source[i]=='+') || (source[i]=='-') || (source[i]=='*') || (source[i]=='/') || source[i] == '%') {
            while((top!=-1) && (stack[top]!='(') && (precedence(stack[top])>=precedence(source[i]))) {
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);
            i++;
        } else {
            printf("Invalid expression\n");
        }
    }
    while((top!=-1) && (stack[top]!='(')) {
        target[j] = pop(stack);
        j++;
    }
    target[j]='\0';
}
void postfixToInfix(char source[], char target[]) {
    int i = 0;
    int k = 0;
    int len = strlen(source);
    char temp[1000], s1[100][30];
    strcpy(target, " ");
    for(i=0; i<=len-1; i++) {
        if(isalnum(source[i])) {
            char t[] = {source[i], '\0'};
            strcpy(s1[k++], t); 
        } else {
            char *op2 = s1[--k];
            char *op1 = s1[--k];
            sprintf(temp, "(%s%c%s)", op1, source[i], op2);
            strcpy(s1[k++], temp);
        }
    }
    strcpy(target, s1[--k]);
}
void prefixToInfix(char source[], char target[]) {
    int i = 0;
    int k = 0;
    int len = strlen(source);
    char temp[1000], s1[100][30];
    strcpy(target, " ");
    for(i=len-1; i>=0; i--) {
        if(isalnum(source[i])) {
            char t[] = {source[i], '\0'};
            strcpy(s1[k++], t); 
        } else {
            char *op1 = s1[--k];
            char *op2 = s1[--k];
            sprintf(temp, "(%s%c%s)", op1, source[i], op2);
            strcpy(s1[k++], temp);
        }
    }
    strcpy(target, s1[--k]);
}
void reverse(char str[]) {
    int len, i=0, j=0;
    len = strlen(str);
    j = len - 1;
    while(j>=0) {
        if(str[j]=='(') {
            temp[i] = ')';
        } else if(str[j]==')') {
            temp[i] = '(';
        } else {
            temp[i] = str[j]; 
        }
        i++;
        j--;
    }
    temp[i] = '\0';
}
int main() {
    int choice;
    printf("Enter 1 for Infix to Postfix\nEnter 2 for infix to prefix\nEnter 3 for Prefix to Infix\nEnter 4 for postfix to infix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            printf("Enter the infix expression: ");
            scanf("%s", infix);
            strcpy(postfix, "");
            infixToPostfix(infix, postfix);
            printf("Postfix expression: %s\n", postfix);
            break;
        case 2: 
            printf("Enter the infix expression : ");
            scanf("%s", infix);
            reverse(infix);
            printf("The reverse of infix expression is : temp = %s\n", postfix);
            strcpy(postfix, "");
            infixToPostfix(temp, postfix);
            printf("The postfix expression is : %s\n", postfix);
            reverse(postfix);
            printf("The prefix expression is : %s", temp);
            break;
        case 3: 
            printf("Enter the prefix expression: ");
            scanf("%s", prefix);
            strcpy(infix, "");
            prefixToInfix(prefix, infix);
            printf("Infix expression: %s\n", infix);
            break;
        case 4: 
            printf("Enter the postfix expression: ");
            scanf("%s", postfix);
            strcpy(infix, "");
            postfixToInfix(postfix, infix);
            printf("The infix expression is : %s", infix);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}