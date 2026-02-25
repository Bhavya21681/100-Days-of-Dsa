/*Problem: Count Nodes in Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);
    
    struct node* head = NULL;
    struct node* temp = NULL;
    
    for(i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if(head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }
    
    temp = head;
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    
    return 0;
}
