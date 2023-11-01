#include "friend.h"

// CONSTRUCTOR
void CreateFriend(Friend * friend){
    CreateGraph(friend);
}

boolean isFriend(Friend friend, int id1, int id2){
    return friend.adjMat[id1][id2] && friend.adjMat[id2][id1];
}

void setFriend(Friend *friend, int id1, int id2){
    friend->adjMat[id1][id2] = true;
    friend->adjMat[id2][id1] = true;
}

void unsetFriend(Friend *friend, int id1, int id2){
    friend->adjMat[id1][id2] = false;
    friend->adjMat[id2][id1] = false;
}