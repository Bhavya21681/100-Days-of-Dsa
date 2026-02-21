/*Problem: Create and Traverse Singly Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, x;
    scanf("%d", &n);
    
    struct node *head = NULL, *cur = NULL;
    
    while(n--) {
        scanf("%d", &x);
        struct node* temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        
        if(!head) head = temp;
        else cur->next = temp;
        cur = temp;
    }
    
    cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    
    return 0;
}
