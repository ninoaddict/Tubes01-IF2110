#ifndef FRIEND_H
#define FRIEND_H
#include <stdio.h>
#include "../../../lib/charmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/graph/graph.h"
#define Friend Graph // menggunakan ADT Graph dengan representasi adjacency matrix

// CONSTRUCTOR
void CreateFriend(Friend * friend);

// CHECK
boolean isFriend(Friend friend, int id1, int id2);

// SELECTOR
void setFriend(Friend *friend, int id1, int id2);

void unsetFriend(Friend *friend, int id1, int id2);

#endif