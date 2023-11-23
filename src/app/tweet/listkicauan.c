#include <stdio.h>
#include "listkicauan.h"

void createListKicauan(ListKicauan *l, int capacity)
{
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *)malloc(sizeof(ElType) * capacity);
}
void dealocateListKicauan(ListKicauan *l)
{
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

void bacaKicauan(ListKicauan *lkic, User currUser, int *IdKicau, int idAuthor, HashTag *hashtag)
{
    Word text;
    int i;
   
    printf("Masukkan kicauan:\n");

    text = readWord(280);

    if (isAllSpace(text))
    {
        printf("\n");
        printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
    }
    else
    {
        printf("\nMasukkan hashtag: \n");
        Word tag = readWord(300);
        int hasLen = tag.Length;
        for (i = 0; i < tag.Length; i++)
        {
            if (tag.TabWord[i] == ' ' || tag.TabWord[i] == '\t')
            {
                hasLen--;
            }
        }
        if (hasLen)
        {
            addHashElement(tag, NEFF(*lkic), hashtag);
        }
        else
        {
            tag.Length = 0;
        }
        DATETIME time;
        BacaDATETIME(&time);
        if (isFullListKicauan(*lkic))
        {
            expandListKicauan(lkic, 2 * NEFF(*lkic));
        }
        createKicauan(NEFF(*lkic) + 1, text, 0, currUser.name, time, &((*lkic).buffer[NEFF(*lkic)]), idAuthor, tag);
        NEFF(*lkic) += 1;
        *IdKicau = NEFF(*lkic) - 1;
        printf("\n");
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        displayKicau((*lkic).buffer[*IdKicau]);
    }
}
boolean userOwnsKicau(ListKicauan lkic, int currIdx, int idKicau)
{
    if (idKicau > lkic.nEff)
    {
        return false;
    }
    else
    {
        return (ELMT(lkic, idKicau - 1).idAuthor == currIdx);
    }
}

void displayListKicauan(ListKicauan lkic, Friend friend, int currId)
{
    int i;

    for (i = 0; i < NEFF(lkic); i++)
    {
        if (ELMT(lkic, i).idAuthor == currId)
        {
            displayKicau(ELMT(lkic, i));
        }
        else if (isFriend(friend, currId, ELMT(lkic, i).idAuthor))
        {
            displayKicau(ELMT(lkic, i));
        }
    }
}
void copyListKicauan(ListKicauan lIn, ListKicauan *lOut)
{
    int i;
    createListKicauan(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn); ++i)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

void expandListKicauan(ListKicauan *l, int num)
{
    ListKicauan lstore;
    int i;
    createListKicauan(&lstore, CAPACITY(*l) + num);
    NEFF(lstore) = NEFF(*l);
    for (i = 0; i < NEFF(*l); ++i)
    {
        ELMT(lstore, i) = ELMT(*l, i);
    }
    dealocateListKicauan(l);
    copyListKicauan(lstore, l);
}

boolean isFullListKicauan(ListKicauan l)
{
    return (NEFF(l) == CAPACITY(l));
}

void likeKicau(ListKicauan *lkic, ListUser lUser, Friend friend, int  idKicauYangInginDiLike, int currIdx)
{
    if (idKicauYangInginDiLike < 1 || idKicauYangInginDiLike > NEFF(*lkic))
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauYangInginDiLike);
    }
    else
    {
        int idUser = (*lkic).buffer[idKicauYangInginDiLike - 1].idAuthor; // lokasi user di listuser
        if (lUser.listU[idUser].accType || isFriend(friend, idUser, currIdx))
        { // jika public atau friend
            LIKE((*lkic).buffer[idKicauYangInginDiLike - 1]) += 1;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            displayKicau(ELMT(*lkic, idKicauYangInginDiLike - 1));
        }
        else
        {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu\n");
        }
    }
}

