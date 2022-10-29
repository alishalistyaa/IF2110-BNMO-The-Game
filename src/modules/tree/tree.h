/* File : bintree.h */
/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#ifndef POHON_H
#define POHON_H

#include "../boolean/boolean.h"

/* Selektor */
#define Root(p) (p)->Root
#define addressChild(p) (p)->Child
#define getChild(p,i) (p)->Child[i]
#define nChild(p) (p)->nChild

typedef int ElType;
typedef struct tNode* Address;
typedef struct tNode { 
     ElType Root; 
     Address *Child; //Array of child
     int nChild; //Banyaknya child 
} Node;

/* Definisi Pohon */
/* pohon kosong p = NULL */

typedef Address Tree;

Tree newTree(ElType root, Tree child[], int leaves); 
/* Menghasilkan sebuah pohon n-ary dari root dan child, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, Tree child[], int leaves, Tree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari root dan child Null, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.root=val, p↑.child = NULL dan p↑.nChild
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */



boolean isTreeEmpty (Tree p);
/* Mengirimkan true jika p adalah pohon yang kosong */

boolean isOneElmt (Tree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */


/* ****** Display Tree ***** */
void printPreorder(Tree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, sub pohon dari kiri ke kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */



void printTree(Tree p, int h);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, sub pohon dari kiri ke kanan dengan indentasi sebanyak h. 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (5(1(0())(1())(8())(27())(64()))(3(6(5())))(5())) akan ditulis sbb:
5
  1
    0
    1
    8
    27
    64
  3
    6
      5
  5
*/


//void printInorder(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

//void printPostorder(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

/* *** Searching *** */
boolean SearchTree(Tree p, ElType X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(Tree p);
/* Mengirimkan banyaknya elemen (node) pohon P */
int NbDaun(Tree p);
/* Mengirimkan banyaknya daun (node) pohon p */
/* Prekondisi: P tidak kosong */

int Level(Tree p, ElType X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Depth(Tree p);
/* Pohon  mungkin kosong. kedalaman pohon kosong = 0.
   Mengirim "depth" yaitu kedalaman dari pohon */

// /* *** Operasi lain *** */
void addLeaves(Tree *p, Tree child[], int leaves);
  /* I.S. p tidak kosong */
  /* F.S. p bertambah daunnya sejumlah leaves*/

// void AddDaunTerkiri(BinTree *P, infotype X);
// /* I.S. P boleh kosong */
// /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
// void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri);
// /* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
// /* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
//         sebagai anak Kanan X (jika Kiri = false) */
// /*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
// void DelDaunTerkiri(BinTree *P, infotype *X);
// /* I.S. P tidak kosong */
// /* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
//         disimpan pada daun terkiri yang dihapus */
// void DelDaun(BinTree *P, infotype X);
// /* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
// /* F.S. Semua daun bernilai X dihapus dari P. */
// List MakeListDaun(BinTree P);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
//    jika semua alokasi list berhasil.
//    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListPreorder(BinTree P);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
//    dengan urutan preorder, jika semua alokasi berhasil.   
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
// List MakeListLevel(BinTree P, int N);
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
//    yang levelnya=N, jika semua alokasi berhasil. 
//    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */

// /* *** Binary  Search  Tree  *** */
// boolean BSearch(BinTree P, infotype X);
// /* Mengirimkan true jika ada node dari P yang bernilai X */

// void InsSearch(BinTree *P, infotype X);
// /* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

// void DelBtree(BinTree *P, infotype X);
// /* I.S. Pohon P tidak  kosong */
// /* F.S. Nilai X yang dihapus pasti ada */
// /* Sebuah node dengan nilai X dihapus */

#endif