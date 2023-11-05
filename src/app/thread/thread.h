#ifndef __THREAD_H__
#define __THREAD_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/boolean.h"




typedef struct utas* AddressUtas;
typedef struct utas{
    DATETIME date;
    Word text;
    AddressUtas nextUtas;
    
}Utas;
typedef AddressUtas ListUtas;

#define DATE(p) (p)->date
#define TEXT(p) (p)-> text
#define NEXT(p) (p)-> nextUtas

AddressUtas newNode(DATETIME date, Word text);

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void CreateUtas(ListUtas*l); // membentuk utas kosong

boolean isEmpty(ListUtas l);

void insertFirstListUtas(ListUtas *l, DATETIME date ,Word text);

void insertLastListUtas(ListUtas* l, DATETIME date, Word text);

void displayListUtas(ListUtas l, Word author);

void insertAtListUtas();
#endif