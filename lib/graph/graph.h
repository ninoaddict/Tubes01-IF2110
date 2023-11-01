#ifndef GRAPH_H
#define GRAPH_H
#include "../boolean.h"

typedef struct
{
    boolean adjMat[20][20];
    int Neff;
} Graph;

void CreateGraph(Graph * graph);

#endif