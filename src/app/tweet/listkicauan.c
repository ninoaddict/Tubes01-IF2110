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

    for (i = NEFF(lkic) - 1; i >= 0; i--)
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

void likeKicau(ListKicauan *lkic, ListUser lUser, Friend friend, int idKicauYangInginDiLike, int currIdx)
{
    if (idKicauYangInginDiLike < 1 || idKicauYangInginDiLike > NEFF(*lkic))
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", idKicauYangInginDiLike);
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
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu\n\n");
        }
    }
}

void updateKicau(ListKicauan *lkic, int currIdx, int idKicau)
{
    if (idKicau < 1 || idKicau > NEFF(*lkic))
    {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n\n", idKicau);
    }
    else if (userOwnsKicau(*lkic, currIdx, idKicau))
    {
        printf("Masukkan kicauan baru:\n");
        Word text;
        text = readWord(280);
        printf("\n");
        if (isAllSpace(text))
        {
            printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
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
    if (idKicau <= 0)
    {
        printf("Kicauan tidak ditemukan\n\n");
        return;
    }
    else if (userOwnsKicau(*lkic, currIdx, idKicau) && isEmptyUtas((*lkic).buffer[idKicau - 1].ut))
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
        printf("Utas tidak ditemukan!\n\n");
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
        displayListUtas(lkic.buffer[i].ut, (lkic).buffer[i].author);
    }
    else
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
    }
}

void sambungUtas(ListKicauan *lkic, int currIdx, int idUtas, int index)
{
    boolean found = false;
    // int i,idAuthor;
    int i;
    if (idUtas >= 1)
    {
        for (i = 0; i < NEFF(*lkic); i++)
        {
            if (ELMT(*lkic, i).idUtas == idUtas)
            {
                found = true;
                break;
            }
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
                    printf("Utas berhasil disambungkan\n\n");
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
                        printf("Utas berhasil disambungkan\n\n");
                    }
                    else
                    {
                        printf("gagal membuat node\n\n");
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
    if (idUtas >= 1)
    {
        for (i = 0; i < NEFF(*lkic); i++)
        {
            if (ELMT(*lkic, i).idUtas == idUtas)
            {
                found = true;
                break;
            }
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

void balas(ListKicauan *lkic, int idKicauan, int idBalasan, int currID, Friend friendGraph, ListUser listuser)
{
    if (idKicauan <= NEFF(*lkic) && idKicauan > 0)
    {
        AddressTree *currTree = &(lkic->buffer[idKicauan - 1].tb.parentNode);
        AddressTree bal = searchBalasan(*currTree, idBalasan);
        if (idBalasan == -1)
        {
            int idAuthorKicau = lkic->buffer[idKicauan - 1].idAuthor;
            if (isFriend(friendGraph, currID, idAuthorKicau) || listuser.listU[idAuthorKicau].accType)
            {
                Balasan newb;

                // read time
                DATETIME time;
                BacaDATETIME(&time);

                // read text
                printf("Masukkan balasan: \n");
                Word text = readWord(280);
                printf("\n");

                // create balasan
                createBalasan(lkic->buffer[idKicauan - 1].tb.nEff + 1, listuser.listU[currID].name, text, time, currID, &newb);

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

                lkic->buffer[idKicauan - 1].tb.nEff += 1;
                printf("Berhasil membuat balasan!\n\n");
            }
            else
            {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
            }
        }
        else if (bal != NULL)
        {
            int idAuthorBal = IDAUTHORBALASAN(INFOREP(bal));
            if (isFriend(friendGraph, currID, idAuthorBal) || listuser.listU[idAuthorBal].accType)
            {
                Balasan newb;

                // read time
                DATETIME time;
                BacaDATETIME(&time);

                // read text
                printf("Masukkan balasan: \n");
                Word text = readWord(280);
                printf("\n");

                // create balasan
                createBalasan(lkic->buffer[idKicauan - 1].tb.nEff + 1, listuser.listU[currID].name, text, time, currID, &newb);

                // add balasan
                addBalasan(&bal, newb);
                lkic->buffer[idKicauan - 1].tb.nEff += 1;
                printf("Berhasil membuat balasan!\n\n");
            }
            else
            {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
            }
        }
        else
        {
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n\n");
        }
    }
    else
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
    }
}

void deleteBalasan(int idKicau, int idBalasan, ListKicauan *lkic, int currID)
{
    if (idKicau > 0 && idKicau <= NEFF(*lkic))
    {
        AddressTree *currTree = &(lkic->buffer[idKicau - 1].tb.parentNode);
        int del = deleteTreeBalasan(currTree, idBalasan, currID);
        if (del == 1)
            printf("Balasan berhasil dihapus\n\n");
        else if (del == 2)
            printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n\n");
        else
            printf("Balasan tidak ditemukan\n\n");
    }
    else
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda hapus!\n\n");
    }
}

void displayBalasan(AddressTree currTree, ListUser listuser, Friend friendGraph, int dep, int currID)
{
    if (isAddressTreeEmpty(currTree))
        return;
    else
    {
        int idAuthor = currTree->info.idAuthorBalasan;
        if (isFriend(friendGraph, idAuthor, currID) || listuser.listU[idAuthor].accType)
        {
            displayBalasanPublic(currTree->info, dep);
        }
        else
        {
            displayBalasanPrivate(currTree->info, dep);
        }
        displayBalasan(LEFT(currTree), listuser, friendGraph, dep + 1, currID);
        displayBalasan(RIGHT(currTree), listuser, friendGraph, dep, currID);
    }
}