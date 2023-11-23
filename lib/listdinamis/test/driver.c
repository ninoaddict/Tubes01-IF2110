#include "../listdin.h"
#include <stdio.h>

int main()
{
    ListDin L;
    CreateListDin(&L, 20);
    readListDin(&L);
    printList(L);
    return 0;
}