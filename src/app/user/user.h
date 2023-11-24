#ifndef PENGGUNA_H
#define PENGGUNA_H
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friendrequest.h"
#include "pcolor.h"
#include <stdio.h>
#include "../../../lib/matrix/matrix.h"
typedef struct
{
    int friendNum; // banyak teman
    Word name;
    Word password;
    Word phoneNum;
    Word bio;
    Word weton;
    boolean accType; // true if public
    Matrix profilePic;
    FriendRequest friendReqList;
} User;

// CONSTRUCTOR
void CreateUser(User * user);

void ConstructWeton();

// READ USER ELEMENT
void readPhoneNum(User * user);
void readBio(User * user);
void readWeton(User * user);
void switchAccType(User * user);
void changeProfilePicture(User * user);
boolean isAllNum(Word w);

// SHOW
void showProfile(User user);
void showProfilePicture(User user);
#endif