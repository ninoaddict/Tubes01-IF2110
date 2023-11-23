#include "../listlinier.h"
#include <stdio.h>


int main()
{
    List L, M;
    ElType val;

    CreateListLin(&L);

    printf("Empty list? %d\n", isEmptyLin(L));
    insertFirstLin(&L, 5);
    insertLastLin(&L, 3);
    insertAtLin(&L, 2, 1);
    displayListLin(L);

    printf("panjang list : %d\n", lengthLin(L));
    deleteAtLin(&L, 2, &val);
    printf("val : %d\n", val);
    displayListLin(L);
    deleteLastLin(&L, &val);
    printf("val : %d\n", val);
    displayListLin(L);
    deleteFirstLin(&L, &val);
    printf("val : %d\n", val);
    displayListLin(L);

    insertFirstLin(&L, 3);
    insertLastLin(&L, 4);
    insertAtLin(&L, 2, 2);
    displayListLin(L);

    CreateListLin(&M);
    insertFirstLin(&M, 5);
    insertLastLin(&M, 89);
    insertAtLin(&M, 5, lengthLin(M));
    displayListLin(M);

    List F = concatLin(L, M);
    displayListLin(F);
    displayListLin(L);
    displayListLin(M);
    val = getElmtLin(F, 2);
    printf("idx 2 di F: %d\n", val);
    setElmtLin(&F, 1, 10);
    displayListLin(F);
    printf("89 ada di idx ke-%d\n", indexOfLin(F, 89));

    return 0;
}