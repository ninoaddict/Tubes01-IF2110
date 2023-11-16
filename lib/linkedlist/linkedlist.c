#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

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

void CreateList(List *l)
{
    FIRST(*l) = NULL;
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
}

boolean isEmpty(List l)
{
    return FIRST(l) == NULL;
    /* Mengirim true jika list kosong */
}

ElType getElmt(List l, int idx)
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

void setElmt(List *l, int idx, ElType val)
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

int indexOf(List l, ElType val)
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

void insertFirst(List *l, ElType val)
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

void insertLast(List *l, ElType val)
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

void insertAt(List *l, ElType val, int idx)
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

void deleteFirst(List *l, ElType *val)
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

void deleteLast(List *l, ElType *val)
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

void deleteAt(List *l, int idx, ElType *val)
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

void displayList(List l)
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

int length(List l)
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

List concat(List l1, List l2)
{
    List l;
    Address p;
    ElType val;
    CreateList(&l);

    p = FIRST(l1);
    while (p != NULL)
    {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }

    p = FIRST(l2);
    while (p != NULL)
    {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }

    // while (length(l1) > 0)
    // {
    //     deleteFirst(&l1, &val);
    // }

    // while (length(l2) > 0)
    // {
    //     deleteFirst(&l2, &val);
    // }

    return l;

    /* I.S. l1 dan l2 sembarang */
    /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
    /* Konkatenasi dua buah list : l1 dan l2    */
    /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
}

boolean fSearch(List L, Address P)
{
    Address q;
    boolean isFound = false;
    q = FIRST(L);
    while (q != NULL && !isFound)
    {
        if (q == P)
        {
            isFound = true;
        }
        q = NEXT(q);
    }
    return isFound;
    // if (indexOf(L, INFO(P)) == IDX_UNDEF){
    //     return false;
    // }
    // else{
    //     return true;
    // }
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */
}

Address searchPrec(List L, ElType X)
{
    int idx = indexOf(L, X);
    Address prec;
    if (idx == 0 || idx == IDX_UNDEF || isEmpty(L))
    {
        prec = NULL;
    }
    else
    {
        Address p;
        p = FIRST(L);
        int i = 0;

        while (i < idx)
        {
            prec = p;
            p = NEXT(p);
            i++;
        }
    }
    return prec;
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain */
}

ElType maxValue(List l)
{
    Address p = FIRST(l);
    int max = INFO(FIRST(l));
    p = NEXT(p);
    while (p != NULL)
    {
        if (max < INFO(p))
        {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
    /* Mengirimkan nilai info(P) yang maksimum */
}

Address adrMax(List l)
{
    int i = 0, idx = indexOf(l, maxValue(l));
    Address p = FIRST(l);
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    return p;
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
}

ElType minValue(List l)
{
    Address p = FIRST(l);
    int min = INFO(FIRST(l));
    p = NEXT(p);
    while (p != NULL)
    {
        if (min > INFO(p))
        {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
    /* Mengirimkan nilai info(P) yang minimum */
}

Address adrMin(List l)
{
    int i = 0, idx = indexOf(l, minValue(l));
    Address p = FIRST(l);
    while (i < idx)
    {
        p = NEXT(p);
        i++;
    }
    return p;
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
}

float average(List L)
{
    int sum = 0;
    Address p = FIRST(L);
    while (p != NULL)
    {
        sum += INFO(p);
        p = NEXT(p);
    }
    return ((float)sum / (float)length(L));
    /* Mengirimkan nilai rata-rata info(P) */
}

void deleteAll(List *l)
{
    ElType val;
    while (!isEmpty(*l))
    {
        deleteFirst(l, &val);
    }
}

void copyList(List *l1, List *l2)
{
    FIRST(*l2) = FIRST(*l1);
    /* I.S. L1 sembarang. F.S. L2=L1 */
    /* L1 dan L2 "menunjuk" kepada list yang sama.*/
    /* Tidak ada alokasi/dealokasi elemen */
}

void inverseList(List *l)
{
    Address p = FIRST(*l);
    int n = length(*l);
    int i;
    int temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = getElmt(*l, i);
        setElmt(l, i, getElmt(*l, n - 1 - i));
        setElmt(l, n - 1 - i, temp);
    }
    /* I.S. sembarang. */
    /* F.S. elemen list dibalik : */
    /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
    /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
}
