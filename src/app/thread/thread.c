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

boolean isEmptyUtas(ListUtas l){
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
        if(isEmptyUtas(*l)){
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




void deleteFirstListUtas(ListUtas *l, DATETIME* date, Word* text){
    AddressUtas p = *l;
    *date = DATEUTAS(p);
    *text = TEXTUTAS(p);

    if (NEXTUTAS(p) == NULL){
        *l = NULL;
        free(*l);
        CreateUtas(l);
    }
    else{
        *l = NEXTUTAS(p);
    }
    free(p);

}
void deleteLastListUtas(ListUtas *l, DATETIME* date, Word* text){
    AddressUtas p = *l;
    *date = DATEUTAS(p);
    *text = TEXTUTAS(p);

    if (NEXTUTAS(p) == NULL){
        *l = NULL;
        free(*l);
        CreateUtas(l);
    }
    else{
        AddressUtas before = NULL;
        while (NEXTUTAS(p) != NULL){
            before =  p;
            p = NEXTUTAS(p);
        }
        if (before == NULL){
            *l = NULL;
        }
        else{
            NEXTUTAS(before) = NULL;
        }
        *date = DATEUTAS(p);
        *text = TEXTUTAS(p);
        free(p);
        
    }
}

void deleteAtListUtas(ListUtas *l, int idx ,DATETIME* date, Word* text){
    idx -= 1;
    int i = 0;
    AddressUtas p, before;
    p = *l;
    before = NULL;

    if (NEXTUTAS(*l) == NULL){
        deleteFirstListUtas(l,date,text);
    }
    else{
        if (idx == 0){
            deleteFirstListUtas(l, date,text);

        }
        else{
            while (i < idx){
                before = p;
                p = NEXTUTAS(p);
                i++;
            }
            *date = DATEUTAS(p);
            *text = TEXTUTAS(p);
            NEXTUTAS(before) = NEXTUTAS(p);
            NEXTUTAS(p) = NULL;
            free(p);
            


        }
    }
}
