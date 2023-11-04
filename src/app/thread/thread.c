#include "thread.h"
#include <stdlib.h>
#include <stdio.h>

AddressUtas newNode(DATETIME date, Word text){
    AddressUtas p = (AddressUtas) malloc(sizeof(Utas));
    DATE(p) = date;
    NEXT(p) = NULL;
}

void CreateUtas(ListUtas*l){
    FIRST(*l) = NULL;
}

boolean isEmpty(ListUtas l){
    return (FIRST(l) == NULL);
    
}
