#ifndef FRIENDREQUEST_H
#define FRIENDREQUEST_H
#include <stdio.h>
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/priorityqueue/priorityqueue.h"
#include "../../../lib/boolean.h"

#define FriendRequest PriorityQueue

/*CONSTRUCTOR*/
void CreateFriendRequest(FriendRequest *pq);

/*SELEKTOR*/
void copyFriendRequest(FriendRequest pqIn, FriendRequest pqOut);

void addToFriendReqList(FriendRequest *pq, int idUser, int cntFriend);

void removeFromFriendReqList(FriendRequest *pq, int idUser);

void confirmFriend(FriendRequest *pq);

pii topFriendRequest(FriendRequest pq);

#endif