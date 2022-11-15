#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../boolean/boolean.h"
#include "../makanan/makanan.h"
// #include "../i_o/i_o.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../time/time.h"
#include "../point/point.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARKLIST -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
   MAKANAN contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;

/* *** Definisi TYPE STOCK *** */
typedef struct {
   int buffer[CAPACITY]; 
} STOCK;

#define ELMTLIST(l, i) (l).contents[(i)]
#define Effective_Capacity(l) (l).effCapacity
#define ELMTSTOCK(s, i) (s).buffer[i]

//--KONSTRUKTOR--
void CreateStock(STOCK *s);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

void IncreaseStock(STOCK *s, int ID);
/* Menambahkan satu stock pada ID tertentu */

void DecreaseStock(STOCK *s, int ID);
/* Mengurangi satu stock pada ID tertentu */

void CopyStock(STOCK S1, STOCK *S2);
/*Melakukan penyalinan tiap elemen stock ke S2*/

void displayStock(STOCK S, ListStatik l);
/*Mencetak elemen stok*/

void CreateListStatik(ListStatik *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

int lengthList(ListStatik l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

Word getNameMakanan(ListStatik l, int idx);
/* Mengirimkan nama makanan dari ID */

MAKANAN getMakanan(ListStatik l, int ID);
/* Mendapatkan makanan dari ID */

// boolean isFoodValid(ListStatik l, int ID_Makanan);
/* Mengirimkan true jika i adalah elemen yang valid dari list */

boolean isIdxListEff(ListStatik l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

boolean isEmpty(ListStatik l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

boolean isFull(ListStatik l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

void insert(ListStatik *l,MAKANAN val);
/* Menambah elemen val sebagai elemen terakhir list*/

void delete(ListStatik *l,MAKANAN *val,IdxType i);
/*Menghapus elemen indeks ke i pada list*/

void cetakList(ListStatik l);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
/* Contoh : jika ada tiga elemen*/
/* 1 . Nama makanan 1*/
/* 2 . Nama makanan 2*/
/* 3 . Nama makanan 3*/
void CopyList(ListStatik l1,ListStatik *l2);
/*Menyalin semua elemen di list 1 ke list 2*/


// void displayBuyable(ListStatik l, ListStatik *buylist);
// /* Menampilkan list yang dapat dibeli sekaligus membentuknya*/

// void displayCookMethod(ListStatik l, ListStatik *mixlist, char *method);
// /* Menampilkan list dengan cook Method tertentu (FRY, BOIL, etc)*/
#endif