#ifndef __TWEET_H__
#define __TWEET_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../user/user.h"
#include "../thread/thread.h"




typedef struct kicauan{
    int id;
    Word text;
    int like;
    Word author;
    DATETIME time;
    Utas* ut;
    // pointer to utas
    // pointer to tree
   

} Kicauan;
#define ID(kic) (kic).id
#define TEXT(kic) (kic).text
#define LIKE(kic) (kic).like
#define AUTHOR(kic) (kic).author
#define DATE(kic) (kic).time
#define UTAS(kic) (kic).ut


void createKicauan(int id, Word text, int like, Word author, DATETIME time, Kicauan* kic);


// KICAUAN , harus ada friendgroup dulu
void ubahKicau(int idKicau);

void displayKicau(Kicauan kic); // display sebuah kicau

void displayKicauan(); // display kicauan user dan teman berdasarkan waktu

#endif