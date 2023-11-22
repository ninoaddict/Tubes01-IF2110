#include "graph.h"

// CONSTRUCTOR
void CreateGraph(Graph *graph)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            graph->adjMat[i][j] = false;
        }
    }
    graph->Neff = 0;
}
