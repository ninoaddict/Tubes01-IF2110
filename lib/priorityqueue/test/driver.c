#include "../priorityqueue.h"
int main(){
PriorityQueue pq;
    CreatePriorityQueue(&pq);
    pii a, b, c, d, e, f;
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
    f.first = 3;
    f.second = 12;
    enqueue(&pq, a);
    enqueue(&pq, b);
    enqueue(&pq, c);
    enqueue(&pq, d);
    enqueue(&pq, e);
    enqueue(&pq, f);
    // while (!isPQEmpty(pq)){
    //     pii temp;
    //     dequeue(&pq, &temp);
    //     printf("%d %d\n", temp.first, temp.second);
    // }
    printf("%d\n", PQLength(pq));
    pii val;
    dequeue(&pq, &val);
    printf("%d %d\n", val.first, val.second);
    dequeue(&pq, &val);
    printf("%d %d\n", val.first, val.second);
}