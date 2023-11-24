#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <errno.h>
#include "load.h"

boolean tagCheck(Word w)
{
    boolean tag = true;
    if (w.Length > 0)
    {
        for (int i = 0; i < w.Length; i++)
        {
            if (w.TabWord[i] == ' ')
            {
                tag = false;
                break;
            }
        }
        return tag;
    }
    else
    {
        return false;
    }
}

int folderExists(const char *path)
{
    struct stat info;

    stat(path, &info);

    // Check if it's a directory
    if (S_ISDIR(info.st_mode))
    {
        return 1; // It's a directory
    }
    else
    {
        // It's not a directory
        return 0;
    }
}

boolean isPublic(Word w)
{
    Word check;
    char publik[6] = "Publik";
    assignWord(&check, publik, 6);
    return isWordEqual(check, w);
}

void muat(int currID, ListUser *listuser, Friend *friendgraph, ListKicauan *listkicauan, ListStackDraft *liststackdraft, HashTag *hashtag)
{
    if (currID == -1)
    {
        Word input, folderconfig;
        assignWord(&folderconfig, "config/", 7);
        printf("Masukkan nama folder yang hendak dimuat.\n");
        input = readWord(100);
        printf("\n");
        mergeWord(&folderconfig, input);
        if (folderExists(folderconfig.TabWord))
        {
            printf("Anda akan melakukan pemuatan dari ");
            displayWord(folderconfig); printf("\n");
            muatPengguna(folderconfig, listuser, friendgraph);
            muatKicauan(folderconfig, listkicauan, hashtag);
            muatBalasan(folderconfig, listkicauan, *listuser);
            muatDraf(folderconfig, listuser, liststackdraft);
            muatUtas(folderconfig, listkicauan);
            printf("Mohon tunggu...\n1...\n2...\n3...\n\n");
            printf("Pemuatan selesai!\n");
        }
        else
        {
            printf("Tidak ada folder yang dimaksud!\n");
        }
    }
    else
    {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    }
}

void muatPengguna(Word folder, ListUser *listuser, Friend *friendgraph)
{
    FILE *file;
    Word config, newfolder;
    newfolder = folder;
    assignWord(&config, "/pengguna.config", 16);
    mergeWord(&newfolder, config);
    displayWord(newfolder);
    file = fopen(newfolder.TabWord, "r");
    if (file != NULL)
    {
        char line[280];
        Word kata;
        int datacount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        listuser->Neff = datacount;
        for (int i = 0; i < datacount; i++)
        {
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
            for (int j = 0; j < 5; j++)
            {
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                for (int k = 0; k < 19; k += 2)
                {
                    listuser->listU[i].profilePic.Buffer[j][k / 2] = kata.TabWord[k];
                }
            }
        }
        for (int i = 0; i < datacount; i++)
        {
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            for (int j = 0; j < datacount * 2; j += 2)
            {
                friendgraph->adjMat[i][j / 2] = (kata.TabWord[j] - '0');
            }
        }
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i = 0; i < datacount; i++)
        {
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            setRequest(friendgraph, kata.TabWord[0] - '0', kata.TabWord[2] - '0');
            addToFriendReqList(&(listuser->listU[kata.TabWord[2] - '0'].friendReqList), kata.TabWord[0] - '0', kata.TabWord[4] - '0');
        }
    }
    fclose(file);
}

void muatKicauan(Word folder, ListKicauan *listkicauan, HashTag *hashtag){
    FILE *file;
    Word config, newfolder;
    newfolder = folder;
    assignWord(&config, "/kicauan.config", 15);
    mergeWord(&newfolder, config);
    displayWord(newfolder);
    file = fopen(newfolder.TabWord, "r");
    if (file != NULL)
    {
        char line[280];
        Word kata;
        int datacount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        if (listkicauan->capacity > datacount){
            expandListKicauan(listkicauan, datacount*2);
        }
        listkicauan->nEff = datacount;
        for (int i = 0; i < datacount; i++)
        {
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
            if (tagCheck(kata))
            {
                listkicauan->buffer[i].tag = kata;
                addHashElement(kata, i, hashtag);
            } else {
                assignWord(&kata, "", 0);
                listkicauan->buffer[i].tag = kata;
            }
        }
    }
    fclose(file);
}

int max2(int a, int b)
{
    return (a > b)? a : b;
}

