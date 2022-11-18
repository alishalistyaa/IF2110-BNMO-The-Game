// NIM : 13521156
// Nama : Brigita Tri Carolina
// Tanggal : 16 Oktober 2022
// Topik : ADT Stack
// Deskripsi : Program berisi implementasi dari fungsi-fungsi pada stack.h

#include "stack.h"
#include "../boolean/boolean.h"
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

// /* ************ Predikat Untuk test keadaan KOLEKSI ************ */
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
        printf("Penambahan\n");
        Top(*S)++;
    }
    InfoTop(*S).command = X.command;
    MakeEmpty(&(InfoTop(*S).I), MaxEl(X.I));
    CopyQueue(X.I, &(InfoTop(*S).I));
    MakeEmpty(&(InfoTop(*S).D), MaxEl(X.D));
    CopyQueue(X.D, &(InfoTop(*S).D));
    InfoTop(*S).T = X.T;
    InfoTop(*S).l = X.l;
    CopyStock(X.stock, &(InfoTop(*S).stock));
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype * X) {
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    (*X).command = InfoTop(*S).command;

    MakeEmpty(&(*X).I, MaxEl((InfoTop(*S).I)));
    CopyQueue(InfoTop(*S).I, &((*X).I));
    // DeAlokasi(&(InfoTop(*S).I));
    MakeEmpty(&(*X).D, MaxEl((InfoTop(*S).D)));
    CopyQueue(InfoTop(*S).D, &((*X).D));
    // DeAlokasi(&(InfoTop(*S).D));

    (*X).T = InfoTop(*S).T;
    (*X).l = InfoTop(*S).l;
    CopyStock(InfoTop(*S).stock, &((*X).stock));
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
    printf("TOP UNDO: %d\n", Top(*undo));
    *command = InfoTop(*undo).command;
    CopyQueue(InfoTop(*undo).I, I);
    CopyQueue(InfoTop(*undo).D, D);
    *T = InfoTop(*undo).T;
    *l = InfoTop(*undo).l;
    TulisPOINT(InfoTop(*undo).l);
    printf("\n");
    CopyStock(InfoTop(*undo).stock, stock);
    Push(Redo, s);
    printf("Command : %s\n", InfoTop(*Redo).command.TabWord);
}
void Redo(Stack *undo, Stack *Redo, Word *command, PrioQueue *I, PrioQueue *D, STOCK *stock, TIME *T, POINT *l) {
    /* Melakukan proses redo */
    /* Menghapus Top dari Stack Redo dan memasukkannya ke Stack Undo */
    infotype s;
    Pop(Redo, &s);
    Push(undo, s);
    printf("TOP UNDO: %d\n", Top(*undo));
    printf("Command : %s\n", InfoTop(*undo).command.TabWord);
    *command = InfoTop(*undo).command;
    CopyQueue(InfoTop(*undo).I, I);
    CopyQueue(InfoTop(*undo).D, D);
    *T = InfoTop(*undo).T;
    *l = InfoTop(*undo).l;
    CopyStock(InfoTop(*undo).stock, stock);
    printf("Loc : ");
    TulisPOINT(InfoTop(*undo).l);
    printf("\n");
}

void updateState(Word command, PrioQueue I, PrioQueue D, STOCK stock, TIME T, POINT l, Stack *undo) {
/* Menginput atau mengupdate state */
/* I. S. undo, M, T, l terdefinisi*/
/* F. S. terbentuk infotype X untuk dan X telah di-push ke stack */
  infotype X;
  X.command = command;
  MakeEmpty(&(X.I), MaxEl(I));
  CopyQueue(I, &(X.I));
  printInventoryExpired(X.I);
  MakeEmpty(&(X.D), MaxEl(D));
  CopyQueue(D,&(X.D));
  printInventoryDelivery(X.D);
  CreateTime(&(X.T), T.DD, T.HH, T.MM);
  TulisTIME1(X.T);
  CreatePoint(&(X.l), l.X, l.Y);
  TulisPOINT(X.l);
  CreateStock(&(X.stock));
  CopyStock(stock, &X.stock);

    Push(undo, X);
}

void displayStack(Stack s) {
    printf("%s\n", InfoTop(s).command.TabWord);
    printInventoryDelivery(InfoTop(s).D);
    printInventoryExpired(InfoTop(s).I);
    TulisTIME1(InfoTop(s).T);
    printf("\n");
    TulisPOINT(InfoTop(s).l);
    printf("\n");
}
