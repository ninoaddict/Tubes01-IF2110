
#include "../../tweet/listkicauan.h"
#include "../../user/listuser.h"
#include <stdio.h>




int main(void){
     ListUser listuser;
    Friend friend;
    Word userinput;
    int currIdx = -1;
    ListKicauan l;
    int idKicau;
    int index;

    CreateFriend(&friend);
    
    CreateListUser(&listuser);
    
    
    int IdKicau = 0; // index kicau pada listkicau, bukan id kicau itu sendiri
    createListKicauan(&l,10);

    SignUp(&listuser, &currIdx);  // signup pertama
    bacaKicauan(&l, listuser.listU[0],&IdKicau,currIdx);
    // printf("\n");
    // currIdx = -1; 

    // SignUp(&listuser, &currIdx);
    // bacaKicauan(&l, listuser.listU[currIdx],&IdKicau,currIdx);
    // listuser.listU[currIdx].accType = 0; // buat privat, utk contoh saja
    // // printf("\n");
    // currIdx = -1; 

    // SignUp(&listuser, &currIdx);
    // bacaKicauan(&l, listuser.listU[currIdx],&IdKicau,currIdx);
    // // printf("\n");

    // setFriend(&friend,currIdx,0); //  sebagai contoh, semisalnya yang sekarang login di buat friend dengan yang signup pertama
    // printf("\n");
    // printf("test display semua kicauan currIdx yang sekarang login =  ");
    // displayWord(listuser.listU[currIdx].name);printf("di contoh ini, teman ");displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" adalah user pertama \n");
    // displayListKicauan(l,friend,currIdx);
    // // printf("\n");
    
    // printf("dalam contoh ini, saya setfriend currentIdx(user sekarang) dengan id 0 (user pertama), dan set private user 1 (user kedua)\n\n");
    // displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" mau like ID kicau berapa ? : ");
    // userinput = readWord(180);
    // idKicau = wordToInteger(userinput);
    // likeKicau( &l,listuser,friend, idKicau,currIdx);

    // displayWordWithoutEnter(listuser.listU[currIdx].name);printf(" mau like ID kicau berapa ? : ");
    // userinput = readWord(180);
    // idKicau = wordToInteger(userinput);
    // likeKicau(&l,listuser,friend,idKicau,currIdx);
    // printf("\n");

    // currIdx = -1; // logout
    // printf("Login : \n");
    // LogIn(&listuser,&currIdx);
    // printf("\n"); ///////////////////////////////////
    int idUtas = 1;
    printf("percobaan membuat utas\n");
    printf("id kicau berapa ? : ");
    userinput = readWord(100);
    idKicau = wordToInteger(userinput);
    makeKicauanUtama(&l,currIdx,idKicau,&idUtas);
    printf("\n");
    printf("berikut cetak utas, jika utas gagal dibuat maka akan tercetak id 0 date 0/0/0\n\n");
    cetakUtas(l,friend,listuser,currIdx,1);
    printf("percobaan sambung utas\n");
    printf("Masukan idutas : "); 
    int id;
    userinput = readWord(280);
    id = wordToInteger(userinput);
    printf("Masukan index : "); 
    
    userinput = readWord(280);
    index = wordToInteger(userinput);
    sambungUtas(&l,currIdx,id,index);
    cetakUtas(l,friend,listuser,currIdx,1);

} 