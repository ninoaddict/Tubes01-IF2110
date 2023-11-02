#include "friend.h"

/*CONSTRUCTOR*/
void CreateFriend(Friend *friend)
{
    CreateGraph(friend);
}

/*CHECK*/
boolean isFriend(Friend friend, int id1, int id2)
{
    return friend.adjMat[id1][id2] && friend.adjMat[id2][id1];
}

boolean isRequested(Friend friend, int id1, int id2){
    return friend.adjMat[id1][id2] && !friend.adjMat[id2][id1];
}

/*SELEKTOR*/
void setFriend(Friend *friend, int id1, int id2)
{
    friend->adjMat[id1][id2] = true;
    friend->adjMat[id2][id1] = true;
}

void unsetFriend(Friend *friend, int id1, int id2)
{
    friend->adjMat[id1][id2] = false;
    friend->adjMat[id2][id1] = false;
}

void setRequest(Friend *friend, int id1, int id2){
    friend->adjMat[id1][id2] = true;
}

void unsetRequest(Friend *friend, int id1, int id2){
    friend->adjMat[id1][id2] = false;
}

/*OPERATOR*/
int countFriend(Friend friend, int currID){
    int cnt = 0;
    for (int i = 0; i < friend.Neff; i++){
        if (isFriend(friend, currID, i)){
            cnt++;
        }
    }
    return cnt;
}