#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"




void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateListDin(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (IdxType)NEFF(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= IDX_MIN) && (i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (i >= IDX_MIN) && (i <= NEFF(l));
}

boolean isEmptyDin(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return listLength(l) == 0;
}

boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

    return listLength(l) == CAPACITY(l);
}

void readListDin(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
    int N,i,element;
    scanf("%d",&N);
    while (N < IDX_MIN || N > CAPACITY(*l)){
        scanf("%d",&N);

    }
    if (N!=0){
        for (i = 0; i < N ; ++i){
            scanf("%d",&element);
            ELMT(*l,i) = element;

        }
    }
    NEFF(*l) = N;
   
}


void printList(ListDin l){
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    int i;
    printf("[");
    for (i = 0 ; i < NEFF(l) ; ++i){
        if (i != NEFF(l) - 1){
            printf("%d,",ELMT(l,i));
        }
        else{
            printf("%d",ELMT(l,i));
        }
    }

    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

    ListDin l3;
    int i;
    CreateListDin(&l3,NEFF(l1));
    if (plus){
    for (i = 0 ; i < NEFF(l1) ; ++i){
        ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
    }
    }
    else{
        for (i = 0 ; i < NEFF(l1) ; ++i){
        ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
    }
    }
    NEFF(l3) = NEFF(l1); // CHECK
    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

    if (NEFF(l1) == NEFF(l2)){
        boolean state = true;
        int i;
        for (i = 0; i < NEFF(l1) ; ++i){
            if (ELMT(l1,i) != ELMT(l2,i)){
                state = false;
            }
        }
        return state;

    }
    else{
        return false;
    }
}

IdxType indexOfDin(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    int index = IDX_UNDEF;
    int i;
    for (i = 0 ; i < NEFF(l) ; ++i){
        if (ELMT(l,i) == val){
            index = i;
            break;
        }
    }
    return index;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

    *max = ELMT(l,0);
    *min = ELMT(l,0);

    int i;
    for (i = 0 ; i < NEFF(l) ; ++i){
        if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min){
            *min = ELMT(l,i);
        }
        
    }

}

void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    int i;
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn) ; ++i){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    int i;
    ElType sum ;
    sum = 0;
    for (i = 0 ; i < NEFF(l) ; ++i){
        sum += ELMT(l,i);
        }
    return sum;
    
}

int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int count,i;
    count = 0;
    for (i = 0 ; i < NEFF(l) ; ++i){
        if (ELMT(l,i) == val){
            count += 1;
        }

    }
    return count;
}

void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
     int i,k,temp;
    if (asc == true){
       int idmin;
        for (i=0 ; i < listLength(*l) ; ++i){
            idmin = i;
            for (k = i + 1; k < listLength(*l) ; ++k){
                if (ELMT(*l,k) < ELMT(*l,idmin)){
                    idmin = k;
                }

            }
            temp = ELMT(*l,i);
            ELMT(*l,i) = ELMT(*l,idmin);
            ELMT(*l,idmin) = temp;
        }
    }
    else{
        int idmax;
        for (i = 0; i < listLength(*l) ; ++i){
            idmax = i;
            for (k = i + 1; k < listLength(*l) ; ++k){
                if (ELMT(*l,k) > ELMT(*l,idmax)){
                    idmax = k;
                }
            }
            temp = ELMT(*l,i);
            ELMT(*l,i) = ELMT(*l,idmax);
            ELMT(*l,idmax) = temp;

        }
    }
}

void insertLastDin(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (!isFull(*l)){
        ELMT(*l,NEFF(*l)) = val;
        NEFF(*l) += 1;
    }
}

void deleteLastDin(ListDin *l, ElType *val){
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    if (!isEmptyDin(*l)){
        *val = ELMT(*l, NEFF(*l)-1);
        NEFF(*l) -= 1;
    }
}
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

    ListDin lstore;
    int i;
    CreateListDin(&lstore,CAPACITY(*l) + num);
    NEFF(lstore) = NEFF(*l);
    for (i = 0 ; i < NEFF(*l) ; ++i){
        ELMT(lstore,i) = ELMT(*l,i);
    }
    dealocateListDin(l);
    copyList(lstore,l);

}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    ListDin lstore;
    int i;
    CreateListDin(&lstore,CAPACITY(*l) - num);
    NEFF(lstore) = NEFF(*l);
    for (i = 0 ; i < NEFF(*l) ; ++i){
        ELMT(lstore,i) = ELMT(*l,i);
    }
    dealocateListDin(l);
    copyList(lstore,l);
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
     ListDin lstore;
    int i;
    CreateListDin(&lstore,NEFF(*l));
    NEFF(lstore) = NEFF(*l);
    for (i = 0 ; i < NEFF(*l) ; ++i){
        ELMT(lstore,i) = ELMT(*l,i);
    }
    dealocateListDin(l);
    copyList(lstore,l);

}