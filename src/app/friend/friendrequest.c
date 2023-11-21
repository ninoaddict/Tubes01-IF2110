#include "friendrequest.h"

void CreateFriendRequest(FriendRequest *pq){
    CreatePriorityQueue(pq);
}

void addToFriendReqList(FriendRequest *pq, int idUser, int cntFriend){
    pii val;
    val.first = idUser;
    val.second = cntFriend;
    enqueue(pq, val);
}

void removeFromFriendReqList(FriendRequest *pq, int idUser){
    pii tempArr[20], tempVal;
    int cnt = 0;
    while (!isPQEmpty(*pq)){
        dequeue(pq, &tempVal);
        if (tempVal.first == idUser) break;
        tempArr[cnt] = tempVal;
        cnt++;
    }
    for (int i = 0; i < cnt; i++){
        enqueue(pq, tempArr[i]);
    }
}

void confirmFriend(FriendRequest *pq){
    pii val;
    dequeue(pq, &val);
}

pii topFriendRequest(FriendRequest pq){
    return pq->info;
}