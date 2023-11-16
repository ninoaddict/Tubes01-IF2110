#ifndef __LISTKICAUAN_H__
#define __LISTKICAUAN_H__

#include <stdio.h>
#include <stdlib.h>
#include "reply.h"
#include "../../../lib/boolean.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/linkedlist/linkedlist.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friend.h"
#include "nodeBalasan.h"

#define IDX_MIN 0
#define IDX_UNDEF -1

typedef Balasan balasan; 

typedef struct LinkedListBalasan{
    Balasan info;
    struct Linkedlistbalasan *next;
} LinkedListBalasan;

#define INFO(bal) (bal)->info
#define NEXT(bal) (bal)->next

void createLinkedListBalasan(NodeLinkedListBalasan **l);

void addReply(NodeLinkedListBalasan **l, Balasan balasan);

void deleteReply(NodeLinkedListBalasan **l, Balasan balasan);

void deleteAll(LinkedListBalasan **l);

boolean isListBalasanEmpty(NodeLinkedListBalasan *l);

int searchBalasanById(NodeLinkedListBalasan *l, int id);

#endif