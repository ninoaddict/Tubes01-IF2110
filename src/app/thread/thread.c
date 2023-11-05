#include "thread.h"
#include <stdlib.h>
#include <stdio.h>

AddressUtas newNode(DATETIME date, Word text){
    AddressUtas p = (AddressUtas) malloc(sizeof(Utas));
    DATEUTAS(p) = date;
    TEXTUTAS(p) = text;
    NEXTUTAS(p) = NULL;
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
        NEXTUTAS(p) = *l;
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
            while (NEXTUTAS(p2) != NULL){
                p2 = NEXTUTAS(p2);
            }
            NEXTUTAS(p2) = p;
        }
    }
}

void insertAtListUtas(ListUtas *l, DATETIME date, Word text, int index){
    AddressUtas p = *l, pcontainer = newNode(date,text);
   
    index -= 1;
    int i = 0;
    if (pcontainer == NULL){
        printf("gagal membuat node\n\n");

    }
    else{
        if (index == 0){
            insertFirstListUtas(l,date,text);
        }
        else{
            while (i < index - 1){
                p = NEXTUTAS(p);
                i++;
            }
            NEXTUTAS(pcontainer) = NEXTUTAS(p);
            NEXTUTAS(p) = pcontainer;
            printf("\n\n");
        }
    }



}

void displayListUtas(ListUtas l, Word author){
    AddressUtas p = l;
    int index = 0;
    while (p != NULL){
        index += 1;
        printf("   | INDEX = %d\n",index);
        printf("   | ");displayWordWithoutEnter(author);printf("\n");
        printf("   | ");TulisDATETIME(DATEUTAS(p));printf("\n");
        printf("   | ");displayWordWithoutEnter(TEXTUTAS(p));printf("\n\n");

        p = NEXTUTAS(p);
    }
}