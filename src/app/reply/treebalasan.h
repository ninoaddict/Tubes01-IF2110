#ifndef __LISTKICAUAN_H__
#define __LISTKICAUAN_H__
#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../../../lib/boolean.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friend.h"

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef Balasan ElType; 
typedef int IdxType;

typedef struct treeBalasan{
    ElType *buffer;
    Address left;
    Address right;
} TreeBalasan;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void createTreeBalasan(TreeBalasan* t);

void deleteTreeBalasan(TreeBalasan* t);

void dealocateTreeBalasan(TreeBalasan *l);

void addBalasan(TreeBalasan* t);

#endif