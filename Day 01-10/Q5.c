/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/
#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    int a[1005];
    for(int i = 0; i < p; i++) scanf("%d", &a[i]);
    
    int q;
    scanf("%d", &q);
    int b[1005];
    for(int i = 0; i < q; i++) scanf("%d", &b[i]);
    
    int i = 0, j = 0;
    int first = 1;
    
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            if(!first) printf(" ");
            printf("%d", a[i]);
            first = 0;
            i++;
        } else {
            if(!first) printf(" ");
            printf("%d", b[j]);
            first = 0;
            j++;
        }
    }
    
    while(i < p) {
        if(!first) printf(" ");
        printf("%d", a[i]);
        first = 0;
        i++;
    }
    
    while(j < q) {
        if(!first) printf(" ");
        printf("%d", b[j]);
        first = 0;
        j++;
    }
    printf("\n");
    
    return 0;
})