void updateKicau(ListKicauan *lkic, int currIdx, int idKicau)
{
    if (idKicau < 1 || idKicau > NEFF(*lkic))
    {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
    }
    else if (userOwnsKicau(*lkic, currIdx, idKicau))
    {
        printf("Masukkan kicauan baru:\n");
        Word text;
        text = readWord(280);
        printf("\n");
        if (isAllSpace(text))
        {
            printf("Kicauan tidak boleh hanya berisi spasi!");
        }
        else
        {
            printf("Selamat! kicauan telah diterbitkan!\n");
            ELMT(*lkic, idKicau - 1).text = text;
            displayKicau(ELMT(*lkic, idKicau - 1));
        }
        printf("\n");
    }
    else
    {
        printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicau);
    }
}

void makeKicauanUtama(ListKicauan *lkic, int currIdx, int idKicau, int *idUtas)
{   
    if (idKicau <= 0 ){
        printf("Kicauan tidak ditemukan\n\n");
        return;
    }
    else if(userOwnsKicau(*lkic, currIdx, idKicau) && isEmptyUtas((*lkic).buffer[idKicau - 1].ut))
    {
        (*lkic).buffer[idKicau - 1].idUtas = *idUtas;
        CreateUtas(&(*lkic).buffer[idKicau - 1].ut);
        *idUtas += 1;
        Word text, yes;
        boolean done = false;
        do
        {

            DATETIME date;
            BacaDATETIME(&date);
            printf("\n");
            if (!done)
            {
                printf("Utas berhasil dibuat!\n\n");
                done = true;
            }

            printf("Masukkan kicauan:\n");
            text = readWord(280);
            insertLastListUtas(&(*lkic).buffer[idKicau - 1].ut, date, text);
            printf("\n");
            printf("Apakah Anda ingin melanjutkan utas ini?\n");
            text = readWord(5);

            yes.Length = 3;
            yes.TabWord[0] = 'Y';
            yes.TabWord[1] = 'E';
            yes.TabWord[2] = 'S';

        } while (isWordEqual(text, yes));
        printf("Utas selesai!\n\n");
    }
    else if (idKicau > (*lkic).nEff || idKicau <= 0)
    {
        printf("Kicauan tidak ditemukan\n\n");
    }
    else if (!userOwnsKicau(*lkic, currIdx, idKicau))
    {
        printf("Utas ini bukan milik anda!\n\n");
        return;
    }
    else if (!isEmptyUtas((*lkic).buffer[idKicau - 1].ut))
    {
        printf("Kicauan ini sudah merupakan utas!\n\n");
        return;
    }
    else if (idKicau < 1 || idKicau > NEFF(*lkic))
        ;
}

void cetakUtas(ListKicauan lkic, Friend friend, ListUser lUser, int currIdx, int idUtas)
{
    boolean found = false;
    int i, idAuthor;

    for (i = 0; i < NEFF(lkic); i++)
    {
        if (ELMT(lkic, i).idUtas == idUtas)
        {
            found = true;
            break;
        }
    }
    idAuthor = (lkic).buffer[i].idAuthor;
    if (!found)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else if (userOwnsKicau(lkic, currIdx, i + 1) || lUser.listU[idAuthor].accType == 1 || isFriend(friend, idAuthor, currIdx))
    {
        // displayKicau(lkic.buffer[i]);
        printf("| ID = %d\n", lkic.buffer[i].id);
        printf("| ");
        displayWord(lkic.buffer[i].author);
        printf("| ");
        TulisDATETIME(lkic.buffer[i].time);
        printf("\n");
        printf("| ");
        displayWord(lkic.buffer[i].text);
        printf("\n");
        displayListUtas(lkic.buffer[i].ut,(lkic).buffer[i].author);
    }
    else
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
    }
}
boolean possibleToConnect(ListUtas lUtas, int index)
{
    index -= 1;
    boolean possible = false;
    AddressUtas p = lUtas;
    if (index >= 0)
    {
        int i = 0;
        while (p != NULL && (i < index - 1))
        {
            p = NEXTUTAS(p);
            i += 1;
        }
        if (i == index - 1 || index == 0)
        {
            possible = true;
        }
    }
    return possible;
}
boolean possibleToDisConnect(ListUtas lUtas, int index)
{
    return possibleToConnect(lUtas, index);
}

