/*Problem: Perform BFS from a given source using queue.*/
#include <stdio.h>

int adj[100][100];
int visited[100];
int queue[100];
int n;

int main() {
    int s, m, front = 0, rear = 0;
    
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
        adj[v][u] = 1;  
    }
    
    scanf("%d", &s);
    
    // BFS starts
    printf("%d ", s);
    visited[s] = 1;
    queue[rear++] = s;
    
    while(front < rear) {
        int u = queue[front++];
        
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && visited[v] == 0) {
                printf("%d ", v);
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    
    printf("\n");
    return 0;
}
