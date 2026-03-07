/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);
    
    struct node* head = NULL;
    struct node* tail = NULL;
    
    for(i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        
        if(head == NULL) {
            head = newnode;
            tail = newnode;
            newnode->next = head;
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }
    
    if(head != NULL) {
        struct node* temp = head;
        do {
            printf("%d", temp->data);
            if(temp->next != head) {
                printf(" ");
            }
            temp = temp->next;
        } while(temp != head);
    }
    
    printf("\n");
    
    return 0;
}
