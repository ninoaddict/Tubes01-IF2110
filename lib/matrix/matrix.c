# include <stdio.h>
# include "matrix.h"

/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (0 <= i && i < ROW_CAP) && (0 <= j && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m) - 1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m) - 1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (0 <= i && i < ROW_EFF(m)) && (0 <= j && j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    *mOut = mIn;
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    int i, j;
    createMatrix(nRow, nCol, m);
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if (j != getLastIdxCol(m)){
                printf(" ");
            }
        }
        if (j != getLastIdxRow(m)){
            printf("\n");
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(m1, i, j) += ELMT(m2, i, j);
        }
    }
    return m1;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(m1, i, j) -= ELMT(m2, i, j);
        }
    }
    return m1;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m2); j++){
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++){
                ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);   
            }
        }
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix m3;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m2); j++){
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++){
                ELMT(m3, i, j) = (ELMT(m3, i, j) + ELMT(m1, i, k) * ELMT(m2, k, j)) % mod;   
            }
        }
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x){
    for (int i = 0; i < ROW_EFF(m); i++){
        for (int j = 0; j < COL_EFF(m); j++){
            ELMT(m, i, j) *= x;
        }
    }
    return m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    for (int i = 0; i < ROW_EFF(*m); i++){
        for (int j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (getLastIdxRow(m1) == getLastIdxRow(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)){
        int i, j;
        for (i = 0; i < ROW_EFF(m1); i++){
            for (j = 0; j < COL_EFF(m1); j++){
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !(isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return (ROW_EFF(m) * COL_EFF(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    if (isSquare(m)){
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = i + 1; j < COL_EFF(m); j++){
                if (ELMT(m, i, j) != ELMT(m, j, i)) return false;
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    if (isSquare(m)){
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < COL_EFF(m); j++){
                if ((i == j && ELMT(m, i, j) != 1) || (i != j && ELMT(m, i, j) != 0)) return false;
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    int cnt = 0;
    for (int i = 0; i < ROW_EFF(m); i++){
        for (int j = 0; j < COL_EFF(m); j++){
            if (ELMT(m, i, j)) cnt++;
        }
    }
    return (20 * cnt <= countElmt(m));
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(m, i, j) *= -1;
        }
    }
    return m;
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) *= -1;
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
Matrix minor(Matrix m, int row, int col){
    Matrix res;
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &res);
    int r = 0, c = 0, i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        if (i != row){
            c = 0;
            for (j = 0; j < COL_EFF(m); j++){
                if (j != col){
                    ELMT(res, r, c) = ELMT(m, i, j);
                    c++;
                }
            }
            r++;
        }
    }
    return res;
}

float determinant(Matrix m){
    if (ROW_EFF(m) == 1) return (float)ELMT(m, 0, 0);
    float res = 0;
    int i;
    for (i = 0; i < ROW_EFF(m); i++){
        res += (i & 1)? (-1.0) * ELMT(m, i, 0) * determinant(minor(m, i, 0)) : ELMT(m, i, 0) * determinant(minor(m, i, 0));
    }
    return res;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    int i, j;
    Matrix temp;
    createMatrix(COL_EFF(m), ROW_EFF(m), &temp);
    for (i = 0; i < ROW_EFF(temp); i++){
        for (j = 0; j < COL_EFF(temp); j++){
            ELMT(temp, i, j) = ELMT(m, j, i);
        }
    }
    return temp;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    *m = transpose(*m);
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */