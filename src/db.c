#include "db.h"
int currID;
int currTweetID;
ListUser listuser;
Friend friendGraph;
int idxCommand;
Word command[20];
Word commands[40];
DATETIME current_time;
ListKicauan lkic;
int id_kicau;
int id_utas;
boolean run;
HashTag hashtag;
ListStackDraft lsd;

void setup()
{
    run = true;
    currID = -1;
    createListKicauan(&lkic, 50);
    currTweetID = 0;
    id_utas = 1;
    CreateListUser(&listuser);
    CreateFriend(&friendGraph);
    CreateHashTag(&hashtag);
    CreateListStackDraft(&lsd);

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

    assignWord(&commands[14], "KICAU", 5);

    assignWord(&commands[15], "KICAUAN", 7);

    assignWord(&commands[16], "SUKA_KICAUAN", 12);

    assignWord(&commands[17], "UBAH_KICAUAN", 12);

    assignWord(&commands[18], "UTAS", 4);

    assignWord(&commands[19], "SAMBUNG_UTAS", 12);

    assignWord(&commands[20], "HAPUS_UTAS", 10);

    assignWord(&commands[21], "CETAK_UTAS", 10);

    assignWord(&commands[22], "KELOMPOK_TEMAN", 14);

    assignWord(&commands[23], "FYB", 3);

    assignWord(&commands[24], "CARI_KICAUAN", 12);

    assignWord(&commands[25], "BUAT_DRAF", 9);

    assignWord(&commands[26], "LIHAT_DRAF", 10);

    assignWord(&commands[27], "BALAS", 5);

    assignWord(&commands[28], "BALASAN", 7);

    assignWord(&commands[29], "HAPUS_BALASAN", 13);

    assignWord(&commands[30], "MUAT", 4);

    assignWord(&commands[31], "SIMPAN", 6);
}
