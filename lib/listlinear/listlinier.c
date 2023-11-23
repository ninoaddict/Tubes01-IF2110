#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


Address newNodeLinear(ElType val)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL; 
    }
    return p;

}

void CreateListLin(List *l){
     FIRST(*l) = NULL;
}

boolean isEmptyLin(List l){
    return FIRST(l) == NULL;
}

ElType getElmtLin(List l, int idx){
    List p = l ;
    int i = 0;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmtLin(List *l, int idx, ElType val){
    int i = 0;
    List p = *l;
    while (i < idx){
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOfLin(List l, ElType val){
    int i = 0;
    List p = l;
    boolean found = false;
    while (p != NULL && !found){
        if (INFO(p) == val){
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

void insertFirstLin(List *l, ElType val){
    Address p;
    p = newNodeLinear(val);
    if (p == NULL){

    }
    else{
        NEXT(p) = *l;
        *l = p; 
    }
}

void insertLastLin(List *l, ElType val){
    Address p;
    p = newNodeLinear(val);
    if (p == NULL){

    }
    else{
        if (isEmptyLin(*l)){
            insertFirstLin(l,val);
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

void insertAtLin(List *l, ElType val, int idx){
    Address p = *l;
    
    int i = 0;
    Address pcontainer = newNodeLinear(val);
    if (pcontainer == NULL){

    }
    else{
        if (idx ==0){
            insertFirstLin(l,val);
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

void deleteFirstLin(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);

    if (NEXT(p) == NULL){
        *l = NULL;
        free(*l);
        CreateListLin(l);

    }
    else{
        *l = NEXT(p);


    }
    free(p);
}

void deleteLastLin(List *l, ElType *val){
    List p = *l;
    *val = INFO(p);

    if (NEXT(p) == NULL){
        *l = NULL;
        free(*l);
        CreateListLin(l);
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

void deleteAtLin(List *l, int idx, ElType *val){
    int i = 0;
    Address p, before;
    p = *l;
    before = NULL;

    if (NEXT(*l) == NULL){
        deleteFirstLin(l,val);
    }
    else{
        if (idx == 0){
            deleteFirstLin(l, val);

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

void displayListLin(List l){
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

int lengthLin(List l){
    int count = 0;
    Address p = l;
    while (p != NULL){
        count ++;
        p = NEXT(p);
    }
    return count;
   

}

List concatLin(List l1, List l2) {
    List l3;
    CreateListLin(&l3);
    Address p1 = l1, p2 = l2;

    while (p1 != NULL){
        insertLastLin(&l3,INFO(p1));
        p1 = NEXT(p1);
    }
    while (p2 != NULL){
        insertLastLin(&l3,INFO(p2));
        p2 = NEXT(p2);
    }
    return l3;

}

