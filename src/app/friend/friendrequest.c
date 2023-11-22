#include "friendrequest.h"

void CreateFriendRequest(FriendRequest *pq)
{
    CreatePriorityQueue(pq);
}

void addToFriendReqList(FriendRequest *pq, int idUser, int cntFriend)
{
    pii val;
    val.first = idUser;
    val.second = cntFriend;
    enqueue(pq, val);
}

void removeFromFriendReqList(FriendRequest *pq, int idUser)
{
    PQAddress currNode = *pq;
    if (INFO(currNode).first == idUser)
    {
        free(currNode);
        *pq = NULL;
    }
    else
    {
        while (NEXT(currNode) != NULL)
        {
            if (INFO(NEXT(currNode)).first == idUser)
            {
                PQAddress temp = NEXT(currNode);
                NEXT(currNode) = NEXT(temp);
                free(temp);
                break;
            }
            currNode = NEXT(currNode);
        }
    }
}

void confirmFriend(FriendRequest *pq)
{
    pii val;
    dequeue(pq, &val);
}

pii topFriendRequest(FriendRequest pq)
{
    return pq->info;
}