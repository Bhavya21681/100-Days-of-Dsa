/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, key, i, val;
    scanf("%d", &n);

    struct node* head = NULL;
    struct node* tail = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node* nn = newNode(val);
        if(head == NULL) {
            head = nn;
            tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }
    }

    scanf("%d", &key);

    struct node* curr = head;
    struct node* prev = NULL;

    while(curr != NULL) {
        if(curr->data == key) {
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    curr = head;
    while(curr != NULL) {
        printf("%d", curr->data);
        if(curr->next != NULL) printf(" ");
        curr = curr->next;
    }

    return 0;
}
