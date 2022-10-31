#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../boolean/boolean.h"
#include "../makanan/makanan.h"

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

#define ELMT(l, i) (l).contents[(i)]

//--KONSTRUKTOR--

void CreateListStatik(ListStatik *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

int lengthList(ListStatik l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

boolean isFoodValid(ListStatik l, MAKANAN val);
/* Mengirimkan true jika i adalah elemen yang valid dari list */

boolean isIdxEff(ListStatik l, IdxType i);
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
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
/* Contoh : jika ada tiga elemen*/
/* 1 . Nama makanan 1*/
/* 2 . Nama makanan 2*/
/* 3 . Nama makanan 3*/
void CopyList(ListStatik l1,ListStatik *l2);
/*Menyalin semua elemen di list 1 ke list 2*/

#endif