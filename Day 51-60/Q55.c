/*Problem Statement: Print the nodes visible when the binary tree is viewed from the right side.*/
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

void rightView(struct Node* root) {
    if(root == NULL) return;
    
    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;
    
    while(front < rear) {
        int size = rear - front;
        for(int i = 0; i < size; i++) {
            struct Node* curr = q[front++];
            if(i == size - 1)
                printf("%d ", curr->data);
            
            if(curr->left) q[rear++] = curr->left;
            if(curr->right) q[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = build(arr, n);
    rightView(root);
    return 0;
}
