#ifndef PENGGUNA_H
#define PENGGUNA_H
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../friend/friendrequest.h"
#include "pcolor.h"
#include <stdio.h>
typedef struct
{
    int idUser;
    Word name;
    Word password;
    int requestID;
    Word phoneNum;
    Word bio;
    Word weton;
    boolean accType;
    char profilePic[10][10];
    FriendRequest friend;
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