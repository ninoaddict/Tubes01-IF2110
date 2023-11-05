#include "tweet.h"
#include <stdio.h>
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"



void createKicauan(int id, Word text, int like, Word author, DATETIME time, Kicauan* kic,int idAuthor){
    ID(*kic) = id;
    TEXTKICAU(*kic) = text;
    LIKE(*kic) = like;
    AUTHOR(*kic) = author;
    DATEKICAU(*kic) = time;
    UTAS(*kic) = NULL;
    IDUTAS(*kic) = -1;
    IDAUTHOR(*kic) = idAuthor;
}

void displayKicau(Kicauan kic){
    printf("| ID = %d\n",ID(kic));
    printf("| ");
    displayWordWithoutEnter(AUTHOR(kic));
    printf("\n");
    printf("| ");
    TulisDATETIME(DATEKICAU(kic));
    printf("\n");
    printf("| ");
    displayWordWithoutEnter(TEXTKICAU(kic));
    printf("\n");
    printf("Disukai: %d\n",LIKE(kic));
}

