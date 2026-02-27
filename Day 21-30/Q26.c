/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

int main() {
    int n, i;
    scanf("%d", &n);

    struct node *head = NULL;
    struct node *tail = NULL;

    for(i = 0; i < n; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    struct node *temp = head;
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL) printf(" ");
        temp = temp->next;
    }

    return 0;
}
