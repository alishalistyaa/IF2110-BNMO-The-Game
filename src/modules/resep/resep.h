#include "../tree/tree.h"
#include "../boolean/boolean.h"
#ifndef RESEP_H
#define RESEP_H
//Membuat ADT resep dan buku resep dengan model list statik secara eksplisit

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARKRESEP NULL
/* Nilai elemen tak terdefinisi*/
#define MARKMAKANAN -999
/*ID untuk Makanan tak terdefinisi*/

//Definisi untuk "Method" pengolahan resep
#define MIX 0xF
#define CHOP 0xFF
#define FRY 0xFFF
#define BOIL 0xFFFF

/* Definisi Resep berbasiskan pohon n-ary */
typedef Tree Resep;

//Koleksi indeks buku resep
typedef int IdxResep;

/* Definisi BukuResep*/
typedef struct {
   Resep contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int nResep;
} BukuResep;

// --SELEKTOR--
#define ELMTBUKURESEP(b, i) (b).contents[i]
#define BanyakResep(b) (b).nResep
#define MethodResep(r) Method(r)

//--KONSTRUKTOR--

void CreateBukuResep(BukuResep *b);
/* I.S. r sembarang */
/* F.S. Terbentuk resep kosong  */
/* Proses: Inisialisasi semua elemen resep dengan MARK */  

//--PREDIKAT--
//boolean isResepValid(BukuResep b, Resep r);
/* Mengirimkan true jika i adalah elemen yang valid dari BukuResep */


boolean isBukuResepEmpty(BukuResep b);
/* Mengirimkan true jika Buku Resep kosong, mengirimkan false jika tidak */

boolean isBukuResepFull(BukuResep b);
/* Mengirimkan true jika Buku Resep penuh, mengirimkan false jika tidak */

void insertResep(BukuResep *b,Resep r);
/* Menambah Resep pada buku resep; apabila sudah penuh tidak perlu ditambahkan*/

//Fungsi-funsgi tambahan
void delResep(BukuResep *b, Resep *buffer,IdxResep i);
/*Menghapus elemen indeks ke i pada list*/

void cetakBukuResep(BukuResep b);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
/* Contoh : jika ada tiga elemen*/
/* 1 . Nama makanan 1*/
/* 2 . Nama makanan 2*/
/* 3 . Nama makanan 3*/
//void printResep(Resep r);

boolean isResepOlah_able(Resep r);

void setMethod(Resep *r);
// Resep concatResep(Resep r1, Resep r2);
/*Melakukan konkatenasi Resep 2 ke resep 1*/
#endif