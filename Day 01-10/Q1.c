/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.*/
#include <stdio.h>

int main() {
    int n, i;
    int arr[1005];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos, x;
    scanf("%d %d", &pos, &x);
    
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    
    arr[pos-1] = x;
    
    for(i = 0; i < n+1; i++) {
        printf("%d", arr[i]);
        if(i < n) printf(" ");
    }
    printf("\n");
    
    return 0;
}
