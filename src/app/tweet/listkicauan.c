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

void bacaKicauan(ListKicauan* lkic, User currUser, int* IdKicau){
    printf("Masukkan kicauan:\n");
    Word text;
    text = readWord(280);
    if(text.Length == 0){
        printf("Kicauan tidak boleh hanya berisi spasi!");
    }
    else{
        *IdKicau += 1; // Idkicau dianggap 0 di main
        DATETIME time;
        BacaDATETIME(&time);
        createKicauan(*IdKicau, text, 0, currUser.name,time,&((*lkic).buffer[*IdKicau-1]));
        NEFF(*lkic) += 1;
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        displayKicau((*lkic).buffer[*IdKicau-1]);
    }


}