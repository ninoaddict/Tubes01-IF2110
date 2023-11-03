#ifndef __DB_H__
#define __DB_H__
#include "app/user/listuser.h"
#include <stdio.h> 
extern ListUser listuser;
extern Friend friendGraph;
extern int currID;
extern int currTweetID;
extern int idxCommand;
extern boolean run;
extern Word command[4];
extern Word commands[30];

void setup();

#endif