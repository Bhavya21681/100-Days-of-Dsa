/*Problem: Level Order Traversal*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* root = newNode(arr[0]);
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];
        
        
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        
        
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}


void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left)  queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[1000];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode* root = buildTree(arr, N);
    levelOrder(root);
    printf("\n");  

    return 0;
}
