#ifndef PENGGUNA_H
#define PENGGUNA_H
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"

typedef struct
{
    int id;
    Word name;
    Word password;
    int requestID;
    Word phoneNum;
    Word bio;
    Word weton;
    boolean accType;
    char profilePic[10][10];
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
#endif