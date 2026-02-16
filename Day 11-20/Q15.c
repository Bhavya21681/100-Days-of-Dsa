/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.*/
#include <stdio.h>

int main() {
    int m, n, sum = 0;
    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if(i == j) sum += x;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
