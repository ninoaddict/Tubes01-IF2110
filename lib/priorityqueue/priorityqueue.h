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

/*CHECK*/
boolean isPQEmpty(PriorityQueue pq);
boolean isPQFull(PriorityQueue pq);

/*OPERATION*/
void swap(pii *a, pii *b);
void enqueue(PriorityQueue *pq, pii val);
void dequeue(PriorityQueue *pq, pii *val);

/*INFO*/
pii front(PriorityQueue pq);
int PQLength(PriorityQueue pq);
