#ifndef __LISTKICAUAN_H__
#define __LISTKICAUAN_H__
#include <stdio.h>
#include <stdlib.h>
#include "tweet.h"
#include "../../../lib/boolean.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
/* Indeks minimum list */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1

/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Kicauan ElType; /* type elemen list */
typedef int IdxType;

typedef struct listKicauan{
    ElType *buffer;
    int nEff;       
    int capacity;

} ListKicauan;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void createListKicauan(ListKicauan* l, int capacity);

void dealocateListKicauan(ListKicauan *l);
void bacaKicauan(ListKicauan* lkic, User currUser, int* IdKicau);

#endif