#include "priorityqueue.h"
#include <stdio.h>
/*IMPLEMENTASI PRIORITY QUEUE DENGAN MIN HEAP*/


/*CONSTRUCTOR*/
void CreatePriorityQueue(PriorityQueue *pq){
    pq->count = 0;
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

void makeHeap(PriorityQueue *pq, int i)
{
    if (pq->count != 1)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * 1 + 2;
        if (l < pq->count && pq->pair[l].second > pq->pair[largest].second)
            largest = l;
        if (r < pq->count && pq->pair[r].second > pq->pair[largest].second)
            largest = r;
        if (largest != i)
        {
            swap(&(pq->pair[largest]), &(pq->pair[i]));
            makeHeap(pq, largest);
        }
    }
}

void enqueue(PriorityQueue *pq, pii newVal)
{
    if (!pq->count)
    {
        pq->pair[0] = newVal;
        pq->count = pq->count + 1;
    }
    else
    {
        if (pq->count == maxN)
        {
            if (pq->pair[pq->count - 1].second < newVal.second)
            {
                pq->pair[pq->count - 1].second = newVal.second;
            }
            else
                return;
        }
        else
        {
            pq->pair[pq->count] = newVal;
            pq->count = pq->count + 1;
        }
        for (int i = (pq->count / 2) - 1; i >= 0; i--)
        {
            makeHeap(pq, i);
        }
    }
}

void dequeue(PriorityQueue *pq, pii *val)
{
    swap(&pq->pair[0], &pq->pair[pq->count - 1]);
    pq->count = pq->count - 1;
    for (int i = (pq->count / 2) - 1; i >= 0; i--)
    {
        makeHeap(pq, i);
    }
}

void front(PriorityQueue pq){
    return pq.pair[0];
}

void PQLength(PriorityQueue pq){
    return pq.count;
}