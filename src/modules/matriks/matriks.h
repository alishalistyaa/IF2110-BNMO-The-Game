/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "../boolean/boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxTypeMAT; /* Index baris, kolom */
typedef char ElTypeMAT;
typedef struct
{
   ElTypeMAT mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMTMAT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxTypeMAT getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
IdxTypeMAT getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxTypeMAT i, IdxTypeMAT j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElTypeMAT getElmtDiagonal(Matrix m, IdxTypeMAT i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol);
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
void displayMatrix(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
# # #
# # # 
# # # 
*/

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

boolean isBuilding(char c);
/* Mengirimkan true jika c adalah bagian dari building */

#endif