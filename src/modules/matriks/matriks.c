// NIM : 13521156
// Nama : Brigita Tri Carolina
// Tanggal : 18 September 2022
// Topik : ADT Matrix
// Deskripsi : Program berisi definisi dari fungsi-fungsi pada matrix.h

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) { 
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP;
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxTypeMAT getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    return ROW_EFF(m) - 1;
}
IdxTypeMAT getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    return COL_EFF(m) - 1;
}
boolean isIdxEff(Matrix m, IdxTypeMAT i, IdxTypeMAT j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m);
}
ElTypeMAT getElmtDiagonal(Matrix m, IdxTypeMAT i) {
/* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
/* Melakukan assignment mOut <- mIn */
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (int i = 0; i < ROW_EFF(mIn); i++) {
        for (int j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j); 
        }
    }

}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
###
***
###
*/  
/* Pembacaan char tanpa spasi dan setiap barisnya diakhiri enter */
    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("\n%c", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
# # #
# # # 
# # # 
*/
    for(int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (j == COL_EFF(m) - 1) {
                printf("%c\n", ELMT(m, i, j));
            } else {
                printf("%c ", ELMT(m, i, j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (countElmt(m1) == countElmt(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)) {
        for (int i = 0; i < ROW_EFF(m1); i++) {
            for (int j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return !isMatrixEqual(m1, m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    return ROW_EFF(m)*COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return  ROW_EFF(m) == COL_EFF(m);
}