/*Problem: Height of Binary Tree*/
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


int height(TreeNode* root) {
    if (root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[1000];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode* root = buildTree(arr, N);
    printf("%d\n", height(root));

    return 0;
}
