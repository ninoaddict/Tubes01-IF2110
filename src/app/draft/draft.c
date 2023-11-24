#include <stdio.h>
#include <stdlib.h>
#include "draft.h"

Address newNodeDraft(Draft x)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateDraft(Draft *d, Word w, DATETIME time, Word tag)
{
    WORD(*d) = w;
    TIME(*d) = time;
    TAG(*d) = tag;
}

void CreateStackDraft(StackDraft *sd)
{
    ADDR_TOP(*sd) = NULL;
}

void pushDraft(StackDraft *sd, Draft d)
{
    Address p = newNodeDraft(d);
    NEXT(p) = ADDR_TOP(*sd);
    ADDR_TOP(*sd) = p;
}

void deleteDraft(StackDraft *sd, Draft *d)
{
    *d = TOP(*sd);
    Address p = ADDR_TOP(*sd);
    ADDR_TOP(*sd) = NEXT(ADDR_TOP(*sd));
    NEXT(p) = NULL;
    free(p);
}

boolean isEmptyDraft(StackDraft sd)
{
    return ADDR_TOP(sd) == NULL;
}

void seeDraft(ListKicauan *lkic, int currIdx, Word authorName, StackDraft *sd, int *IdKicau, HashTag *hashtag)
{
    if (isEmptyDraft(*sd))
    {
        printf("\nYah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        printf("\nIni draf terakhir Anda:\n");
        printf("| %d/%d/%d %d:%d:%d\n", INFO(ADDR_TOP(*sd)).time.DD, INFO(ADDR_TOP(*sd)).time.MM, INFO(ADDR_TOP(*sd)).time.YYYY, INFO(ADDR_TOP(*sd)).time.T.HH, INFO(ADDR_TOP(*sd)).time.T.MM, INFO(ADDR_TOP(*sd)).time.T.SS);
        printf("| ");
        displayWord(INFO(ADDR_TOP(*sd)).word);
        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        Word ubah, terbit, ans, kembali;
        assignWord(&ubah, "UBAH", 4);
        assignWord(&terbit, "TERBIT", 6);
        assignWord(&kembali, "KEMBALI", 7);
        ans = readWord(30);
        Draft temp;
        deleteDraft(sd, &temp);
        if (isWordEqual(ans, terbit))
        {
            if (isFullListKicauan(*lkic))
            {
                expandListKicauan(lkic, 2 * NEFF(*lkic));
            }
            int hashLen = temp.tag.Length;
            for (int i = 0; i < temp.tag.Length; i++)
            {
                if (temp.tag.TabWord[i] == ' ' || temp.tag.TabWord[i] == '\t')
                    hashLen--;
            }
            if (hashLen){
                addHashElement(temp.tag, NEFF(*lkic), hashtag);
            }
            else{
                temp.tag.Length = 0;
            }
            
            DATETIME time;
            BacaDATETIME(&time);
            createKicauan(NEFF(*lkic) + 1, temp.word, 0, authorName, time, &(lkic->buffer[NEFF(*lkic)]), currIdx, temp.tag);
            NEFF(*lkic) += 1;
            *IdKicau = NEFF(*lkic) - 1;
            printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan: \n");
            displayKicau((*lkic).buffer[*IdKicau]);
        }
        else if (isWordEqual(ans, ubah))
        {
            printf("\nMasukkan draf yang baru: \n");
            makeDraft(lkic, currIdx, authorName, sd, IdKicau, hashtag);
        }
        else if (isWordEqual(ans, kembali)){
            pushDraft(sd, temp);
            printf("\nKembali..\n");
        }
        else
        {
            printf("\nDraf telah berhasil dihapus!\n");
        }
    }
}

void publishDraft(int id_kicau, int id_user, Word user_name, Kicauan *k, Draft d, Word author, int idAuthor)
{
    DATETIME t;
    BacaDATETIME(&t);
    // createKicauan(id_kicau, d.word, 0, author, t, k, idAuthor);
}

void makeDraft(ListKicauan *lkic, int currIdx, Word authorName, StackDraft *st, int *IdKicau, HashTag *hashtag)
{
    Word text = readWord(280);
    int textLen = text.Length;
    for (int i = 0; i < text.Length; i++)
    {
        if (text.TabWord[i] == ' ' || text.TabWord[i] == '\t')
        {
            textLen--;
        }
    }
    if (text.Length == 0 || textLen == 0)
    {
        printf("\n");
        printf("Draf tidak boleh hanya berisi spasi!\n\n");
    }
    else
    {
        printf("\nMasukkan hashtag: \n");
        Word tag = readWord(300);
        int hashLen = tag.Length;
        for (int i = 0; i < tag.Length; i++)
        {
            if (tag.TabWord[i] == ' ' || tag.TabWord[i] == '\t')
            {
                hashLen--;
            }
        };
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        Word simpan, terbit, answer;
        assignWord(&simpan, "SIMPAN", 6);
        assignWord(&terbit, "TERBIT", 6);
        answer = readWord(30);
        DATETIME time;
        BacaDATETIME(&time);
        if (isWordEqual(answer, terbit))
        {
            if (isFullListKicauan(*lkic))
            {
                expandListKicauan(lkic, 2 * NEFF(*lkic));
            }
            if (hashLen)
            {
                addHashElement(tag, NEFF(*lkic), hashtag);
            }
            createKicauan(NEFF(*lkic) + 1, text, 0, authorName, time, &(lkic->buffer[NEFF(*lkic)]), currIdx, tag);
            NEFF(*lkic) += 1;
            *IdKicau = NEFF(*lkic) - 1;
            printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan: \n");
            displayKicau((*lkic).buffer[*IdKicau]);
        }
        else if (isWordEqual(answer, simpan))
        {
            Draft dr;
            CreateDraft(&dr, text, time, tag);
            pushDraft(st, dr);
            printf("\nDraf telah berhasil disimpan!\n");
        }
        else
        {
            printf("\nDraf telah berhasil dihapus!\n");
        }
    }
}

int draftLength(StackDraft sd) {
    Address p = sd.addrTopDraft;
    int cnt = 0;
    while (p != NULL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}

void inverseStackDraft(StackDraft *sd){
    StackDraft inversesd;
    Draft temp;
    CreateStackDraft(&inversesd);
    for (int i=1; i<=draftLength(*sd); i++){
        deleteDraft(sd, &temp);
        pushDraft(&inversesd, temp);
    }
    *sd = inversesd;
}