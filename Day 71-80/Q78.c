/*Problem Statement: Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int graph[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    int key[MAX];
    int inMST[MAX];
    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }
    
    key[0] = 0;
    int total = 0;
    
    for(int count = 0; count < n; count++) {
        int min_val = INT_MAX;
        int u = -1;
        
        for(int i = 0; i < n; i++) {
            if(!inMST[i] && key[i] < min_val) {
                min_val = key[i];
                u = i;
            }
        }
        
        if(u == -1) break;
        
        inMST[u] = 1;
        total += min_val;
        
        for(int v = 0; v < n; v++) {
            if(graph[u][v] != INT_MAX && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    
    printf("%d\n", total);
    return 0;
}
