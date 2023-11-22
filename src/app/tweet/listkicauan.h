#ifndef __LISTKICAUAN_H__
#define __LISTKICAUAN_H__
#include <stdio.h>
#include <stdlib.h>
#include "tweet.h"
#include "../../../lib/boolean.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../hashtag/hashtag.h"
#include "../friend/friend.h"
#include "../user/listuser.h"
/* Indeks minimum list */
#define IDX_MIN 0

/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Kicauan ElType; /* type elemen list */
typedef int IdxType;

typedef struct listKicauan
{
    ElType *buffer;
    int nEff;
    int capacity;

} ListKicauan;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void createListKicauan(ListKicauan *l, int capacity);

void dealocateListKicauan(ListKicauan *l);

void bacaKicauan(ListKicauan *lkic, User currUser, int *IdKicau, int currId, HashTag * hashtag);

void displayListKicauan(ListKicauan lkic, Friend friend, int currId);

void copyListKicauan(ListKicauan lIn, ListKicauan *lOut);

void expandListKicauan(ListKicauan *l, int num);

boolean isFullListKicauan(ListKicauan l);

void likeKicau(ListKicauan *lkic, ListUser l, Friend friend, int idKicauYangInginDiLike, int currIdx);

void updateKicau(ListKicauan *lkic, int currIdx, int idKicau);

boolean userOwnsKicau(ListKicauan lkic, int currIdx, int idKicau);

void makeKicauanUtama(ListKicauan *lkic, int currIdx, int idKicau, int *idUtas);

void cetakUtas(ListKicauan lkic, Friend friend, ListUser lUser, int currIdx, int idUtas);

boolean possibleToConnect(ListUtas lUtas, int index);

boolean possibleToDisConnect(ListUtas lUtas, int index);

void sambungUtas(ListKicauan *lkic, int currIdx, int idUtas, int index);

void putusUtas(ListKicauan *lkic, DATETIME *date, Word *text, int currIdx, int idUtas, int index);

void searchHashTag(ListKicauan lkic, HashTag *hashtag, Word tag);

#endif