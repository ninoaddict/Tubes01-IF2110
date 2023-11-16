#ifndef __LISTKICAUAN_H__
#define __LISTKICAUAN_H__
#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "linkedListBalasan.h"
#include "nodeBalasan.h"
#include "../../../lib/boolean.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/linkedlist/linkedlist.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friend.h"

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef Balasan balasan;

typedef struct NodeBalasan
{
    Balasan info;
    NodeBalasan* left;
    LinkedListBalasan* right;
} NodeBalasan;

#define INFO(t) (t).info
#define LEFT(t) (t).left
#define RIGHT(t) (t).right

void createTreeBalasan(NodeBalasan** t);

void addBalasan(NodeBalasan** t, Balasan balasan);

void deleteTreeBalasan(NodeBalasan *t);

boolean isTreeBalasanEmpty (NodeBalasan* t);

boolean isHaveBalasan(NodeBalasan t);

#endif