/*Problem Statement: Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* build(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while(i < n && front < rear) {
        struct Node* curr = q[front++];
        if(i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;
        if(i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if(root == NULL) return;
    
    int map[200][1000];
    int count[200] = {0};
    int offset = 100;
    
    struct Pair q[1000];
    int front = 0, rear = 0;
    q[rear].node = root;
    q[rear].hd = 0;
    rear++;
    
    while(front < rear) {
        struct Node* node = q[front].node;
        int hd = q[front].hd;
        front++;
        
        map[hd + offset][count[hd + offset]++] = node->data;
        
        if(node->left) {
            q[rear].node = node->left;
            q[rear].hd = hd - 1;
            rear++;
        }
        if(node->right) {
            q[rear].node = node->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }
    
    for(int i = 0; i < 200; i++) {
        if(count[i] > 0) {
            for(int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = build(arr, n);
    verticalOrder(root);
    return 0;
}
