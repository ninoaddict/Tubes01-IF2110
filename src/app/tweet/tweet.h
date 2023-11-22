#ifndef __TWEET_H__
#define __TWEET_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../user/user.h"
#include "../thread/thread.h"
#include "../friend/friend.h"
#include "../user/listuser.h"

typedef struct kicauan
{
    int id;
    Word text;
    int like;
    Word author;
    DATETIME time;
    ListUtas ut;  // null jika tidak ada
    int idUtas;   // -1 jika tidak ada
    int idAuthor; // lokasi user di listuser, jadi currId
    // pointer to tree

} Kicauan;
#define ID(kic) (kic).id
#define TEXTKICAU(kic) (kic).text
#define LIKE(kic) (kic).like
#define AUTHOR(kic) (kic).author
#define DATEKICAU(kic) (kic).time
#define UTAS(kic) (kic).ut
#define IDUTAS(kic) (kic).idUtas
#define IDAUTHOR(kic) (kic).idAuthor

void createKicauan(int id, Word text, int like, Word author, DATETIME time, Kicauan *kic, int idAuthor);

// KICAUAN , harus ada friendgroup dulu
void ubahKicau(int idKicau);

void displayKicau(Kicauan kic); // display sebuah kicau

#endif