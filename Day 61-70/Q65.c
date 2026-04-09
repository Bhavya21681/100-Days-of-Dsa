/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.*/
#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

int dfs(int u, int parent) {
    visited[u] = 1;
    
    for(int v = 0; v < n; v++) {
        if(adj[u][v] == 1) {
            if(v == parent) continue;
            if(visited[v] == 1) return 1;
            if(dfs(v, u)) return 1;
        }
    }
    return 0;
}

int main() {
    int m, i, j;
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int hasCycle = 0;
    
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            if(dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }
    
    if(hasCycle == 1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
