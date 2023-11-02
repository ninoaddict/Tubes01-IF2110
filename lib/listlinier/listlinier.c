#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


Address newNode(ElType val)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL; 
    }
    return p;

}

void CreateList(List *l){
     FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx){
    List p = l ;
    int i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
    int i = 0;
    List p = *l;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val){
    int i = 0;
    List p = l;
    boolean found = false;
    while (p != NULL && !found){
        if (INFO(p).id == val.id){
            found = true;
        }
        else{
            i++;
            p = NEXT(p);
        }
    }
    if (found){
        return i;
    }
    else {
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val){
    Address p;
    p = newNode(val);
    if (p == NULL){

    }
    else{
        NEXT(p) = *l;
        *l = p; 
    }
}

void insertLast(List *l, ElType val){
    Address p;
    p = newNode(val);
    if (p == NULL){

    }
    else{
        if (isEmpty(*l)){
            insertFirst(l,val);
        }
        else{
            Address p2 = *l;
            while (NEXT(p2) != NULL){
                p2 = NEXT(p2);
            }
            NEXT(p2) = p;
        }
        
    }
}

void insertAt(List *l, ElType val, int idx){
    Address p = *l;
    
    int i = 0;
    Address pcontainer = newNode(val);
    if (pcontainer == NULL){

    }
    else{
        if (idx ==0){
            insertFirst(l,val);
        }
        else{
            while (i < idx - 1){
                p = NEXT(p);
                i++;
            }
            NEXT(pcontainer) = NEXT(p);
            NEXT(p) = pcontainer; // mu
        }
    }

}

void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);

    if (NEXT(p) == NULL){
        *l = NULL;
        free(*l);
        CreateList(l);

    }
    else{
        *l = NEXT(p);


    }
    free(p);
}

void deleteLast(List *l, ElType *val){
    List p = *l;
    *val = INFO(p);

    if (NEXT(p) == NULL){
        *l = NULL;
        free(*l);
        CreateList(l);
    }
    else{
        Address before = NULL;
        while (NEXT(p) != NULL){
            before =  p;
            p = NEXT(p);
        }
        if (before == NULL){
            *l = NULL;
        }
        else{
            NEXT(before) = NULL;
        }
        *val = INFO(p);
        free(p);

    }
}

void deleteAt(List *l, int idx, ElType *val){
    int i = 0;
    Address p, before;
    p = *l;
    before = NULL;

    if (NEXT(*l) == NULL){
        deleteFirst(l,val);
    }
    else{
        if (idx == 0){
            deleteFirst(l, val);

        }
        else{
            while (i < idx){
                before = p;
                p = NEXT(p);
                i++;
            }
            *val = INFO(p);
            NEXT(before) = NEXT(p);
            NEXT(p) = NULL;
            free(p);


        }
    }
}

void displayList(List l){
    printf("[");
    Address p = l;
    while (p != NULL){
        if (NEXT(p) != NULL){
            printf("%d,",INFO(p));
        }
        else{
            printf("%d",INFO(p));
        }
        p = NEXT(p);
        
    }
    

    printf("]");

}

int length(List l){
    int count = 0;
    Address p = l;
    while (p != NULL){
        count ++;
        p = NEXT(p);
    }
    return count;
   

}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p1 = l1, p2 = l2;

    while (p1 != NULL){
        insertLast(&l3,INFO(p1));
        p1 = NEXT(p1);
    }
    while (p2 != NULL){
        insertLast(&l3,INFO(p2));
        p2 = NEXT(p2);
    }
    return l3;

}

