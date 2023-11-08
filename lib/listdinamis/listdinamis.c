#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
{
  BUFFER(*l) = (int *)malloc(capacity * sizeof(int));
  NEFF(*l) = 0;
  CAPACITY(*l) = capacity;
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
}

void dealocateList(ListDin *l)
{
  free(BUFFER(*l));
  NEFF(*l) = 0;
  CAPACITY(*l) = 0;
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
}

int listLength(ListDin l)
{
  return (NEFF(l));
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  /* *** Daya tampung container *** */
}

IdxType getFirstIdx(ListDin l)
{
  return (IDX_MIN);
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l pertama */
}

IdxType getLastIdx(ListDin l)
{
  return (NEFF(l) - 1);
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l terakhir */
}

boolean isIdxValid(ListDin l, IdxType i)
{
  return (i >= 0) && (i < CAPACITY(l));
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
  /* yaitu antara indeks yang terdefinisi utk container*/
}

boolean isIdxEff(ListDin l, IdxType i)
{
  return (i >= 0) && (i < NEFF(l));
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
  /* yaitu antara 0..NEFF(l) */
}

boolean isEmpty(ListDin l)
{
  return (listLength(l) == 0);
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  /* *** Test list penuh *** */
}

boolean isFull(ListDin l)
{
  return (NEFF(l) == CAPACITY(l));
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
}

void readList(ListDin *l)
{
  int i, n, value;
  scanf("%d", &n);
  while ((n < 0) || (n > CAPACITY(*l)))
  {
    scanf("%d", &n);
  }
  CreateListDin(l, CAPACITY(*l));
  if (n > 0)
  {
    for (i = 0; i < n; i++)
    {
      scanf("%d", &value);
      ELMT(*l, i) = value;
    }
  }
  NEFF(*l) = n;
  /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
  /* F.S. List l terdefinisi */
  /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
  /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
  /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
  /*    Jika N = 0; hanya terbentuk l kosong */
}

void printList(ListDin l)
{
  int i;
  printf("[");
  if (!isEmpty(l))
  {
    for (i = IDX_MIN; i < listLength(l); i++)
    {
      printf("%d", ELMT(l, i));
      if (i < listLength(l) - 1)
      {
        printf(",");
      }
    }
  }
  printf("]");
  /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. l boleh kosong */
  /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
  int i;
  ListDin l3;
  CreateListDin(&l3, CAPACITY(l1));
  NEFF(l3) = NEFF(l1);
  if (plus)
  {
    for (i = IDX_MIN; i < listLength(l1); i++)
    {
      ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
    }
  }
  else
  {
    for (i = IDX_MIN; i < listLength(l1); i++)
    {
      ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
    }
  }
  return (l3);
  /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
}

boolean isListEqual(ListDin l1, ListDin l2)
{
  boolean eq = true;
  int i;
  if (listLength(l1) != listLength(l2))
  {
    eq = false;
  }
  for (i = IDX_MIN; i < listLength(l1); i++)
  {
    if (ELMT(l1, i) != ELMT(l2, i))
    {
      eq = false;
    }
  }
  return (eq);
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
}

IdxType indexOf(ListDin l, ElType val)
{
  int idx_val = IDX_UNDEF, i;
  if (isEmpty(l))
  {
    return (IDX_UNDEF);
  }
  else
  {
    for (i = IDX_MIN; i < listLength(l); i++)
    {
      if (ELMT(l, i) == val)
      {
        idx_val = i;
        break;
      }
    }
    if (idx_val == IDX_UNDEF)
    {
      return (IDX_UNDEF);
    }
    else
    {
      return (idx_val);
    }
  }
  /* Search apakah ada elemen List l yang bernilai val */
  /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
  /* Jika tidak ada, mengirimkan IDX_UNDEF */
  /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
  /* Skema Searching yang digunakan bebas */
}

