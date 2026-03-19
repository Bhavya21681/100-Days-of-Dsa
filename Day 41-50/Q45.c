/*Problem Statement: Find the height (maximum depth) of a given binary tree.*/
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

TreeNode* buildTree(int* levelOrder, int n) {
    if (n == 0 || levelOrder[0] == -1) return NULL;
    
    TreeNode* root = newNode(levelOrder[0]);
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    int i = 1;
    
    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];
        

        if (i < n && levelOrder[i] != -1) {
            curr->left = newNode(levelOrder[i]);
            queue[rear++] = curr->left;
        }
        i++;
        
       
        if (i < n && levelOrder[i] != -1) {
            curr->right = newNode(levelOrder[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int levelOrder[1000];
    for(int i = 0; i < N; i++) {
        scanf("%d", &levelOrder[i]);
    }
    
    TreeNode* root = buildTree(levelOrder, N);
    printf("%d\n", maxDepth(root));
    
    return 0;
}
