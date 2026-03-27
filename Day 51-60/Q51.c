/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if(root == NULL) return create(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

int findLCA(struct Node* root, int p, int q) {
    if(root == NULL) return -1;
    if(p < root->data && q < root->data)
        return findLCA(root->left, p, q);
    if(p > root->data && q > root->data)
        return findLCA(root->right, p, q);
    return root->data;
}

int main() {
    int n, val, p, q;
    scanf("%d", &n);
    struct Node* root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &p, &q);
    printf("%d\n", findLCA(root, p, q));
    return 0;
}
