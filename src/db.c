#include "db.h"
int currID;
int currTweetID;
ListUser listuser;
Friend friendGraph;
int idxCommand;
Word command[4];
Word commands[30];
DATETIME current_time;
ListKicauan lkic;
extern int id_kicau;
boolean run;

void setup(){
    run = true;
    currID = -1;
    currTweetID = 0;
    CreateListUser(&listuser);
    CreateFriend(&friendGraph);

    // setup commands  
    assignWord(&commands[0], "DAFTAR", 6);

    assignWord(&commands[1], "MASUK", 5);

    assignWord(&commands[2], "KELUAR", 6);

    assignWord(&commands[3], "TUTUP_PROGRAM", 13);

    assignWord(&commands[4], "GANTI_PROFIL", 12);

    assignWord(&commands[5], "LIHAT_PROFIL", 12);

    assignWord(&commands[6], "ATUR_JENIS_AKUN", 15);

    assignWord(&commands[7], "UBAH_FOTO_PROFIL", 16);

    assignWord(&commands[8], "DAFTAR_TEMAN", 12);

    assignWord(&commands[9], "HAPUS_TEMAN", 11);

    assignWord(&commands[10], "TAMBAH_TEMAN", 12);

    assignWord(&commands[11], "BATAL_TAMBAH_TEMAN", 18);

    assignWord(&commands[12], "DAFTAR_PERMINTAAN_PERTEMANAN", 28);

    assignWord(&commands[13], "SETUJUI_PERTEMANAN", 18);
}