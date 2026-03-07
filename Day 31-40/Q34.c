/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if(top == NULL) {
        return 0;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char c;
    int op1, op2, result;
    
    while(scanf("%c", &c) == 1) {
        if(c == ' ' || c == '\n') continue;
        
        if(c >= '0' && c <= '9') {
            int num = 0;
            while(c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                if(scanf("%c", &c) != 1 || (c != ' ' && c != '\n')) break;
            }
            push(num);
            if(c != ' ' && c != '\n') {
                if(isOperator(c)) {
                    op2 = pop();
                    op1 = pop();
                    
                    if(c == '+') result = op1 + op2;
                    else if(c == '-') result = op1 - op2;
                    else if(c == '*') result = op1 * op2;
                    else if(c == '/') result = op1 / op2;
                    
                    push(result);
                }
            }
        }
        else if(isOperator(c)) {
            op2 = pop();
            op1 = pop();
            
            if(c == '+') result = op1 + op2;
            else if(c == '-') result = op1 - op2;
            else if(c == '*') result = op1 * op2;
            else if(c == '/') result = op1 / op2;
            
            push(result);
        }
    }
    
    if(top != NULL) {
        printf("%d\n", top->data);
    }
    
    while(top != NULL) {
        struct node* temp = top;
        top = top->next;
        free(temp);
    }
    
    return 0;
}
