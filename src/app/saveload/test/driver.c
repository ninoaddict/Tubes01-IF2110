#include "../load.h"
#include "../save.h"
#include <stdio.h>

HashTag ht;

int main(void){
    ListUser listuser;
    Friend friendGraph;
    ListKicauan listkicauan;
    ListStackDraft liststackdraft;
    CreateListUser(&listuser);
    CreateFriend(&friendGraph);
    createListKicauan(&listkicauan, 10);
    CreateListStackDraft(&liststackdraft);
    CreateHashTag(&ht);
    muat(-1, &listuser, &friendGraph, &listkicauan, &liststackdraft, &ht);
    for (int i = 0; i < listuser.Neff; i++){
        showProfile(listuser.listU[i]);
    }
    for (int i = 0; i < listuser.Neff; i++){
        for (int j = 0; j < listuser.Neff; j++){
            printf("%d ", friendGraph.adjMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    displayListKicauan(listkicauan, friendGraph, 0);
    Word tuan, tuan2;
    assignWord(&tuan, "Tuan Bus", 8);
    displayListUtas(listkicauan.buffer[0].ut, tuan);
    assignWord(&tuan2, "Tuan Hak", 8);
    int i = 2;
    seeDraft(&listkicauan, 0, tuan2, &(liststackdraft.contents[0]), &i, &ht);
    save(listuser, friendGraph, listkicauan, liststackdraft);
    return 0;
}