/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.*/
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
    int n, m, i, val;
    scanf("%d", &n);

    struct node* head1 = NULL;
    struct node* tail1 = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node* nn = newNode(val);
        if(head1 == NULL) {
            head1 = nn;
            tail1 = nn;
        } else {
            tail1->next = nn;
            tail1 = nn;
        }
    }

    scanf("%d", &m);

    struct node* head2 = NULL;
    struct node* tail2 = NULL;

    for(i = 0; i < m; i++) {
        scanf("%d", &val);
        struct node* nn = newNode(val);
        if(head2 == NULL) {
            head2 = nn;
            tail2 = nn;
        } else {
            tail2->next = nn;
            tail2 = nn;
        }
    }

    struct node* head = NULL;
    struct node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
            } else {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        } else {
            if(head == NULL) {
                head = head2;
                tail = head2;
            } else {
                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }
    }

    if(head1 != NULL) {
        if(head == NULL) {
            head = head1;
        } else {
            tail->next = head1;
        }
    }

    if(head2 != NULL) {
        if(head == NULL) {
            head = head2;
        } else {
            tail->next = head2;
        }
    }

    struct node* temp = head;
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL) printf(" ");
        temp = temp->next;
    }

    return 0;
}
