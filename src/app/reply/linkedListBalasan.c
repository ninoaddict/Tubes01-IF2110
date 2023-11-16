#include <stdio.h>
#include <stdlib.h>
#include "linkedListBalasan.h"

void createLinkedListBalasan(Node **l)
{
    *l = NULL;
}

void addReply(LinkedListBalasan **l, Balasan balasan)
{
    Node *newBalasan;
    createLinkedListBalasan(&newBalasan);
    Node *last = *l;
    if (isListBalasanEmpty)
    {
        l = newBalasan;
    }
    else
    {
        while (last != NULL)
        {
            last = NEXT(last);
        }
        NEXT(last) = newBalasan;
    }
}

void deleteReply(LinkedListBalasan **l, Balasan balasan)
{
    // Asumsi di main sudah dicek dulu pakai searchBalasanById jadi pasti balasan yang akan dihapus exist.
    NodeBalasan *p = *l;
    int i = 0;
    int idx = searchBalasanById(*l, ID(INFO(balasan)));
    while (i != idx - 1)
    {
        p = NEXT(p);
        i++;
    }
    NEXT(p) = NEXT(NEXT(p));
    p = NEXT(p);
    free(p);
}

void deleteAll(LinkedListBalasan **l){
    while (!isListBalasanEmpty(*l))
    {
        // Delete first
        LinkedListBalasan p = *l;
        *l = NEXT(p);
        free(p);
    }
}

boolean isListBalasanEmpty(LinkedListBalasan *l)
{
    return l == NULL;
}

int searchBalasanById(LinkedListBalasan *l, int id)
{
    Node *p = l;
    int idx = IDX_UNDEF;
    int i = 0;
    while (p != NULL && !idx == IDX_UNDEF)
    {
        if (INFO(p).id == id)
        {
            idx = i;
        }
        p = NEXT(p);
        i++;
    }
    return idx;
}