/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int freq[1000] = {0};
    
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] == arr[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == arr[i]) count++;
            }
            freq[i] = count;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(freq[i] > 0) {
            printf("%d:%d ", arr[i], freq[i]);
        }
    }
    printf("\n");
    
    return 0;
}
