/*Problem Statement : Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.*/
#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int sum(int arr[], int n) {
    int s = 0, i;
    for(i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int current = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(current + arr[i] > maxPages) {
            students++;
            current = arr[i];
            if(students > m) return 0;
        } else {
            current += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int low = 0, high = 0;
    for(i = 0; i < n; i++) {
        low = max(low, arr[i]);
        high += arr[i];
    }
    
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
