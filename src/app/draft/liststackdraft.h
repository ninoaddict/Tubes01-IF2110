#ifndef __LISTDRAFT_H__
#define __LISTDRAFT_H__

#include <stdio.h>
#include "draft.h"

#define MaxElListStack 20

typedef StackDraft ListElType;
typedef struct liststackdraft
{
   ListElType contents[MaxElListStack];
} ListStackDraft;

// #define ELMT(l,idx) (l).contents[idx]

void assignStackDraft(ListStackDraft *l, int userID, StackDraft sd);

void CreateListStackDraft(ListStackDraft *l);

#endif