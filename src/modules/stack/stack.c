// NIM : 13521156
// Nama : Brigita Tri Carolina
// Tanggal : 16 Oktober 2022
// Topik : ADT Stack
// Deskripsi : Program berisi implementasi dari fungsi-fungsi pada stack.h

#include "stack.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return Top(S) == Nil;
}
boolean IsFullStack(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return Top(S) == State - 1;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (IsEmptyStack(*S)) {
        Top(*S) = 0;
    }
    else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype * X) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    if (Top(*S) == 0) {
        Top(*S) = Nil;
    } else {
        Top(*S)--;
    }
}

void Undo(Stack *undo, Stack *Redo, Word *command, PrioQueue *I, PrioQueue *D, STOCK *stock, TIME *T, POINT *l) {
/* Melakukan proses undo */
/* Menghapus Top dari Stack Undo dan memasukkannya ke Stack Redo */
    infotype s;
    Pop(undo, &s);
    *command = InfoTop(*undo).command;
    *I = InfoTop(*undo).I;
    *D = InfoTop(*undo).D;
    *T = InfoTop(*undo).T;
    *l = InfoTop(*undo).l;
    *stock = InfoTop(*undo).stock;
    Push(Redo, s);
}
void Redo(Stack *undo, Stack *Redo, Word *command, PrioQueue *I, PrioQueue *D, STOCK *stock, TIME *T, POINT *l) {
/* Melakukan proses redo */
/* Menghapus Top dari Stack Redo dan memasukkannya ke Stack Undo */
    infotype s;
    Pop(Redo, &s);
    Push(undo, s);
    *command = InfoTop(*undo).command;
    *I = InfoTop(*undo).I;
    *D = InfoTop(*undo).D;
    *T = InfoTop(*undo).T;
    *l = InfoTop(*undo).l;
    *stock = InfoTop(*undo).stock;
}

void updateState(Word command, PrioQueue I, PrioQueue D, STOCK stock, TIME T, POINT l, Stack *undo) {
/* Menginput atau mengupdate state */
/* I. S. undo, M, T, l terdefinisi*/
/* F. S. terbentuk infotype X untuk dan X telah di-push ke stack */
  infotype X;
  X.command = command;
  X.I = I;
  X.D = D;
  X.T = T;
  X.l = l;
  X.stock = stock;
  Push(undo, X);
}