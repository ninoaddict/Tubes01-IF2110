#ifndef HASHTAG_H
#define HASHTAG_H

#include <stdio.h>
#include "../../../lib/boolean.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include <stdlib.h>

#define mod 1005293
#define prime 263

typedef struct hashnode* hashAddress;
typedef struct hashnode
{
    int info;
    hashAddress next;
} HashNode;

typedef struct
{
    hashAddress val;
    Word key;
} HashElmt;

typedef struct
{
    HashElmt Buffer[1005293];
} HashTag;


/* Hashtag Constructor */
void CreateHashTag(HashTag * hashtag);

/* Hash Function */
int HashFunction(Word w);

/* Hashnode Operation */
hashAddress newHashNode(int elmt);
void insertHashElement(hashAddress *node, int elmt);

/* Hashmap Operation */
int findSlot(Word w, HashTag hashtag);

void addHashElement(Word w, int idx, HashTag * hashtag);

#endif