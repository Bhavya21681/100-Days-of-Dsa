/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);
    
    struct node* head = NULL;
    struct node* tail = NULL;
    
    for(i = 0; i < n; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;
        
        if(head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    struct node* ptr = head;
    int first = 1;
    
    while(ptr != NULL) {
        if(ptr->coef == 0) {
            ptr = ptr->next;
            continue;
        }
        
        if(!first) {
            printf(" + ");
        }
        
        if(ptr->coef != 1 && ptr->coef != -1) {
            printf("%d", ptr->coef);
        } else if(ptr->coef == -1) {
            printf("-");
        }
        
        if(ptr->exp == 1) {
            printf("x");
        } else if(ptr->exp > 1) {
            printf("x^%d", ptr->exp);
        }
        
        first = 0;
        ptr = ptr->next;
    }
    
    if(first) {
        printf("0");
    }
    
    printf("\n");
    
    return 0;
}
