#include "priorityqueue.h"

PQAddress newPQAddress(pii val){
    PQAddress new = (PQAddress) malloc(sizeof(PQNode));
    if (new != NULL){
        NEXT(new) = NULL;
        INFO(new) = val;
    }
    return new;
}

void CreatePriorityQueue(PriorityQueue *pq){
    *pq = NULL;
}

int PQLength(PriorityQueue pq){
    int cnt = 0;
    PQAddress currNode = pq;
    while (currNode != NULL){
        cnt++;
        currNode = NEXT(currNode);
    }
    return cnt;
}

boolean isPQEmpty(PriorityQueue pq){
    return pq == NULL;
}

void enqueue(PriorityQueue *pq, pii val){
    PQAddress newNode = newPQAddress(val);
    if (isPQEmpty(*pq)){
        FIRST(*pq) = newNode;
    }
    else{
        PQAddress currNode = FIRST(*pq);
        if (INFO(currNode).second < val.second){
            NEXT(newNode) = currNode;
            FIRST(*pq) = newNode;
        }
        else{
            boolean udah = false;
            while (NEXT(currNode) != NULL && !udah){
                if (INFO(NEXT(currNode)).second < val.second){
                    NEXT(newNode) = NEXT(currNode);
                    NEXT(currNode) = newNode;
                    udah = true;
                }
                currNode = NEXT(currNode);
            }
            if (!udah){
                NEXT(currNode) = newNode;
            }
        }
    }
}

void dequeue(PriorityQueue *pq, pii *val){
    *val = FRONT(*pq);
    PQAddress currNode = FIRST(*pq);
    FIRST(*pq) = NEXT(currNode);
    free(currNode);
}

void DisplayPriorityQueue(PriorityQueue q){
    printf("[");
    if (!isPQEmpty(q)){
        PQAddress currNode = FIRST(q);
        while (NEXT(currNode) != NULL){
            printf("%d %d,",INFO(currNode).first, INFO(currNode).second);
            currNode = NEXT(currNode);
        }
        printf("%d %d", INFO(currNode).first, INFO(currNode).second);
    }
    printf("]\n");
}