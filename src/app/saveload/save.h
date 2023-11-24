#ifndef SAVE_H
#define SAVE_H
#include "load.h"
#include "../draft/liststackdraft.h"

int countDraf(ListStackDraft liststackdraft, int neff);

int countUtas(ListKicauan listkicauan);

int countFriendReq(ListUser listuser);

int countBalasan(ListKicauan lkic);

void save(ListUser listuser, Friend friendgraph, ListKicauan listkicauan, ListStackDraft liststackdraft);

void savePengguna(Word folder, ListUser listuser, Friend friendgraph);

void saveKicauan(Word folder, ListKicauan listkicauan);

void saveBalasan(Word folder, ListKicauan listkicauan);

void saveDraf(Word folder, ListUser listuser, ListStackDraft liststackdraft);

void saveUtas(Word folder, ListKicauan listkicauan);

#endif