#include <stdio.h>
#include "listkicauan.h"


void createListKicauan(ListKicauan* l, int capacity){
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType*) malloc(sizeof(ElType)*capacity);
}
void dealocateListKicauan(ListKicauan *l)
{
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

void bacaKicauan(ListKicauan* lkic, User currUser, int* IdKicau,int idAuthor){
    printf("Masukkan kicauan:\n");
    Word text;
    text = readWord(280);
    if(text.Length == 0){
        printf("\n");
        printf("Kicauan tidak boleh hanya berisi spasi!");
    }
    else{
        // *IdKicau += 1; // Idkicau dianggap 0 di main
        DATETIME time;
        BacaDATETIME(&time);
        if(isFullListKicauan(*lkic)){
            expandListKicauan(lkic,2*NEFF(*lkic));
        }
        createKicauan( NEFF(*lkic) + 1, text, 0, currUser.name,time,&((*lkic).buffer[NEFF(*lkic)]),idAuthor);
        NEFF(*lkic) += 1;
        *IdKicau = NEFF(*lkic) - 1;
        printf("\n");
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        displayKicau((*lkic).buffer[*IdKicau]);
    }


}
boolean userOwnsKicau(ListKicauan lkic, int currIdx, int idKicau){
    return(ELMT(lkic,idKicau-1).idAuthor == currIdx);
}

void displayListKicauan(ListKicauan lkic, Friend friend , int currId){
    int i;

    for (i = 0 ; i < NEFF(lkic) ; i++){
       if (ELMT(lkic,i).idAuthor == currId){
        displayKicau(ELMT(lkic,i));
        printf("\n");
       }
       else if (isFriend(friend,currId,ELMT(lkic,i).idAuthor)){
        displayKicau(ELMT(lkic,i));
        printf("\n");
       }
    }

}
void copyListKicauan(ListKicauan lIn, ListKicauan* lOut){
    int i;
    createListKicauan(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn) ; ++i){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }

}

void expandListKicauan(ListKicauan *l, int num){
    ListKicauan lstore;
    int i;
    createListKicauan(&lstore,CAPACITY(*l) + num);
    NEFF(lstore) = NEFF(*l);
    for (i = 0 ; i < NEFF(*l) ; ++i){
        ELMT(lstore,i) = ELMT(*l,i);
    }
    dealocateListKicauan(l);
    copyListKicauan(lstore,l);

}

boolean isFullListKicauan(ListKicauan l){
    return (NEFF(l) == CAPACITY(l));
}

void likeKicau(ListKicauan* lkic,ListUser lUser,Friend friend, int idKicauYangInginDiLike, int currIdx){
    if (idKicauYangInginDiLike < 1 || idKicauYangInginDiLike > NEFF(*lkic)){
        printf("Tidak ditemukan kicauan dengan ID = %d\n",idKicauYangInginDiLike);
    
    }
    else{
        int idUser = (*lkic).buffer[idKicauYangInginDiLike-1].idAuthor; // lokasi user di listuser
        if (lUser.listU[idUser].accType || isFriend(friend,idUser,currIdx)){ // jika public atau friend
        LIKE((*lkic).buffer[idKicauYangInginDiLike-1]) += 1;
        printf("Selamat! kicauan telah disukai!\n");
        printf("Detil kicauan:\n");
        displayKicau(ELMT(*lkic,idKicauYangInginDiLike-1));


        }
        else{
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu\n");
        }
        
    }
}

void updateKicau(ListKicauan* lkic, int currIdx, int idKicau){
    if(idKicau < 1 || idKicau > NEFF(*lkic)){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n",idKicau);

    }
    else if (userOwnsKicau(*lkic, currIdx, idKicau)){
        printf("Masukkan kicauan baru:\n");
        Word text;
        text = readWord(280);
        printf("\n");
        if(text.Length == 0){
            printf("Kicauan tidak boleh hanya berisi spasi!");
        }
        else{
            printf("Selamat! kicauan telah diterbitkan!\n");
            ELMT(*lkic,idKicau-1).text = text;
            displayKicau(ELMT(*lkic,idKicau-1));

        }
        printf("\n");
    }
    else{
        printf("Kicauan dengan ID = %d bukan milikmu!\n",idKicau);
        
    }

}


void makeKicauanUtama(ListUtas l, ListKicauan* lkic, int currIdx,int idKicau,int* idUtas){
    
}