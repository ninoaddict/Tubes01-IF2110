#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../pii/pii.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct pqnode* PQAddress;
typedef struct pqnode
{
    pii info;
    PQAddress next;
} PQNode;

typedef PQAddress PriorityQueue;

#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define FRONT(pq) (pq)->info
#define FIRST(pq) (pq)

/* Constructor */
PQAddress newPQAddress(pii val);
void CreatePriorityQueue(PriorityQueue *pq);
void DisplayPriorityQueue(PriorityQueue pq);

/* Priority Queue Properties */
int PQLength(PriorityQueue pq);
boolean isPQEmpty(PriorityQueue pq);

/* Enqueue/Dequeue Primitive */
void enqueue(PriorityQueue *pq, pii val);
void dequeue(PriorityQueue *pq, pii *val);

#endif