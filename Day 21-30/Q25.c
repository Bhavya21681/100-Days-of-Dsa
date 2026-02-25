/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, key, i;
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

    struct node *curr = head, *prev = NULL;

    while(curr) {
        if(curr->data == key) {
            if(prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    curr = head;
    while(curr) {
        printf("%d", curr->data);
        if(curr->next) printf(" ");
        curr = curr->next;
    }

    return 0;
}
