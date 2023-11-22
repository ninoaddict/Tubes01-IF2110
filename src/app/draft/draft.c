#include <stdio.h>
#include <stdlib.h>
#include "draft.h"

Address newNodeDraft(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateDraft(Draft *d, Word w, DATETIME time){
    WORD(*d) = w;
    TIME(*d) = time;
}

void CreateStackDraft(StackDraft *sd){
    ADDR_TOP(*sd) = NULL;
}

void pushDraft(StackDraft *sd, ElType d){
    Address p = newNodeDraft(d);
    NEXT(p) = ADDR_TOP(*sd);
    ADDR_TOP(*sd) = p;
}

void deleteDraft(StackDraft *sd, ElType *d){
    *d = TOP(*sd);
    Address p = ADDR_TOP(*sd);
    ADDR_TOP(*sd) = NEXT(ADDR_TOP(*sd));
    NEXT(p) = NULL;
    free(p);
}

boolean isEmptyDraft(StackDraft sd){
    return ADDR_TOP(sd)==NULL;
}

void seeDraft(StackDraft sd){
    printf("Ini draf terakhir anda:\n");
    printf("| %d/%d/%d %d:%d:%d\n", INFO(ADDR_TOP(sd)).time.DD, INFO(ADDR_TOP(sd)).time.MM, INFO(ADDR_TOP(sd)).time.YYYY, INFO(ADDR_TOP(sd)).time.T.HH, INFO(ADDR_TOP(sd)).time.T.MM, INFO(ADDR_TOP(sd)).time.T.SS);
    printf("| ");
    displayWord(INFO(ADDR_TOP(sd)).word);
}

void publishDraft(int id_kicau, int id_user, Word user_name, Kicauan *k, ElType d,Word author, int idAuthor){
    DATETIME t;
    BacaDATETIME(&t);
    createKicauan(id_kicau, d.word, 0, author, t, k, idAuthor);
}