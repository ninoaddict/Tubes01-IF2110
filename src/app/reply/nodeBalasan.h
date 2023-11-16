#ifndef __NODEBALASAN_H__
#define __NODEBALASAN_H__

#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../../../lib/boolean.h"
#include "../../../lib/binarytree/binarytree.h"
// #include "../../../lib/linkedlist/linkedlist.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friend.h"
#include "linkedListBalasan.h"

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

NodeBalasan newNode(Balasan balasan);

#endif