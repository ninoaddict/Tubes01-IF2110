#include <stdio.h>
#include "stacklinked.h"

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NIL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(Stack s){
    return (ADDR_TOP(s)==NIL);
}

int length(Stack s){
    Address p = ADDR_TOP(s);
    int count = 0;
    while (p != NIL){
        p = NEXT(p);
        count++;
    }
    return count;
}

void CreateStack(Stack *s){
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s){
    Address p = ADDR_TOP(s);
    printf("[");
    while (p!=NIL){
        printf("%d",INFO(p));
        if (NEXT(p) != NIL){
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

void push(Stack *s, ElType x){
    Address p = newNode(x);
    if (p != NIL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x){
    *x = TOP(*s);
    Address p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NIL;
    free(p);
}