#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "save.h"

int countDraf(ListStackDraft liststackdraft, int neff){
    int count = 0;
    for (int i=0; i<neff; i++){
        if (liststackdraft.contents[i].addrTopDraft != NULL){
            count++;
        }
    }
    return count;
}

int countUtas(ListKicauan listkicauan){
    int count = 0;
    for (int i=0; i<listkicauan.nEff; i++){
        if (listkicauan.buffer[i].idUtas != -1){
            count++;
        }
    }
    return count;
}

int countFriendReq(ListUser listuser){
    int count = 0;
    for (int i=0; i<listuser.Neff; i++){
        count += PQLength(listuser.listU[i].friendReqList);
    }
    return count;
}

void save(ListUser listuser, Friend friendgraph, ListKicauan listkicauan, ListStackDraft liststackdraft){
    Word input, folderconfig;
    char folder[100] = "config/"; 
    assignWord(&folderconfig, folder, 16);
    printf("Masukkan nama folder penyimpanan\n");
    input = readWord(100);
    printf("\n");
    mergeWord(&folderconfig, input);
    displayWord(folderconfig);
    if (!folderExists(folderconfig.TabWord)){
        if (mkdir(folderconfig.TabWord, S_IRWXU) == 0) {
            printf("Folder1 sudah berhasil dibuat.\n\n");
        } else {
            perror("Error creating folder");
        }
        printf("Belum terdapat Folder1. Akan dilakukan pembuatan Folder1 terlebih dahulu.\n\n");
        printf("Mohon tunggu...\n1...\n2...\n3...\n\n");
        if (mkdir(folderconfig.TabWord, S_IRWXU) == 0) {
            printf("Folder1 sudah berhasil dibuat.\n\n");
        } else {
            perror("Error creating folder");
        }
    }
    printf("Anda akan melakukan penyimpanan di Folder1.\n\n");
    savePengguna(folderconfig, listuser, friendgraph);
    // saveKicauan(folderconfig, listkicauan);
    // saveBalasan(folderconfig, listkicauan);
    // saveDraf(folderconfig, listuser, liststackdraft);
    // saveUtas(folderconfig, listkicauan);
    printf("Mohon tunggu...\n1...\n2...\n3...\n\n");
    printf("Penyimpanan telah berhasil dilakukan!\n");
}

void savePengguna(Word folder, ListUser listuser, Friend friendgraph){
    FILE *file;
    Word kata;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-2/pengguna.config", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "%d\n", listuser.Neff);
    for (int i=0; i<listuser.Neff; i++){
        kata = addNewline(listuser.listU[i].name);
        fprintf(file, kata.TabWord);
        kata = addNewline(listuser.listU[i].password);
        fprintf(file, kata.TabWord);
        kata = addNewline(listuser.listU[i].phoneNum);
        fprintf(file, kata.TabWord);
        kata = addNewline(listuser.listU[i].weton);
        fprintf(file, kata.TabWord);
        if (listuser.listU[i].accType){
            assignWord(&kata, "Publik\n", 6);
        } else {
            assignWord(&kata, "Privat\n", 6);
        }
        fprintf(file, kata.TabWord);
        for (int j=0;j<5;j++){
            for (int k=0;k<10;k+=2){
                if (k==9){
                    fprintf(file, "%c\n", listuser.listU[i].profilePic[j][k]);
                } else {
                    fprintf(file, "%c ", listuser.listU[i].profilePic[j][k]);
                }
            }
        }
    }
    for (int i=0; i<listuser.Neff; i++){
        for (int j=0; j<listuser.Neff; j++){
            if (j==listuser.Neff-1){
                fprintf(file, "%d\n", friendgraph.adjMat[i][j/2]);
            } else {
                fprintf(file, "%d ", friendgraph.adjMat[i][j/2]);
            }
        }
    }
    fprintf(file, "%d\n", countFriendReq(listuser));
    for (int i=0; i<listuser.Neff; i++){
        if (PQLength(listuser.listU[i].friendReqList)>0){
            PQAddress p = listuser.listU[i].friendReqList;
            for (int j=1; j<=PQLength(listuser.listU[i].friendReqList); j++){
                fprintf(file, "%d ", p->info.first);
                fprintf(file, "%d ", p->info.second);
                fprintf(file, "%d\n", countFriend(friendgraph, p->info.first));
                p = NEXT(p);
            }
        }
    }
    fclose(file);
}

