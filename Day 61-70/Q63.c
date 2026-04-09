/*Problem: Perform DFS starting from a given source vertex using recursion.*/
#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int u) {
    printf("%d ", u);
    visited[u] = 1;
    
    for(int v = 0; v < n; v++) {
        if(adj[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int s, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // remove this line if graph is directed
    }
    
    scanf("%d", &s);
    
    dfs(s);
    printf("\n");
    
    return 0;
}
