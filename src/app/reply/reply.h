#ifndef __REPLY_H__
#define __REPLY_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/datetime/datetime.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct balasan
{
    int id;
    Word text;
    Word author;
    DATETIME time;
    int idAuthorBalasan;
} Balasan;

#define IDBALASAN(balasan) (balasan).id
#define TEXTBALASAN(balasan) (balasan).text
#define AUTHORBALASAN(balasan) (balasan).author
#define DATEBALASAN(balasan) (balasan).time
#define IDAUTHORBALASAN(balasan) (balasan).idAuthorBalasan

typedef struct nodeBalasan *AddressTree;
typedef struct nodeBalasan
{
    Balasan info;
    struct nodeBalasan *left;
    struct nodeBalasan *right;
} NodeBalasan;

typedef struct {
    AddressTree parentNode;
    int nEff;
} TreeBalasan;

#define INFOREP(t) (t)->info
#define LEFT(t) (t)->left
#define RIGHT(t) (t)->right

#define PARNODE(t) (t).parentNode

void createBalasan(int id, Word author, Word text, DATETIME time, int idAuthorBalasan, Balasan *balasan);

#endif