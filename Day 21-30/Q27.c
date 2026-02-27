/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/
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

    struct node *head1 = NULL, *tail1 = NULL;
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node* nn = newNode(val);
        if(!head1) head1 = tail1 = nn;
        else {
            tail1->next = nn;
            tail1 = nn;
        }
    }

    scanf("%d", &m);

    struct node *head2 = NULL, *tail2 = NULL;
    for(i = 0; i < m; i++) {
        scanf("%d", &val);
        struct node* nn = newNode(val);
        if(!head2) head2 = tail2 = nn;
        else {
            tail2->next = nn;
            tail2 = nn;
        }
    }

    
    int len1 = 0, len2 = 0;
    struct node *p1 = head1, *p2 = head2;

    while(p1) { len1++; p1 = p1->next; }
    while(p2) { len2++; p2 = p2->next; }

  
    p1 = head1;
    p2 = head2;

    if(len1 > len2) {
        int diff = len1 - len2;
        while(diff--) p1 = p1->next;
    } else {
        int diff = len2 - len1;
        while(diff--) p2 = p2->next;
    }


    while(p1 && p2) {
        if(p1 == p2) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");

    return 0;
}
