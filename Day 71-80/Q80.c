/*Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long long d[100][100];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &d[i][j]);
            if (d[i][j] == -1 && i != j)
                d[i][j] = 1e15;
        }
    }
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) printf(" ");
            if (d[i][j] >= 1e14)
                printf("-1");
            else
                printf("%lld", d[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
