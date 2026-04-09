/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>

int adj[100][100];
int indegree[100];
int queue[100];
int n;

int main() {
    int m, i, front = 0, rear = 0;
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int count = 0;
    
    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    
    printf("\n");
    return 0;
}
