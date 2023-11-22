#ifndef __THREAD_H__
#define __THREAD_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/boolean.h"

typedef struct utas *AddressUtas;
typedef struct utas
{
    DATETIME date;
    Word text;
    AddressUtas nextUtas;

} Utas;
typedef AddressUtas ListUtas;

#define DATEUTAS(p) (p)->date
#define TEXTUTAS(p) (p)->text
#define NEXTUTAS(p) (p)->nextUtas

AddressUtas newNode(DATETIME date, Word text);

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void CreateUtas(ListUtas *l); // membentuk utas kosong

boolean isEmptyUtas(ListUtas l);

void insertFirstListUtas(ListUtas *l, DATETIME date, Word text);

void insertLastListUtas(ListUtas *l, DATETIME date, Word text);

void displayListUtas(ListUtas l, Word author);

void insertAtListUtas(ListUtas *l, DATETIME date, Word text, int index);

void deleteFirstListUtas(ListUtas *l, DATETIME *date, Word *text);

void deleteLastListUtas(ListUtas *l, DATETIME *date, Word *text);

void deleteAtListUtas(ListUtas *l, int idx, DATETIME *date, Word *text);

#endif