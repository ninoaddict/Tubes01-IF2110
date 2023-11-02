#ifndef __TWEET.H__
#define __TWEET.H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"


typedef struct kicauan{
    int id;
    Word text;
    int like;
    Word author;
    DATETIME time;
    // pointer to utas
    // pointer to tree
   

} Kicauan;

#endif