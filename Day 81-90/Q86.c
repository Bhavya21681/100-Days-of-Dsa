/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.*/
#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int low = 0, high = n, ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid * 1LL * mid == n) {
            printf("%d\n", mid);
            return 0;
        }
        if(mid * 1LL * mid < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
