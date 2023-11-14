#ifndef __REPLY_H__
#define __REPLY_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/binarytree/binarytree.h"
#include "../../../lib/linkedlist/linkedlist.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../tweet/tweet.h"
#include "../user/user.h"

typedef struct balasan
{
    int id;
    Word text;
    Word author;
    DATETIME time;
} Balasan;

#define ID(balasan) (balasan).id
#define TEXT(balasan) (balasan).text
#define AUTHOR(balasan) (balasan).author
#define DATE(balasan) (balasan).time
#define BALASAN(balasan) (balasan).balasan

void createBalasan(int id, Word author, Word text, DATETIME time, Balasan *balasan);

void Balas (int IDKicau, IDbalasan);

void deleteBalasan(int IDbalasan);

void displayBalasan(Address balasan);

void isHaveReply(Balasan balasan);

#endif