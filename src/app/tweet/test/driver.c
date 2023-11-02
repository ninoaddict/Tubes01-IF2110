#include "../listkicauan.h"
#include "../../user/listuser.h"
#include <stdio.h>

int main(void){
    ListUser listuser;
    int currIdx = -1;
    CreateListUser(&listuser);
    SignUp(&listuser, &currIdx);
    ListKicauan l;
    int IdKicau = 0;
    createListKicauan(&l,10);
    bacaKicauan(&l, listuser.listU[0],&IdKicau);
    return 0 ;
}