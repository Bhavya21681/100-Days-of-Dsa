/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[1005];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    if(n == 0) {
        printf("\n");
        return 0;
    }
    
    int k = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[k-1]) {
            a[k] = a[i];
            k++;
        }
    }
    
    for(int i = 0; i < k; i++) {
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}
