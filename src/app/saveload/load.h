#ifndef LOAD_H
#define LOAD_H
#include "../../../lib/boolean.h"
#include "../user/listuser.h"
#include "../tweet/listkicauan.h"
#include "../friend/friend.h"
#include "../draft/liststackdraft.h"

boolean tagCheck(Word w);

int folderExists(const char *folderPath);

boolean isPublic(Word w);

void muat(int currID, ListUser *listuser, Friend *friendgraph, ListKicauan *listkicauan, ListStackDraft *liststackdraft);

void muatPengguna(Word folder, ListUser *listuser, Friend *friendgraph);

void muatKicauan(Word folder, ListKicauan *listkicauan);

void muatBalasan(Word folder, ListKicauan *listkicauan);

void muatDraf(Word folder, ListUser *listuser, ListStackDraft *liststackdraft);

void muatUtas(Word folder, ListKicauan *listkicauan);

#endif