#include "priorityqueue.h"
#include <stdio.h>
/*IMPLEMENTASI PRIORITY QUEUE DENGAN MIN HEAP*/

/*CONSTRUCTOR*/
void CreatePriorityQueue(PriorityQueue *pq)
{
    pq->count = 0;
}

/*CHECK*/
boolean isPQEmpty(PriorityQueue pq)
{
    return !pq.count;
}

boolean isPQFull(PriorityQueue pq)
{
    return pq.count == maxN;
}

/*OPERATION*/

void swap(pii *a, pii *b)
{
    int tempFirst = a->first;
    a->first = b->first;
    b->first = tempFirst;
    int tempSecond = a->second;
    a->second = b->second;
    b->second = tempSecond;
}

void enqueue(PriorityQueue *pq, pii newVal)
{
    if (pq->count == maxN)
    {
        if (pq->pair[pq->count - 1].second < newVal.second)
            pq->pair[pq->count - 1] = newVal;
        else
            return;
    }
    else
    {
        pq->pair[pq->count] = newVal;
        pq->count = pq->count + 1;
    }
    int i = pq->count - 1;
    while (i > 0 && pq->pair[i].second > pq->pair[(i - 1) / 2].second)
    {
        swap(&pq->pair[i], &pq->pair[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dequeue(PriorityQueue *pq, pii *val){
    *val = pq->pair[0];
    swap(&pq->pair[0], &pq->pair[pq->count - 1]);
    pq->count = pq->count - 1;
    int i = 0;
    while ((2 * i + 1) < pq->count){
        int j = 2 * i + 1;
        if (2 * i + 2 < pq->count && pq->pair[2 * i + 2].second > pq->pair[j].second){
            j = 2 * i + 2;
        }
        if (pq->pair[j].second <= pq->pair[i].second){
            break;
        }
        swap(&pq->pair[j], &pq->pair[i]);
        i = j;
    }
} 

pii front(PriorityQueue pq)
{
    return pq.pair[0];
}

int PQLength(PriorityQueue pq)
{
    return pq.count;
}