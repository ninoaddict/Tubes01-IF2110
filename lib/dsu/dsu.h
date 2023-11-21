#ifndef DSU_H
#define DSU_H
#include "../boolean.h"
#include <stdio.h>

extern int parent[20];

// Inisialisasi terhadap vertex v
void makeSet(int n);

// Mencari Parent
int findParent(int v);

// Menggabungkan 2 set
void unionSet(int u, int v);
#endif