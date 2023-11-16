#include <stdio.h>
#include <stdlib.h>
#include "nodeBalasan.h"


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

