/*Problem Statement: Construct a binary tree from given preorder and inorder traversal arrays.*/
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

int search(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val) return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if(start > end) return NULL;
    
    int rootVal = preorder[(*preIndex)++];
    struct Node* root = newNode(rootVal);
    
    if(start == end) return root;
    
    int inIndex = search(inorder, start, end, rootVal);
    
    root->left = build(preorder, inorder, start, inIndex-1, preIndex);
    root->right = build(preorder, inorder, inIndex+1, end, preIndex);
    
    return root;
}

void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int preorder[1000], inorder[1000];
    for(int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    
    int preIndex = 0;
    struct Node* root = build(preorder, inorder, 0, n-1, &preIndex);
    
    postorder(root);
    return 0;
}
