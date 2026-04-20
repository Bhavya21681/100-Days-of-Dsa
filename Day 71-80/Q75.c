/*Problem Statement: Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.*/
#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    int x;
    
    while(scanf("%d", &x) == 1) {
        arr[n++] = x;
    }
    
    int max_len = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0 && (j - i + 1) > max_len) {
                max_len = j - i + 1;
            }
        }
    }
    
    printf("%d\n", max_len);
    return 0;
}
