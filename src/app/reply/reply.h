#ifndef __REPLY_H__
#define __REPLY_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
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

void displayBalasan(Kicauan kic, Balasan balasan, int depth);

void isHaveReply(Kicauan kic);

#endif