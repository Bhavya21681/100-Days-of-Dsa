/*Problem: Given an array of integers, find two elements whose sum is closest to zero.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100005];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min_sum = INT_MAX;
    int a = 0, b = 0;
    
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int abs_sum = abs(sum);
            
            if(abs_sum < min_sum) {
                min_sum = abs_sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }
    
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    printf("%d %d\n", a, b);
    
    return 0;
}