void saveKicauan(Word folder, ListKicauan listkicauan){
    FILE *file;
    Word kata;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-2/kicauan.config", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "%d\n", listkicauan.nEff);
    for (int i=0; i<listkicauan.nEff; i++){
        fprintf(file, "%d\n", i+1);
        kata = addNewline(listkicauan.buffer[i].text);
        fprintf(file, kata.TabWord);
        fprintf(file, "%d\n", listkicauan.buffer[i].like);
        kata = addNewline(listkicauan.buffer[i].author);
        fprintf(file, kata.TabWord);
        kata = dateTimeToWord(listkicauan.buffer[i].time);
        fprintf(file, kata.TabWord);
        assignWord(&kata, "", 0);
        if (isWordEqual(listkicauan.buffer[i].tag, kata)){
            fprintf(file, "\n");
        } else {
            kata = addNewline(listkicauan.buffer[i].tag);
            fprintf(file, kata.TabWord);
        }
    }
    fclose(file);
}

void saveBalasan(Word folder, ListKicauan listkicauan){
    /*FILE *file;
    Word kata;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-2/balasan.config", "w");
    if (file == NULL) {
        perror("Error opening file");
    }

    fclose(file);*/
}

void saveDraf(Word folder, ListUser listuser, ListStackDraft liststackdraft){
    FILE *file;
    Word kata;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-2/draf.config", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "%d\n", countDraf(liststackdraft, listuser.Neff));
    for (int i=0; i<countDraf(liststackdraft, listuser.Neff); i++){
        if (liststackdraft.contents[i].addrTopDraft != NULL){
            kata = listuser.listU[i].name;
            fprintf(file, kata.TabWord);
            fprintf(file, " %d\n", draftLength(liststackdraft.contents[i]));
            Address p = liststackdraft.contents[i].addrTopDraft;
            for (int j=1; j<draftLength(liststackdraft.contents[i]); j++){
                kata = addNewline(WORD(INFO(p)));
                fprintf(file, kata.TabWord);
                kata = dateTimeToWord(TIME(INFO(p)));
                fprintf(file, kata.TabWord);
                assignWord(&kata, "", 0);
                if (isWordEqual(p->info.tag, kata)){
                    fprintf(file, "\n");
                } else {
                    kata = addNewline(p->info.tag);
                    fprintf(file, kata.TabWord);
                }
            }
        }
    }
    
    fclose(file);
}

void saveUtas(Word folder, ListKicauan listkicauan){
    FILE *file;
    Word kata;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-2/utas.config", "w");
    if (file == NULL) {
        perror("Error opening file");
    }
    fprintf(file, "%d\n", countUtas(listkicauan));
    for (int i=0; i<listkicauan.nEff; i++){
        if (listkicauan.buffer[i].idUtas != -1){
            fprintf(file, "%d\n", i+1);
            fprintf(file, "%d\n", listUtasLength(listkicauan.buffer[i].ut));
            AddressUtas p = listkicauan.buffer[i].ut;
            for (int j=1; j<=listUtasLength(listkicauan.buffer[i].ut); j++){
                kata = addNewline(TEXTUTAS(p));
                fprintf(file, kata.TabWord);
                kata = addNewline(listkicauan.buffer[i].author);
                fprintf(file, kata.TabWord);
                kata = dateTimeToWord(DATEUTAS(p));
                fprintf(file, kata.TabWord);
                p = NEXTUTAS(p);
            }
        }
    }
    fclose(file);
}