void extremeValues(ListDin l, ElType *max, ElType *min)
{
  int i;
  *max = ELMT(l, 0);
  *min = ELMT(l, 0);
  for (i = 1; i < listLength(l); i++)
  {
    if (ELMT(l, i) > *max)
    {
      *max = ELMT(l, i);
    }
    if (ELMT(l, i) < *min)
    {
      *min = ELMT(l, i);
    }
  }
  /* I.S. List l tidak kosong */
  /* F.S. max berisi nilai maksimum l;
  min berisi nilai minimum l */
}

void copyList(ListDin lIn, ListDin *lOut)
{
  int i;
  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for (i = 0; i < listLength(lIn); i++)
  {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
  /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
  /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
  /* Proses : Menyalin isi lIn ke lOut */
}

ElType sumList(ListDin l)
{
  if (isEmpty(l))
  {
    return 0;
  }
  else
  {
    int sum, i;
    sum = 0;
    for (i = 0; i < NEFF(l); i++)
    {
      sum += ELMT(l, i);
    }
    return (sum);
  }
  /* Menghasilkan hasil penjumlahan semua elemen l */
  /* Jika l kosong menghasilkan 0 */
}

int countVal(ListDin l, ElType val)
{
  if (isEmpty(l))
  {
    return 0;
  }
  else
  {
    int count, i;
    count = 0;
    for (i = 0; i < listLength(l); i++)
    {
      if (ELMT(l, i) == val)
      {
        count += 1;
      }
    }
    return (count);
  }
  /* Menghasilkan berapa banyak kemunculan val di l */
  /* Jika l kosong menghasilkan 0 */
}

void sort(ListDin *l, boolean asc)
{
  int i, j;
  ElType temp;
  if (!asc)
  {
    for (i = IDX_MIN; i < listLength(*l); i++)
    {
      for (j = IDX_MIN; j < listLength(*l); j++)
      {
        if (ELMT(*l, i) > ELMT(*l, j))
        {
          temp = ELMT(*l, i);
          ELMT(*l, i) = ELMT(*l, j);
          ELMT(*l, j) = temp;
        }
      }
    }
  }
  else
  {
    for (i = IDX_MIN; i < listLength(*l); i++)
    {
      for (j = IDX_MIN; j < listLength(*l); j++)
      {
        if (ELMT(*l, i) < ELMT(*l, j))
        {
          temp = ELMT(*l, i);
          ELMT(*l, i) = ELMT(*l, j);
          ELMT(*l, j) = temp;
        }
      }
    }
  }
  /* I.S. l boleh kosong */
  /* F.S. Jika asc = true, l terurut membesar */
  /*      Jika asc = false, l terurut mengecil */
  /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
     algoritma bebas */
}

void insertLast(ListDin *l, ElType val)
{
  ELMT(*l, NEFF(*l)) = val;
  NEFF(*l) += 1;
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
}

void deleteLast(ListDin *l, ElType *val)
{
  *val = ELMT(*l, getLastIdx(*l));
  NEFF(*l) -= 1;
  /* Proses : Menghapus elemen terakhir list */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen list berkurang satu */
  /*      List l mungkin menjadi kosong */
}

void expandList(ListDin *l, int num)
{
  BUFFER(*l) = (int *)realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(int));
  CAPACITY(*l) += num;
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
}

void shrinkList(ListDin *l, int num)
{
  BUFFER(*l) = (int *)realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(int));
  CAPACITY(*l) -= num;
  /* Proses : Mengurangi capacity sebanyak num */
  /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
}

void compressList(ListDin *l)
{
  BUFFER(*l) = (int *)realloc(BUFFER(*l), NEFF(*l) * sizeof(int));
  CAPACITY(*l) = NEFF(*l);
  /* Proses : Mengubah capacity sehingga capacity = nEff */
  /* I.S. List tidak kosong */
  /* F.S. Ukuran capacity = nEff */
}

// int main()
// {
//   ListDin l1, l2, l3;
//   ElType val;
//   readList(&l1);
//   readList(&l2);
//   l3 = plusMinusList(l1, l2, true);
//   printList(l3);
//   return 0;
// }

// 42 43 sort
// 25 26 plus minus