/*Problem Statement: Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.*/
#include<stdio.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;
    int last = arr[0];
    int i;
    for(i = 1; i < n; i++) {
        if(arr[i] - last >= dist) {
            count++;
            last = arr[i];
            if(count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[100];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    
    int low = 1, high = arr[n-1] - arr[0];
    int ans = 0;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
