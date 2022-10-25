#ifndef queue_H
#define queue_H


#define Nil -1
#include"../makanan/makanan.h"
#include"../boolean/boolean.h"
#include<stdio.h>

typedef struct
{
    MAKANAN * M;
    int HEAD;
    int TAIL;
    int MAXEL;
} queue;
/* AKSES SELEKTOR */
#define Kedaluarsa(e) (e).Kedaluarsa
#define Nama(e) (e).Nama
#define IDXHEAD(q) (q).HEAD
#define IDXTAIL(q) (q).TAIL
#define HEAD(q) (q).M[(q).HEAD]
#define TAIL(q) (q).M[(q).TAIL]
#define MAXEL(q) (q).MAXEL
#define ELMT(q,i) (q).M[(i)]

boolean isEmpty(queue Q);
/*Mengirim true jika queue kosong*/
boolean isFull(queue Q);
/*Mengirimkan true jika queue penuh*/
/*Mengandung elemen sebanyak MAXEL*/
int NBELMT (queue Q);
/*Mengirimkan banyak elemen pada queue*/
void MakeEmpty(queue * Q,int Max);
/*Membuat queue kosong dengan tabel memori berukuran Max+1*/
void Dealokasi(queue *Q);
/*Q pernah dialokasi,dan Q menjadi tidak terdefinisi (Q).MAXEL = 0*/
void Enqueue(queue *Q,MAKANAN M);
/*Menambah M ke dalam Q dengan aturan priority queue,terurut membesar berdasarkan kedaluarsa*/
void Dequeue(queue *Q,MAKANAN *M);
/*Menghapus M pada Q*/
#endif