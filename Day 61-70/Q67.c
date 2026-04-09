/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>

int adj[100][100];
int visited[100];
int stack[100];
int top = -1;
int n;

void dfs(int u) {
    visited[u] = 1;
    
    for(int v = 0; v < n; v++) {
        if(adj[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
    
    stack[++top] = u;
}

int main() {
    int m, i;
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }
    
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    
    return 0;
}
