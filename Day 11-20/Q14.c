/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int is_identity = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if(i == j) {
                if(x != 1) is_identity = 0;
            } else {
                if(x != 0) is_identity = 0;
            }
        }
    }
    
    if(is_identity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");
        
    return 0;
}
