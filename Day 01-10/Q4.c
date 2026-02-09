/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[1005];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int left = 0;
    int right = n - 1;
    
    while(left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
    
    for(int i = 0; i < n; i++) {
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}
