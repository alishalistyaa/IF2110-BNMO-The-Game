#ifndef LISTRESEP_H
#define LISTRESEP_H

#include "../boolean/boolean.h"
#include "../tree/tree.h"

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
   Tree contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int Neff;
} ListResep;

#define ELMTLIST(l, i) (l).contents[(i)]

//--KONSTRUKTOR--

void CreateListResep(ListResep *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

int lengthList(ListResep l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

boolean isFoodValid(ListResep l, Tree val);
/* Mengirimkan true jika i adalah elemen yang valid dari list */

boolean isIdxListEff(ListResep l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

boolean isEmpty(ListResep l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */


boolean isFull(ListResep l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

void insert(ListResep *l,Tree val);
/* Menambah elemen val sebagai elemen terakhir list*/

void deleteList(ListResep *l,Tree *val,IdxType i);
/*Menghapus elemen indeks ke i pada list*/

void cetakList(ListResep l);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
/* Contoh : jika ada tiga elemen*/
/* 1 . Nama makanan 1*/
/* 2 . Nama makanan 2*/
/* 3 . Nama makanan 3*/
void CopyList(ListResep l1,ListResep *l2);
/*Menyalin semua elemen di list 1 ke list 2*/

#endif