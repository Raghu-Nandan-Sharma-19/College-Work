// Write a program to evaluate postfix, prefix and infix expressions using Stacks.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
char stack[max];
int top = -1;
void push(float stack[], float val) {
    if(top == max-1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}
float pop(float stack[]) {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
float prefixEvaluation(char prefix[]) {
    float stack[max];
    int i;
    for(i = strlen(prefix)-1; i >= 0; i--) {
        if(isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            float op1 = pop(stack);
            float op2 = pop(stack);
            switch(prefix[i]) {
                case '+':
                    push(stack, op1 + op2);
                    break;
                case '-':
                    push(stack, op1 - op2);
                    break;
                case '*':
                    push(stack, op1 * op2);
                    break;
                case '/':
                    push(stack, op1 / op2);
                    break;
            }
        }
    }
    return pop(stack);
}
float postfixEvaluation(char postfix[]) {
    float stack[max];
    int i;
    for(i = 0; i < strlen(postfix); i++) {
        if(isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            float op2 = pop(stack);
            float op1 = pop(stack);
            switch(postfix[i]) {
                case '+':
                    push(stack, op1 + op2);
                    break;
                case '-':
                    push(stack, op1 - op2);
                    break;
                case '*':
                    push(stack, op1 * op2);
                    break;
                case '/':
                    push(stack, op1 / op2);
                    break;
            }
        }
    }
    return pop(stack);
}
float infixEvaluation(char infix[]) {
    float stack[max];
    char postfix[max];
    int i, j = 0;
    for(i = 0; i < strlen(infix); i++) {
        if(isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if(infix[i] == '(') {
            push(stack, infix[i]);
        } else if(infix[i] == ')') {
            while(stack[top] != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        } else {
            while(top != -1 && stack[top] != '(' && (infix[i] == '*' || infix[i] == '/')) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while(top != -1) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
    return postfixEvaluation(postfix);
}
int main() {
    int choice;
    printf("1. Evaluate Prefix Expression\n2. Evaluate Postfix Expression\n3. Evaluate Infix Expression\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            char prefix[max];
            printf("Enter the prefix expression: ");
            scanf("%s", prefix);
            printf("Result: %.2f\n", prefixEvaluation(prefix));
            break;
        }
        case 2: {
            char postfix[max];
            printf("Enter the postfix expression: ");
            scanf("%s", postfix);
            printf("Result: %.2f\n", postfixEvaluation(postfix));
            break;
        }
        case 3: {
            char infix[max];
            printf("Enter the infix expression: ");
            scanf("%s", infix);
            printf("Result: %.2f\n", infixEvaluation(infix));
            break;
        }
        default:
            printf("Invalid choice\n");
    }
    return 0;
}   