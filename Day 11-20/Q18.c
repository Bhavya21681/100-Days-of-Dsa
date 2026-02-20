/*Problem: Given an array of integers, rotate the array to the right by k positions.*/
#include <stdio.h>

int main() {
    int n, k, arr[100000];
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    scanf("%d", &k);
    k %= n;
    
    for(int i = n-k; i < n; i++)
        printf("%d ", arr[i]);
    for(int i = 0; i < n-k; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
