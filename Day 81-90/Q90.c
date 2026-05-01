/*Problem Statement : Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.*/
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int boards[100];
    long long total = 0;
    int max_board = 0;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        total += boards[i];
        if(boards[i] > max_board) {
            max_board = boards[i];
        }
    }
    
    long long low = max_board;
    long long high = total;
    long long ans = total;
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        
        int painters = 1;
        long long curr = 0;
        
        for(int i = 0; i < n; i++) {
            if(curr + boards[i] > mid) {
                painters++;
                curr = boards[i];
            } else {
                curr += boards[i];
            }
        }
        
        if(painters <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}
