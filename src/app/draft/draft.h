#ifndef __DRAFT_H__
#define __DRAFT_H__

#include <stdio.h>
#include "../../../lib/stack/stack.h"
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../tweet/listkicauan.h"

typedef struct draft
{
    Word word;
    Word tag;
    DATETIME time;
} Draft;

typedef struct node *Address;
typedef struct node
{
    Draft info;
    Address next;
} Node;

typedef struct
{
    Address addrTopDraft;
} StackDraft;

#define NEXT(p) (p)->next
#define INFO(p) (p)->info
#define ADDR_TOP(sd) (sd).addrTopDraft
#define TOP(sd) (sd).addrTopDraft->info
#define WORD(d) (d).word
#define TIME(d) (d).time

Address newNodeDraft(Draft x);

void CreateDraft(Draft *d, Word w, DATETIME time, Word tag);

void CreateStackDraft(StackDraft *sd);

void pushDraft(StackDraft *sd, Draft d);

void deleteDraft(StackDraft *sd, Draft *d);

boolean isEmptyDraft(StackDraft sd);

void seeDraft(ListKicauan *lkic, int currIdx, Word authorName, StackDraft *sd, int *IdKicau, HashTag *hashtag);

void publishDraft(int id_kicau, int id_user, Word user_name, Kicauan *k, Draft d, Word author, int idAuthor);

void makeDraft(ListKicauan *lkic, int currIdx, Word authorName, StackDraft *st, int *IdKicau, HashTag *hashtag);

#endif