void muatBalasan(Word folder, ListKicauan *listkicauan, ListUser listuser)
{
    FILE *file;
    Word config;
    assignWord(&config, "/balasan.config", 15);
    mergeWord(&folder, config);
    file = fopen(folder.TabWord, "r");
    if (file == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        char line[280];
        Word kata;
        int datacount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i = 0; i < datacount; i++)
        {
            // read tweet id
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            int currTweetID = wordToInteger(kata);

            // read count balasan
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            int cntBalasan = wordToInteger(kata);
            int maxNum = 0;

            // read balasan
            for (int j = 0; j < cntBalasan; j++)
            {
                // read u and v
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                int u, v;
                splitInt(&kata, &u, &v);
                // create currTree
                AddressTree *currTree = &(listkicauan->buffer[currTweetID - 1].tb.parentNode);

                maxNum = max2(maxNum, u);
                maxNum = max2(maxNum, v);

                // init newb
                Balasan newb;

                // read text
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                Word text = kata;

                // read author
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                Word author = kata;
                int authorID = searchUserByID(listuser, author);

                // read DATETIME
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                DATETIME time = string_toDate_time(kata);

                // create balasan
                createBalasan(v, author, text, time, authorID, &newb);

                if (u == -1)
                {
                    // add balasan
                    AddressTree newBalasan = CreateNewNode(newb);

                    if (*currTree == NULL)
                        *currTree = newBalasan;
                    else
                    {
                        AddressTree p = *currTree;
                        while (RIGHT(p) != NULL)
                            p = RIGHT(p);
                        RIGHT(p) = newBalasan;
                    }
                }
                else
                {
                    AddressTree bal = searchBalasan(*currTree, u);
                    addBalasan(&bal, newb);
                }
            }
            listkicauan->buffer[currTweetID - 1].tb.nEff = maxNum;
        }
    }
    fclose(file);
}

void muatDraf(Word folder, ListUser *listuser, ListStackDraft *liststackdraft)
{
    FILE *file;
    Word config, newfolder;
    newfolder = folder;
    assignWord(&config, "/draf.config", 12);
    mergeWord(&newfolder, config);
    displayWord(newfolder);
    file = fopen(newfolder.TabWord, "r");
    if (file != NULL)
    {
        char line[280];
        Word kata;
        int datacount, drafcount, iddraf;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i = 0; i < datacount; i++)
        {
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            splitWordAndInt(&kata, &drafcount);
            iddraf = searchUserByID(*listuser, kata);
            for (int j = 0; j < drafcount; j++)
            {
                Draft draf;
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                displayWord(kata);
                draf.word = kata;
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                kata = addNewline(kata);
                draf.time = string_toDate_time(kata);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                if (tagCheck(kata))
                {
                    draf.tag = kata;
                }
                else
                {
                    assignWord(&kata, "", 0);
                    draf.tag = kata;
                }
                if (j == 0)
                {
                    liststackdraft->contents[iddraf].addrTopDraft = newNodeDraft(draf);
                }
                else
                {
                    pushDraft(&(liststackdraft->contents[iddraf]), draf);
                }
            }
            liststackdraft->contents[iddraf] = inverseStackDraft(liststackdraft->contents[iddraf]);
        }
    }
    fclose(file);
}

void muatUtas(Word folder, ListKicauan *listkicauan)
{
    FILE *file;
    Word config, newfolder;
    newfolder = folder;
    assignWord(&config, "/utas.config", 12);
    mergeWord(&newfolder, config);
    displayWord(newfolder);
    file = fopen(newfolder.TabWord, "r");
    if (file != NULL)
    {
        char line[280];
        Word kata;
        int datacount, idkicau, utascount;
        fgets(line, sizeof(line), file);
        stringToWord(&kata, line);
        datacount = wordToInteger(kata);
        for (int i = 0; i < datacount; i++)
        {
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            idkicau = wordToInteger(kata) - 1;
            fgets(line, sizeof(line), file);
            stringToWord(&kata, line);
            utascount = wordToInteger(kata);
            listkicauan->buffer[idkicau].idUtas = i + 1;
            for (int j = 0; j < utascount; j++)
            {
                Word text;
                fgets(line, sizeof(line), file);
                stringToWord(&text, line);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                fgets(line, sizeof(line), file);
                stringToWord(&kata, line);
                kata = addNewline(kata);
                if (j == 0)
                {
                    listkicauan->buffer[idkicau].ut = newNode(string_toDate_time(kata), text);
                }
                else
                {
                    insertLastListUtas(&(listkicauan->buffer[idkicau].ut), string_toDate_time(kata), text);
                }
            }
        }
    }
    fclose(file);
}