/*Problem: Detect cycle in directed graph using DFS and recursion stack.*/
#include <stdio.h>

int adj[100][100];
int visited[100];
int recStack[100];
int n;

int dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;
    
    for(int v = 0; v < n; v++) {
        if(adj[u][v] == 1) {
            if(recStack[v] == 1) return 1;
            if(visited[v] == 0 && dfs(v)) return 1;
        }
    }
    
    recStack[u] = 0;
    return 0;
}

int main() {
    int m, i;
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    
    int hasCycle = 0;
    
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            if(dfs(i)) {
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
