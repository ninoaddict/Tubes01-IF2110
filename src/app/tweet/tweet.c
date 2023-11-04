#include "tweet.h"
#include <stdio.h>
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"



void createKicauan(int id, Word text, int like, Word author, DATETIME time, Kicauan* kic,int idAuthor){
    ID(*kic) = id;
    TEXT(*kic) = text;
    LIKE(*kic) = like;
    AUTHOR(*kic) = author;
    DATE(*kic) = time;
    UTAS(*kic) = NULL;
    IDAUTHOR(*kic) = idAuthor;
}

void displayKicau(Kicauan kic){
    printf("| ID = %d\n",ID(kic));
    printf("| ");
    displayWordWithoutEnter(AUTHOR(kic));
    printf("\n");
    printf("| ");
    TulisDATETIME(DATE(kic));
    printf("\n");
    printf("| ");
    displayWordWithoutEnter(TEXT(kic));
    printf("\n");
    printf("Disukai: %d\n",LIKE(kic));
}

