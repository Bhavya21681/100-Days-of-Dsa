/*Problem: Convert an infix expression to postfix notation using stack.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if(top < MAX-1) {
        stack[++top] = x;
    }
}

char pop() {
    if(top >= 0) {
        return stack[top--];
    }
    return '#';
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    int i = 0, j = 0;
    
    scanf("%s", infix);
    
    while(infix[i] != '\0') {
        char c = infix[i];
        
        if(isalnum(c)) {
            postfix[j++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if(top >= 0) pop();
        }
        else {
            while(top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    
    while(top >= 0) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
    
    printf("%s\n", postfix);
    
    return 0;
}
