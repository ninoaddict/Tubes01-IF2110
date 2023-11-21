#include "../listkicauan.h"
#include "../../user/listuser.h"
#include <stdio.h>

int main(void){
    ListUser listuser;
    Friend friend;
    Word userinput;
    int currIdx = -1;
    ListKicauan l;
    int idKicau;

    CreateFriend(&friend);
    
    CreateListUser(&listuser);
    
    
    int IdKicau = 0; // index kicau pada listkicau, bukan id kicau itu sendiri
    createListKicauan(&l,10);

    SignUp(&listuser, &currIdx);  // signup pertama
    bacaKicauan(&l, listuser.listU[0],&IdKicau,currIdx);
    printf("\n");
    currIdx = -1; 

    SignUp(&listuser, &currIdx);
    bacaKicauan(&l, listuser.listU[currIdx],&IdKicau,currIdx);
    listuser.listU[currIdx].accType = 0; // buat privat, utk contoh saja
    printf("\n");
    currIdx = -1; 

    SignUp(&listuser, &currIdx);
    bacaKicauan(&l, listuser.listU[currIdx],&IdKicau,currIdx);
    printf("\n");

    setFriend(&friend,currIdx,0); //  sebagai contoh, semisalnya yang sekarang login di buat friend dengan yang signup pertama
    printf("\n");
    printf("test display semua kicauan currIdx yang sekarang login =  ");
    displayWord(listuser.listU[currIdx].name);printf("di contoh ini, teman ");displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" adalah user pertama \n");
    displayListKicauan(l,friend,currIdx);
    printf("\n");
    
    printf("dalam contoh ini, saya setfriend currentIdx(user sekarang) dengan id 0 (user pertama), dan set private user 1 (user kedua)\n\n");
    displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" mau like ID kicau berapa ? : ");
    userinput = readWord(180);
    idKicau = wordToInteger(userinput);
    likeKicau( &l,listuser,friend, idKicau,currIdx);

    displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" mau like ID kicau berapa ? : ");
    userinput = readWord(180);
    idKicau = wordToInteger(userinput);
    likeKicau(&l,listuser,friend,idKicau,currIdx);
    printf("\n");

    currIdx = -1; // logout
    printf("Login : \n");
    LogIn(&listuser,&currIdx);
    printf("\n");
    printf("Percobaan ubah kicau  \n");
    printf("ubah id kicau berapa ? : ");
    userinput = readWord(180);
    idKicau = wordToInteger(userinput);
    updateKicau(&l,currIdx,idKicau);
    printf("\n");

    printf("Percobaan 2 ubah kicau  \n");
    printf("ubah id kicau berapa ? : ");
    userinput = readWord(180);
    idKicau = wordToInteger(userinput);
    updateKicau(&l,currIdx,idKicau);

    return 0 ;
}