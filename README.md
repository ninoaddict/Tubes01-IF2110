<h1 align="center">Tubes01-IF2110</h1>

<h2 id = "description">✨ Deskripsi </h2>
Tugas Besar Algoritma dan Struktur Data: Burung Biru (BURBIR)


<h2 id = "table-of-contents">🔍 Daftar Isi</h2>
- <a href="#description">Deskripsi</a><br/>
- <a href="#table-of-contents">Daftar Isi</a><br/>
- <a href="#contributor">Kontributor</a><br/>
- <a href="#how-to-run">Cara Penggunaan Program</a><br/>
- <a href="#feat">Fitur</a>


<h2 id = "contributor">🌟Kontributor</h2>
<table>
  <tr>
    <th>Nama</th>
    <th>NIM</th>
  </tr>
  <tr>
    <th>Adril Putra Merin</th>
    <th>13522068</th>
  </tr>
  <tr>
    <th>Marvel Pangondian</th>
    <th>13522075</th>
  </tr>
  <tr>
    <th>Evelyn Yosiana</th>
    <th>13522083</th>
  </tr>
  <tr>
    <th>Sa'ad Abdul Hakim</th>
    <th>13522092</th>
  </tr>
  <tr>
    <th>Fabian Radenta Bangun</th>
    <th>13522105</th>
  </tr>
</table>


<h2 id="how-to-run">📘 Cara Penggunaan Program</h2>

### Run Program
1. Clone _repository_ ini pada _device_ dan tambahkan folder bin pada _root directory_
```bash
git clone https://github.com/ninoaddict/Tubes01-IF2110
```
3. Jika anda menggunakan _device_ berbasis UNIX seperti MacOS atau Linux, jalankan _command_ berikut pada terminal Anda
```bash
make all
```
4. Untuk menghapus _file_ .o setelah menjalankan program, jalankan _command_ berikut pada terminal Anda
```bash
make clean
```
5. Jika anda menggunakan Windows (dapat digunakan juga pada MacOS dan Linux), jalankan _command_ berikut pada terminal Anda
```bash
gcc -o bin/main src/main.c lib/charmachine/charmachine.c lib/wordmachine/wordmachine.c lib/dsu/dsu.c lib/graph/graph.c lib/matrix/matrix.c lib/maxheap/maxheap.c lib/priorityqueue/priorityqueue.c lib/time/time.c lib/datetime/datetime.c src/db.c src/app/user/user.c src/app/user/listuser.c src/app/user/pcolor.c src/app/tweet/tweet.c src/app/tweet/listkicauan.c src/app/thread/thread.c src/app/saveload/save.c src/app/saveload/load.c src/app/reply/reply.c src/app/reply/treebalasan.c src/app/hashtag/hashtag.c src/app/fyb/fyb.c src/app/friend/friend.c src/app/friend/friendrequest.c src/app/draft/draft.c src/app/draft/liststackdraft.c
```
6. Kemudian, jalankan _command_ berikut
```bash
./bin/main
```


<h2 id="feat">📱Fitur</h2>

### Daftar perintah
| Perintah | Deskripsi |
| ------------- | ------------- |
| DAFTAR | Untuk mendaftarkan akun |
| MASUK | Untuk masuk ke dalam akun yang sudah terdaftar |
| KELUAR | Untuk keluar dari akun saat ini |
| GANTI_PROFIL | Untuk mengganti profil |
| LIHAT_PROFIL [NAMA] | Untuk melihat profil pengguna dengan nama [NAMA] |
| ATUR_JENIS_AKUN | Untuk mengganti jenis akun dari publik ke privat atau sebaliknya |
| UBAH_FOTO_PROFIL | Untuk mengubah foto profil dari pengguna saat ini |
| DAFTAR_TEMAN | Untuk menampilkan daftar teman |
| HAPUS_TEMAN | Untuk menghapus teman yang dipunyai pengguna |
| TAMBAH_TEMAN | Untuk menambah teman dengan mengajukan permintaan pertemanan |
| DAFTAR_PERMINTAAN_PERTEMANAN | Untuk melihat daftar permintaan pertemanan yang diajukan kepada pengguna |
| SETUJUI_PERTEMANAN | Untuk mengkonfirmasi permintaan pertemanan dari pengguna dengan _teman_ paling banyak |
| KICAU | Untuk membuat kicauan |
| KICAUAN | Untuk menampilkan kicauan |
| SUKA_KICAUAN [IDKicau] | Untuk menyukai kicauan dengan id [IDKicau] |
| UBAH_KICAUAN [IDKicau] | Untuk mengubah isi kicauan dengan id [IDKicau] |
| BALAS [IDKicau] [IDBalasan] | Untuk membalas kicauan pada id [IDKicau] dengan id balasan [IDBalasan] |
| HAPUS_BALASAN [IDKicau] [IDBalasan] | Untuk menghapus balasan pada id [IDKicau] dengan id balasan [IDBalasan] |
| BUAT_DRAF | Untuk membuat draf |
| LIHAT_DRAF | Untuk melihat draf |
| UTAS [IDKicau] | Untuk membuat utas pada id [IDKicau] |
| SAMBUNG_UTAS [IDUtas] [index] | Untuk menyambung utas dengan id utas [IDUtas] dan index [index] |
| HAPUS_UTAS [IDUtas] [index] | Untuk menghapus kicauan dalam sebuah utas dengan id = [IDUtas] |
| CETAK_UTAS [IDUtas] | Untuk mencetak utas |
| SIMPAN | Untuk menyimpan data saat ini ke dalam file config |
| MUAT | Untuk memuat data dari file config |
| CARI_KICAUAN [Tagar] | Untuk menampilkan kicauan dengan tagar [Tagar] | 
| KELOMPOK_TEMAN | Untuk menampilkan kelompok teman dari pengguna | 
| FYB | Untuk menampilkan 8 Kicauan dengan like tertinggi |
