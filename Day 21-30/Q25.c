/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, key, i, count = 0;
    scanf("%d", &n);

    struct node *head = NULL, *tail = NULL;

    for(i = 0; i < n; i++) {
        struct node *nn = malloc(sizeof(struct node));
        scanf("%d", &nn->data);
        nn->next = NULL;

        if(!head) {
            head = nn;
            tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }
    }

    scanf("%d", &key);

    struct node *curr = head;
    while(curr) {
        if(curr->data == key) {
            count++;
        }
        curr = curr->next;
    }

    printf("%d", count);

    return 0;
}
