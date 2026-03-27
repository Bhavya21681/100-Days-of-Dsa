/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.*/
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

struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    
    while(i < n && front < rear) {
        struct Node* curr = queue[front++];
        
        // Left child
        if(i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        
        // Right child
        if(i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    if(root == NULL) return NULL;
    if(root->data == p || root->data == q) return root;
    
    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);
    
    if(left && right) return root;
    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int p, q;
    scanf("%d %d", &p, &q);
    
    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, p, q);
    
    if(lca) printf("%d\n", lca->data);
    else printf("-1\n");
    
    return 0;
}
