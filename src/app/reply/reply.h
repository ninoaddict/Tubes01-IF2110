#ifndef __REPLY_H__
#define __REPLY_H__
#include "../../../lib/datetime/datetime.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../user/user.h"

typedef struct balasan{
    int id;
    Word text;
    Word author;
    DATETIME time;
    // pointer to tree

} Balasan;

#define ID(balasan) (balasan).id
#define TEXT(balasan) (balasan).text
#define AUTHOR(balasan) (balasan).author
#define DATE(balasan) (balasan).time
#define BALASAN(balasan) (balasan).balasan


void createBalasan(int id, Word text, Word author, DATETIME time, Blasan* balasan);


// KICAUAN , harus ada friendgroup dulu
void ubahKicau(int idKicau);

void displayKicau(Kicauan kic); // display sebuah kicau

void displayKicauan(); // display kicauan user dan teman berdasarkan waktu

#endif