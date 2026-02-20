/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.*/
#include <stdio.h>

int main() {
    int n, arr[100005] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", arr+i);
    
    long long sum = 0;
    int cnt = 0, mp[200010] = {0};
    mp[100005] = 1;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        cnt += mp[sum + 100005];
        mp[sum + 100005]++;
    }
    
    printf("%d\n", cnt);
    return 0;
}
