#include <stdio.h>
#include <stdlib.h>
#include "treebalasan.h"

NodeBalasan *newNode(Balasan balasan){
    NodeBalasan *newBalasan = malloc(sizeof(newBalasan));
    if (newBalasan != NULL)
    {
        INFO(*newBalasan) = balasan;
        LEFT(*newBalasan) = NULL;
        RIGHT(*newBalasan) = NULL;
    }
    return newBalasan;
}

void createTreeBalasan(NodeBalasan** t){
    *t = NULL;
}

void addBalasan(NodeBalasan** t, Balasan balasan){
    NodeBalasan* newBalasan = newNode(balasan);
    if (LEFT(*t) == NULL){
        LEFT(*t) = newBalasan;
    }
    else {
        addReply(RIGHT(t));
    }
}

void deleteTreeBalasan(NodeBalasan *t){

    if (LEFT(*t) == NULL){
        free(t);
    }
    else{
        deleteAll(RIGHT(LEFT(*t)));
        deleteTreeBalasan(LEFT(*t));
    }
}

boolean isTreeBalasanEmpty (NodeBalasan* t){
    return t == NULL;
}

boolean isHaveBalasan(NodeBalasan t){
    return LEFT(t) == NULL;
    // RIGHT(t) gausah dicek soalnya dia ngisinya dari LEFT(t), kalo leftnya null pasti rightnya juga null
}