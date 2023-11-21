#ifndef __TREEBALASAN_H__
#define __TREEBALASAN_H__

#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../../../lib/boolean.h"

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef struct nodeBalasan *AddressTree;
typedef struct nodeBalasan
{
    Balasan info;
    struct nodeBalasan *left;
    struct nodeBalasan *right;
} NodeBalasan;

#define INFO(t) (t)->info
#define LEFT(t) (t)->left
#define RIGHT(t) (t)->right

typedef AddressTree TreeBalasan;

AddressTree createNewNode(Balasan balasan);

void createTreeBalasan(TreeBalasan *t);

void addBalasan(AddressTree *n, Balasan balasan);

boolean deleteTreeBalasan(TreeBalasan t, int idFind);

void deleteAllNode(NodeBalasan *n);

boolean isTreeBalasanEmpty(TreeBalasan t);

boolean isOneElementTree(TreeBalasan t);

boolean isNodeHaveBalasan(TreeBalasan t);

AddressTree searchBalasan(TreeBalasan t, int id);

#endif