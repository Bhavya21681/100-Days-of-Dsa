/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* front = NULL;
    struct Node* rear = NULL;
    
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            newNode->next = front;
            rear = newNode;
        }
    }
    
    int m;
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++) {
        if (front != NULL) {
            front = front->next;
        }
    }
    
    struct Node* temp = front;
    for(int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    return 0;
}
