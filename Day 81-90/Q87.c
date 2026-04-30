/*Problem: Implement Binary Search Iterative - Implement the algorithm.*/
#include<stdio.h>

int main() {
    int n, i, target, low, high, mid, ans = -1;
    scanf("%d", &n);
    int arr[100];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    
    low = 0;
    high = n - 1;
    
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            break;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
