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
boolean IsEmpty(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return Top(S) == Nil;
}
boolean IsFull(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return Top(S) == MaxEl - 1;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (IsEmpty(*S)) {
        Top(*S) = 0;
    }
    else {
        Top(*S)++;
    }
    for (int i = 0; i < X.Length; i++) {
        InfoTop(*S).TabWord[i] = X.TabWord[i];
    }
    InfoTop(*S).Length = X.Length;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype * X) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    for (int i = 0; i < InfoTop(*S).Length; i++) {
        (*X).TabWord[i] = InfoTop(*S).TabWord[i];
    }
    (*X).Length = InfoTop(*S).Length;
    if (Top(*S) == 0) {
        Top(*S) = Nil;
    } else {
        Top(*S)--;
    }
}

void Undo(Stack *Undo, Stack *Redo) {
/* Melakukan proses undo */
/* Menghapus Top dari Stack Undo dan memasukkannya ke Stack Redo */
    Word s;
    Pop(Undo, &s);
    Push(Redo, s);
}
void Redo(Stack *Undo, Stack *Redo) {
/* Melakukan proses redo */
/* Menghapus Top dari Stack Redo dan memasukkannya ke Stack Undo */
    Word s;
    Pop(Redo, &s);
    Push(Undo, s);
}