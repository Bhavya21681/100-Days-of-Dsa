/*Problem Statement: Using BFS or DFS, check if the entire graph is connected.*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int n;

void dfs(int u) {
    vis[u] = 1;
    for(int v = 0; v < n; v++) {
        if(adj[u][v] && !vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        vis[i] = 0;
    }
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    dfs(0);
    
    int connected = 1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            connected = 0;
            break;
        }
    }
    
    if(connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }
    
    return 0;
}
