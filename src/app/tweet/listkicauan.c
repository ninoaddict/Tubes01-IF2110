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


void makeKicauanUtama( ListKicauan* lkic, int currIdx,int idKicau,int* idUtas){
    if (userOwnsKicau(*lkic,currIdx,idKicau) && isEmpty((*lkic).buffer[idKicau-1].ut)){
        (*lkic).buffer[idKicau-1].idUtas = *idUtas;
        CreateUtas(&(*lkic).buffer[idKicau-1].ut);
        *idUtas += 1;
        Word text,yes;
        boolean done = false;
        do{
            
            DATETIME date;
            BacaDATETIME(&date);
            printf("\n");
            if (!done){
                printf("Utas berhasil dibuat!\n\n");
                done = true;

            }
            
            printf("Masukkan kicauan:\n");
            text = readWord(280);
            insertLastListUtas(&(*lkic).buffer[idKicau-1].ut,date,text);
            printf("\n");
            printf("Apakah Anda ingin melanjutkan utas ini?\n");
            text = readWord(5);
            
            
            yes.Length  = 3;
            yes.TabWord[0] = 'Y';
            yes.TabWord[1] = 'E';
            yes.TabWord[2] = 'S';




        }while(isWordEqual(text,yes));
        printf("Utas selesai!\n");

    }
    else if (!userOwnsKicau(*lkic,currIdx,idKicau)){
        printf("Utas ini bukan milik anda!\n");
    }
    else if (!isEmpty((*lkic).buffer[idKicau-1].ut)  ){
        printf("Kicauan ini sudah merupakan utas!\n");
    }
    else if (idKicau < 1 || idKicau > NEFF(*lkic));
}

void cetakUtas(ListKicauan lkic, Friend friend, ListUser lUser,int currIdx, int idUtas){
    boolean found = false;
    int i,idAuthor;

    for (i = 0; i < NEFF(lkic); i++){
        if (ELMT(lkic,i).idUtas == idUtas){
            found = true;
            break;
            
        }
    }
    idAuthor = (lkic).buffer[i].idAuthor;
    if (!found){
        printf("Utas tidak ditemukan!\n");
    }
    if(userOwnsKicau(lkic,currIdx,i+1) || lUser.listU[idAuthor].accType == 1 || isFriend(friend,idAuthor,currIdx)){
        displayKicau(lkic.buffer[i]);
        displayListUtas(lkic.buffer[i].ut,lkic.buffer[i].author);

    }
}
boolean possibleToConnect(ListUtas lUtas, int index){
    index -= 1;
    boolean possible = false;
    AddressUtas p  = lUtas;
    if (index >= 0){
        int i = 0;
        while (p != NULL && (i < index - 1 )){
            p = NEXTUTAS(p);
            i += 1;
        }
        if (i == index - 1 || index == 0){
            possible = true;
        }

    }
    return possible;
}

void sambungUtas(ListKicauan* lkic, int currIdx,int idUtas,int index){
    boolean found = false;
    // int i,idAuthor;
    int i;

    for (i = 0; i < NEFF(*lkic); i++){
        if (ELMT(*lkic,i).idUtas == idUtas){
            found = true;
            break;
            
        }
    }
    if (found){
        if (!userOwnsKicau((*lkic),currIdx,i)){
            printf("Anda tidak bisa menyambung utas ini!\n\n");
        }
        else {
            if (!possibleToConnect((*lkic).buffer[i].ut,index)){
                if (index - 1 < 0){
                    printf("Index terlalu rendah\n\n ");
                }
                else{
                    printf("Index terlalu tinggi!\n\n");
                }
            }
            else{
                Word text;
                DATETIME time;
                printf("Masukkan kicauan:\n");
                text = readWord(280);
                if (text.Length == 0){
                    printf("utas tidak bisa spasi saja\n\n");
                }
                else{
                    BacaDATETIME(&time);
                    insertAtListUtas(&(*lkic).buffer[i].ut, time,text,index);
                }

            }

        }
    }
    else{
        printf("Utas tidak ditemukan!\n\n");
    }
}