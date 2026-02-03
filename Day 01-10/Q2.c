/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.*/
#include <stdio.h>

int main() {
    int n, i;
    int arr[1005];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos;
    scanf("%d", &pos);
    
    // shift left from pos to end
    for(i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    
    // now we have n-1 elements
    for(i = 0; i < n-1; i++) {
        printf("%d", arr[i]);
        if(i < n-2) printf(" ");
    }
    printf("\n");
    
    return 0;
}
