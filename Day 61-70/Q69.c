/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Pair;

typedef struct {
    Pair heap[MAX];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq) {
    pq->size = 0;
}

void swap(Pair *a, Pair *b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void push(PriorityQueue *pq, int v, int w) {
    pq->heap[pq->size].v = v;
    pq->heap[pq->size].w = w;
    int i = pq->size;
    pq->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq->heap[i].w >= pq->heap[p].w) break;
        swap(&pq->heap[i], &pq->heap[p]);
        i = p;
    }
}

Pair pop(PriorityQueue *pq) {
    Pair res = pq->heap[0];
    pq->size--;
    pq->heap[0] = pq->heap[pq->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < pq->size && pq->heap[l].w < pq->heap[smallest].w)
            smallest = l;
        if (r < pq->size && pq->heap[r].w < pq->heap[smallest].w)
            smallest = r;
        if (smallest == i) break;
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return res;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int main() {
    int n, m, src;
    scanf("%d %d %d", &n, &m, &src);
    
    int adj[MAX][MAX] = {0};
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    
    PriorityQueue pq;
    initPQ(&pq);
    push(&pq, src, 0);
    
    while (!isEmpty(&pq)) {
        Pair p = pop(&pq);
        int u = p.v;
        int d = p.w;
        
        if (d > dist[u]) continue;
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0) {
                int newd = dist[u] + adj[u][v];
                if (newd < dist[v]) {
                    dist[v] = newd;
                    push(&pq, v, newd);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d ", -1);
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
    
    return 0;
}