void sambungUtas(ListKicauan *lkic, int currIdx, int idUtas, int index)
{
    boolean found = false;
    // int i,idAuthor;
    int i;

    for (i = 0; i < NEFF(*lkic); i++)
    {
        if (ELMT(*lkic, i).idUtas == idUtas)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        if (!userOwnsKicau((*lkic), currIdx, ELMT(*lkic, i).id))
        {
            printf("Anda tidak bisa menyambung utas ini!\n\n");
        }
        else
        {
            ListUtas lUtas;
            lUtas = (*lkic).buffer[i].ut;
            Word text;
            DATETIME time;
            boolean possible = false;
            AddressUtas pbefore = NULL;
            AddressUtas p = lUtas; // kicauan utama
            // p = NEXTUTAS(p); // index 1
            if (isEmptyUtas(p))
            {
                possible = (index == 1);
            }
            else
            {
                if (index >= 0)
                {
                    int idx = 1;
                    while (p != NULL && idx < index)
                    {
                        pbefore = p;
                        p = NEXTUTAS(p);
                        idx += 1;
                    }
                    if (idx == index)
                    {
                        possible = true;
                    }
                }
            }
            if (possible)
            {
                printf("Masukkan kicauan:\n");
                text = readWord(280);
                BacaDATETIME(&time);

                if (index == 1)
                {
                    insertFirstListUtas(&(*lkic).buffer[i].ut, time, text);
                }
                else
                {
                    AddressUtas pcontainer;
                    pcontainer = newNode(time, text);
                    if (pcontainer != NULL)
                    {
                        NEXTUTAS(pcontainer) = p;
                        if (pbefore != NULL)
                        {
                            NEXTUTAS(pbefore) = pcontainer;
                        }
                    }
                    else
                    {
                        printf("gagal membuat node");
                    }
                }
            }
            else
            {
                if (index <= 0)
                {
                    printf("Index terlalu rendah\n\n");
                }
                else
                {
                    printf("Index terlalu tinggi!\n\n");
                }
            }
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n\n");
    }
}

void putusUtas(ListKicauan *lkic, DATETIME *date, Word *text, int currIdx, int idUtas, int index)
{
    boolean found = false;
    // int i,idAuthor;
    int i;

    for (i = 0; i < NEFF(*lkic); i++)
    {
        if (ELMT(*lkic, i).idUtas == idUtas)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        if (!userOwnsKicau((*lkic), currIdx, ELMT(*lkic, i).id))
        {
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n\n");
        }
        else
        {
            int idx = 1;
            AddressUtas p = ELMT(*lkic, i).ut, pbefore = NULL;

            while (p != NULL && idx < index)
            {
                pbefore = p;
                p = NEXTUTAS(p);
                idx += 1;
            }
            if (p == NULL || index < 0)
            {
                printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n\n", index);
            }
            else if (index == 0)
            {
                printf("Anda tidak bisa menghapus kicauan utama!\n\n");
            }
            else
            {
                DATETIME date;
                Word text;
                if (pbefore == NULL)
                {
                    deleteFirstListUtas(&((*lkic).buffer[i].ut), &date, &text);
                }
                else
                {
                    NEXTUTAS(pbefore) = NEXTUTAS(p);
                    free(p);
                }
                printf("Kicauan sambungan berhasil dihapus!\n\n");
            }
        }
    }
    else
    {
        printf("Utas tidak ditemukan!\n\n");
    }
}

void searchHashTag(ListKicauan lkic, HashTag *hashtag, Word tag, int currID, Friend friendGraph, ListUser listuser)
{
    int i = HashFunction(tag);
    while (hashtag->Buffer[i].val != NULL && !isWordEqual(hashtag->Buffer[i].key, tag))
    {
        // printf("ada collision bos!\n");
        i = (i + 1) % mod;
    }
    hashAddress currNode = hashtag->Buffer[i].val;
    while (currNode != NULL)
    {
        int idx = currNode->info;
        int userIdx = lkic.buffer[idx].idAuthor;
        if ((currID != -1 && isFriend(friendGraph, currID, userIdx)) || listuser.listU[userIdx].accType)
            displayKicau(lkic.buffer[idx]);
        printf("\n");
        currNode = currNode->next;
    }
}