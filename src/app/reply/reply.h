#ifndef __REPLY_H__
#define __REPLY_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../tweet/tweet.h"
#include "../user/user.h"
#include "../friend/friend.h"
#include "../user/user.h"

typedef struct balasan
{
    int id;
    Word text;
    Word author;
    // DATETIME time;

} Balasan;

#define IDBALASAN(balasan) (balasan).id
#define TEXTBALASAN(balasan) (balasan).text
#define AUTHORBALASAN(balasan) (balasan).author
#define DATEBALASAN(balasan) (balasan).time

// void createBalasan(int id, Word author, Word text, DATETIME time, Balasan *balasan);

void createBalasan(int id, Word author, Word text, Balasan *balasan);

void Balas(int IDKicau, int IDbalasan, boolean isFriend(Graph friend, int id1, int id2));

void deleteBalasan(int IDbalasan);

void displayBalasan(Balasan balasan);

#endif