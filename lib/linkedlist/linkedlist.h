/* File : linkedlist.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef linkedlist_H
#define linkedlist_H

#include "boolean.h"

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType* val);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address Listlinked;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void CreateList(Listlinked *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty(Listlinked l);
/* Mengirim true jika list kosong */

ElType getElmt(Listlinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(Listlinked *l, int idx, ElType val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(Listlinked l, ElType val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

void insertFirst(Listlinked *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(Listlinked *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(Listlinked *l, ElType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void deleteFirst(Listlinked *l, ElType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void deleteLast(Listlinked *l, ElType *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(Listlinked *l, int idx, ElType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

void displayList(Listlinked l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(Listlinked l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void deleteAll(Listlinked *l);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

#endif