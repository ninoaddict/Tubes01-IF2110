#include "../maxheap.h"
#include <stdio.h>
int main(){
    PriorityQueue pq;
    CreatePriorityQueue(&pq);
    pii a, b, c, d, e;
    a.first = 1;
    a.second = 2;
    b.first = 2;
    b.second = 1;
    c.first = 3;
    c.second = 5;
    d.first = 4;
    d.second = -1;
    e.first = 5;
    e.second = 10;
    enqueue(&pq, a);
    enqueue(&pq, b);
    enqueue(&pq, c);
    enqueue(&pq, d);
    enqueue(&pq, e);
    pii val;
    while (!isPQEmpty(pq)){
        dequeue(&pq, &val);
        printf("%d %d\n", val.first, val.second);
    }
}