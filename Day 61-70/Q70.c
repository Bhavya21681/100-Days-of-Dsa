/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m, src;
    scanf("%d %d %d", &n, &m, &src);
    
    Edge edges[MAX];
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    int dist[MAX];
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    int neg = 0;
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            neg = 1;
            break;
        }
    }
    
    if(neg) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX)
                printf("-1 ");
            else
                printf("%d ", dist[i]);
        }
        printf("\n");
    }
    
    return 0;
}
