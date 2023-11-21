# include "dsu.h"

int parent[20];

void makeSet(int n){
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int findParent(int v){
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v]);
}

void unionSet(int u, int v){
    u = findParent(u);
    v = findParent(v);
    if (u != v){
        parent[v] = u;
    }
}