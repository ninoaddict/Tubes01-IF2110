#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <errno.h>
#include "load.h"

boolean tagCheck(Word w){
    boolean tag = true;
    if (w.Length > 0){
        for (int i=0;i<w.Length;i++){
            if (w.TabWord[i] == ' '){
                tag = false;
                break;
            }
        }
        return tag;
    } else {
        return false;
    }
}

int folderExists(const char *path) {
    struct stat info;

    stat(path, &info);

    // Check if it's a directory
    if (S_ISDIR(info.st_mode)) {
        return 1; // It's a directory
    } else {
        // It's not a directory
        printf("Error: The path is not a directory.\n");
        return 0;
    }
}

boolean isPublic(Word w){
    Word check;
    char publik[6] = "Publik";
    assignWord(&check, publik, 6);
    return isWordEqual(check, w);
}

void muat(int currID, ListUser *listuser, Friend *friendgraph, ListKicauan *listkicauan, ListStackDraft *liststackdraft){
    if (currID == -1){
        Word input, folderconfig;
        char folder[100] = "config/"; 
        assignWord(&folderconfig, folder, 16);
        printf("Masukkan nama folder yang hendak dimuat.\n");
        input = readWord(100);
        printf("\n");
        mergeWord(&folderconfig, input);
        displayWord(folderconfig);
        // wordToString(&folder, folderconfig);
        if (folderExists(folderconfig.TabWord)){
            printf("%d", folderExists(folderconfig.TabWord));
            printf("Anda akan melakukan pemuatan dari Folder2.\n\n");
            muatPengguna(folderconfig, listuser, friendgraph);
            muatKicauan(folderconfig, listkicauan);
            muatBalasan(folderconfig, listkicauan);
            // muatDraf(folderconfig, listuser, liststackdraft);
            muatUtas(folderconfig, listkicauan);
            printf("Mohon tunggu...\n1...\n2...\n3...\n\n");
            printf("Pemuatan selesai!\n");
        } else {
            printf("Tidak ada folder yang dimaksud!\n");
        }
    } else {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    }
}

void muatPengguna(Word folder, ListUser *listuser, Friend *friendgraph){
    FILE *file;
    // char filename[15] = "pengguna.config";
    // Word config;
    // stringToWord(&config, filename);
    // assignWord(&config, "/pengguna.config", 17);
    // mergeWord(&folder, config);
    // displayWord(folder);
    file = fopen("config/config-1/pengguna.config", "r");
    if (file != NULL){
        char line[280];
        Word kata;
        int datacount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        listuser->Neff = datacount;
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].name = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].password = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].bio = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].phoneNum = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].weton = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listuser->listU[i].accType = isPublic(kata);
            for (int j=0;j<5;j++){
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                for (int k=0;k<19;k+=2){
                    listuser->listU[i].profilePic[j][k/2] = kata.TabWord[k];
                }
            }
        }
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            for (int j=0; j<datacount*2; j+=2){
                friendgraph->adjMat[i][j/2] = (kata.TabWord[j]-'0');
            }
        }
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            setRequest(friendgraph, kata.TabWord[0]-'0', kata.TabWord[2]-'0');
            addToFriendReqList(&(listuser->listU[kata.TabWord[2]-'0'].friendReqList), kata.TabWord[0]-'0', kata.TabWord[4]-'0');
        }
    }
    fclose(file);
}

void muatKicauan(Word folder, ListKicauan *listkicauan){
    FILE *file;
    // char filename[20] = "kicauan.config";
    // Word config;
    // stringToWord(&config, filename);
    // mergeWord(&folder, config);
    // wordToString(&filename, folder);
    file = fopen("config/config-1/kicauan.config", "r");
    if (file != NULL){
        char line[280];
        Word kata;
        int datacount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        listkicauan->nEff = datacount;
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listkicauan->buffer[i].id = wordToInteger(kata);
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listkicauan->buffer[i].text = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listkicauan->buffer[i].like = wordToInteger(kata);
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            listkicauan->buffer[i].author = kata;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            kata = addNewline(kata);
            listkicauan->buffer[i].time = string_toDate_time(kata);
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            if (tagCheck(kata)){
                listkicauan->buffer[i].tag = kata;
            } else {
                assignWord(&kata, "", 0);
                listkicauan->buffer[i].tag = kata;
            }
        }
    }
    fclose(file);
}

void muatBalasan(Word folder, ListKicauan *listkicauan){
    /*FILE *file;
    char filename[20] = "balasan.config";
    Word config;
    stringToWord(&config, filename);
    mergeWord(&folder, config);
    wordToString(&filename, folder);
    file = fopen(filename, "r");
    if (file != NULL){
        char line[280];
        Word kata;
        int datacount, balasancount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
        }
    }
    fclose(file);*/
}

void muatDraf(Word folder, ListUser *listuser, ListStackDraft *liststackdraft){
    FILE *file;
    file = NULL;
    // char filename[20] = "draf.config";
    // Word config;
    // stringToWord(&config, filename);
    // mergeWord(&folder, config);
    // wordToString(&filename, folder);
    file = fopen("config/config-1/draf.config", "r");
    if (file != NULL){
        char line[280];
        Word kata;
        int datacount, drafcount, iddraf;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            splitWordAndInt(&kata, &drafcount);
            iddraf = searchUserByID(*listuser, kata);
            for (int j=0; j<drafcount; j++){
                Draft draf;
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                draf.word = kata;
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                kata = addNewline(kata);
                draf.time = string_toDate_time(kata);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                if (tagCheck(kata)){
                    draf.tag = kata;
                } else {
                    assignWord(&kata, "", 0);
                    draf.tag = kata;
                }
                if (j==0){
                    liststackdraft->contents[iddraf].addrTopDraft = newNodeDraft(draf);
                } else {
                    pushDraft(&(liststackdraft->contents[iddraf]), draf);
                }
            }
            inverseStackDraft(&(liststackdraft->contents[iddraf]));
        }
    }
    fclose(file);
}

void muatUtas(Word folder, ListKicauan *listkicauan){
    FILE *file;
    file = NULL;
    // char filename[20] = "utas.config";
    // Word config;
    // stringToWord(&config, filename);
    // mergeWord(&folder, config);
    // wordToString(&filename, folder);
    // file = fopen(filename, "r");
    file = fopen("config/config-1/utas.config", "r");
    if (file != NULL){
        char line[280];
        Word kata;
        int datacount, idkicau, utascount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i=0; i<datacount; i++){
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            idkicau = wordToInteger(kata) - 1;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            utascount = wordToInteger(kata);
            listkicauan->buffer[idkicau].idUtas = i+1;
            for (int j=0; j<utascount; j++){
                Word text;
                fgets(line, sizeof(line), file);
                stringToWord(&text, line);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                kata = addNewline(kata);
                if (j==0){
                    listkicauan->buffer[idkicau].ut = newNode(string_toDate_time(kata), text);
                } else {
                    insertLastListUtas(&(listkicauan->buffer[idkicau].ut), string_toDate_time(kata), text);
                }
            }
        }
    }
    fclose(file);
}