#ifndef LISTUSER_H
#define LISTUSER_H
#include <stdio.h>
#include "user.h"
#include "../friend/friend.h"
#include "../../../lib/boolean.h"
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"

typedef struct 
{
    User listU[20];
    int Neff;
}ListUser;

// CONSTRUCTOR
void CreateListUser(ListUser * listuser);

// SELECTOR
int searchUserByID(ListUser listuser, Word name);

// AUTHENTICATION
void SignUp(ListUser *listuser);

int isUsernameNotValid(Word name, ListUser listuser);
/*
    code 0 : valid
    code 1 : invalid word length
    code 2 : invalid username (already used)
    code 3 : name consist of whitespaces only
*/

boolean isPasswordValid(Word password);

#endif