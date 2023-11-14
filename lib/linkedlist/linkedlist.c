#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Address newNode(ElType val)
{
    Address p;
    p = malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
    /* Definisi List : */
    /* List kosong : FIRST(l) = NULL */
    /* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
    /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
}

void CreateList(Listlinked *l)
{
    FIRST(*l) = NULL;
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
}

boolean isEmpty(Listlinked l)
{
    return FIRST(l) == NULL;
    /* Mengirim true jika list kosong */
}

ElType getElmt(Listlinked l, int idx)
{
    Address p;
    int i = 0;
    p = FIRST(l);
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */
}

void setElmt(Listlinked *l, int idx, ElType val)
{
    Address p;
    int i = 0;
    p = FIRST(*l);
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
}

int indexOf(Listlinked l, ElType val)
{
    ElType idx = IDX_UNDEF;
    Address p;
    int i = 0;
    boolean isFound = false;
    p = FIRST(l);
    while (p != NULL)
    {
        if (INFO(p) == val)
        {
            return i;
        }
        i++;
        p = NEXT(p);
    }
    return IDX_UNDEF;

    /* I.S. l, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list l yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
    /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
}

void insertFirst(Listlinked *l, ElType val)
{
    Address p;
    p = newNode(val);
    if (p != NULL)
    {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
    // length(l) += 1;
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
}

void insertLast(Listlinked *l, ElType val)
{
    if (isEmpty(*l))
    {
        insertFirst(l, val);
    }
    else
    {
        Address p, q;
        p = newNode(val);
        if (p != NULL)
        {
            q = FIRST(*l);
            while (NEXT(q) != NULL)
            {
                q = NEXT(q);
            }
            NEXT(q) = p;
        }
    }
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
}

void insertAt(Listlinked *l, ElType val, int idx)
{
    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {
        Address p, q, r;
        int i = 0;
        p = newNode(val);
        if (p != NULL)
        {
            q = FIRST(*l);
            while (i < idx - 1)
            {
                q = NEXT(q);
                i++;
            }
            r = NEXT(q);
            NEXT(q) = p;
            NEXT(p) = r;
        }
    }
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
}

void deleteFirst(Listlinked *l, ElType *val)
{
    Address p;
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
    /* I.S. List l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */
}

void deleteLast(Listlinked *l, ElType *val)
{
    Address p;
    if (length(*l) == 1)
    {
        p = FIRST(*l);
        *val = INFO(p);
        FIRST(*l) = NULL;
    }
    else
    {
        Address q;
        p = FIRST(*l);
        while (NEXT(p) != NULL)
        {
            q = p;
            p = NEXT(p);
        }
        *val = INFO(p);
        NEXT(q) = NULL;
    }
    free(p);
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */
}

void deleteAt(Listlinked *l, int idx, ElType *val)
{
    Address p;
    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        Address q;
        int i = 0;
        p = FIRST(*l);
        while (i < idx - 1)
        {
            p = NEXT(p);
            i++;
        }
        q = NEXT(p);
        *val = INFO(q);
        NEXT(p) = NEXT(q);
        free(q);
    }
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
}

void displayList(Listlinked l)
{
    Address p;
    p = FIRST(l);
    printf("[");
    while (p != NULL)
    {
        printf("%d", INFO(p));
        if (NEXT(p) != NULL)
        {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
    // void printInfo(List l);
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
}

int length(Listlinked l)
{
    Address p;
    int i = 0;
    p = FIRST(l);
    while (p != NULL)
    {
        i++;
        p = NEXT(p);
    }
    return i;
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
}

void deleteAll(Listlinked *l)
{
    ElType val;
    while (!isEmpty(*l))
    {
        deleteFirst(l, &val);
    }
}
