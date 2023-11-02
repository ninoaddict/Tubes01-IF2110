#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"

#define maxN 40

typedef struct
{
    int first;
    int second;
}pii; // pair of integer

typedef struct
{
    int count;
    pii pair[maxN];
} PriorityQueue;

/*CONSTRUCTOR*/
void CreatePriorityQueue(PriorityQueue *pq);
boolean isEmpty(PriorityQueue pq);
boolean isFull(PriorityQueue pq);

/*OPERATION*/
void swap(pii *a, pii *b);
void makeHeap(PriorityQueue *pq, int i);
void enqueue(PriorityQueue *pq, pii val);
void dequeue(PriorityQueue *pq, pii *val);

/*INFO*/
void front(PriorityQueue pq);
void PQLength(PriorityQueue pq);
