/*Problem: Implement push and pop operations on a stack and verify stack operations.*/
#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if(top < MAX - 1) {
        stack[++top] = x;
    }
}

void pop() {
    if(top >= 0) {
        top--;
    }
}

int main() {
    int n, m, i, val;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }
    
    scanf("%d", &m);
    
    for(i = 0; i < m && top >= 0; i++) {
        pop();
    }
    
    if(top == -1) {
        printf("\n");
        return 0;
    }
    
    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i > 0) printf(" ");
    }
    printf("\n");
    
    return 0;
}
