#include "thread.h"
#include <stdlib.h>
#include <stdio.h>

AddressUtas newNode(DATETIME date, Word text){
    AddressUtas p = (AddressUtas) malloc(sizeof(Utas));
    DATE(p) = date;
    TEXT(p) = text;
    NEXT(p) = NULL;
    return p;
}

void CreateUtas(ListUtas*l){
    FIRST(*l) = NULL;
}

boolean isEmpty(ListUtas l){
    return (FIRST(l) == NULL);
    
}

void insertFirstListUtas(ListUtas *l, DATETIME date, Word text){
    AddressUtas p;
    
    p = newNode(date,text);
    if (p == NULL){

    }
    else{
        NEXT(p) = *l;
        *l = p;
    }
}


void insertLastListUtas(ListUtas* l, DATETIME date, Word text){
    AddressUtas p = newNode(date,text);
    if (p == NULL){

    }
    else{
        if(isEmpty(*l)){
            insertFirstListUtas(l,date,text);

        }
        else{
            AddressUtas p2 = *l;
            while (NEXT(p2) != NULL){
                p2 = NEXT(p2);
            }
            NEXT(p2) = p;
        }
    }
}

void displayListUtas(ListUtas l, Word author){
    AddressUtas p = l;
    int index = 0;
    printf("\n");
    while (p != NULL){
        index += 1;
        printf("   | INDEX = %d\n",index);
        printf("   | ");displayWordWithoutEnter(author);printf("\n");
        printf("   | ");TulisDATETIME(DATE(p));printf("\n");
        printf("   | ");displayWordWithoutEnter(TEXT(p));printf("\n");printf("\n");

        p = NEXT(p);
    }
}