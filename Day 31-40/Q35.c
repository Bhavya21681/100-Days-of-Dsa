/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    
    if(rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int main() {
    int n, i, val;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    
    struct node* ptr = front;
    while(ptr != NULL) {
        printf("%d", ptr->data);
        if(ptr->next != NULL) {
            printf(" ");
        }
        ptr = ptr->next;
    }
    printf("\n");
    
    return 0;
}
