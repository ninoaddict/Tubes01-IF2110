#ifndef __DRAFT_H__
#define __DRAFT_H__

#include <stdio.h>
#include "../../../lib/stack/stack.h"
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../tweet/tweet.h"

typedef struct draft
{
    Word word;
    DATETIME time;
} Draft;


typedef Draft ElType;

typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next; 
} Node; 

typedef struct { 
    Address addrTopDraft;
} StackDraft;

#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(sd) (sd).addrTopDraft
#define      TOP(sd) (sd).addrTopDraft->info 
#define WORD(d) (d).word
#define TIME(d) (d).time



Address newNodeDraft(ElType x);

void CreateDraft(Draft *d, Word w, DATETIME time);

void CreateStackDraft(StackDraft *sd);

void pushDraft(StackDraft *sd, ElType d);

void deleteDraft(StackDraft *sd, ElType *d);

boolean isEmptyDraft(StackDraft sd);

void seeDraft(StackDraft sd);

void publishDraft(int id_kicau, int id_user, Word user_name, Kicauan *k, ElType d,Word author, int idAuthor);


#endif