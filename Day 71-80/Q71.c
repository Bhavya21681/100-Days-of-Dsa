/*Problem Statement: Implement a hash table using quadratic probing with formula*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

void init() {
    for(int i = 0; i < m; i++) table[i] = -1;
}

int hash(int k) {
    return k % m;
}

int search(int k) {
    int h = hash(k);
    for(int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if(table[pos] == -1) return 0;
        if(table[pos] == k) return 1;
    }
    return 0;
}

void insert(int k) {
    int h = hash(k);
    for(int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if(table[pos] == -1 || table[pos] == k) {
            table[pos] = k;
            return;
        }
    }
}

int main() {
    scanf("%d", &m);
    int q;
    scanf("%d", &q);
    
    init();
    
    char op[10];
    int val;
    for(int i = 0; i < q; i++) {
        scanf("%s %d", op, &val);
        if(strcmp(op, "INSERT") == 0) {
            insert(val);
        } else if(strcmp(op, "SEARCH") == 0) {
            if(search(val))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    
    return 0;
}
