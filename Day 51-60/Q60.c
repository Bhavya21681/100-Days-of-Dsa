/*Problem Statement: Check whether a given binary tree satisfies the Min-Heap property.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int isHeap = 1;
    
    for(int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n && a[i] > a[left]) {
            isHeap = 0;
            break;
        }
        if(right < n && a[i] > a[right]) {
            isHeap = 0;
            break;
        }
    }
    
    if(isHeap == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}  
