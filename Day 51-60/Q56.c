/*Problem Statement: Check whether a given binary tree is symmetric around its center.*/
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

int isMirror(struct Node* a, struct Node* b) {
    if(a == NULL && b == NULL) return 1;
    if(a == NULL || b == NULL) return 0;
    if(a->data != b->data) return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = build(arr, n);
    
    if(isMirror(root, root))
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
