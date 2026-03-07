/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, k, i;
    scanf("%d", &n);
    
    struct node* head = NULL;
    struct node* tail = NULL;
    
    for(i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if(head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    scanf("%d", &k);
    
    if(n == 0 || k == 0) {
    } else {
        k = k % n;
        if(k != 0) {
            struct node* temp = head;
            for(i = 1; i < n - k; i++) {
                temp = temp->next;
            }
            tail->next = head;
            head = temp->next;
            temp->next = NULL;
        }
    }
    
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("%d", ptr->data);
        if(ptr->next != NULL) printf(" ");
        ptr = ptr->next;
    }
    printf("\n");
    
    return 0;
}
