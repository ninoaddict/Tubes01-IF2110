#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../pii/pii.h"

#define maxN 40

typedef struct
{
    int count;
    pii pair[maxN];
} MaxHeap;

/*CONSTRUCTOR*/
void CreateMaxHeap(MaxHeap *pq);

/*CHECK*/
boolean isMaxHeapEmpty(MaxHeap pq);
boolean isMaxHeapFull(MaxHeap pq);

/*OPERATION*/
void swap(pii *a, pii *b);
void enqueueMaxHeap(MaxHeap *pq, pii val);
void dequeueMaxHeap(MaxHeap *pq, pii *val);

/*INFO*/
pii maxHeapFront(MaxHeap pq);
int maxHeapLength(MaxHeap pq);
#endif