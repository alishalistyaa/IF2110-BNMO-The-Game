#ifndef QUEUE_H
#define QUEUE_H


#define Nil -1
#include"../time/time.h"
#include"../boolean/boolean.h"
#include"../makanan/makanan.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    MAKANAN * T;
    int HEAD;
    int TAIL;
    int MAXEL;
} queue;
/* AKSES SELEKTOR */
#define D(e) (e).DD
#define H(e) (e).HH
#define M(e) (e).MM
#define IDXHEAD(q) (q).HEAD
#define IDXTAIL(q) (q).TAIL
#define INFOHEAD(q) (q).T[(q).HEAD]
#define INFOTAIL(q) (q).T[(q).TAIL]
#define MAXEL(q) (q).MAXEL
#define ELMT(q,i) (q).T[(i)]
#define Buffer(q) (q).T

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
void EnqueuePrio(queue *Q,MAKANAN time);
/*Menambah T ke dalam Q dengan aturan priority queue,terurut membesar berdasarkan waktu*/
void Enqueue(queue *Q,MAKANAN time);
/*Menambah T ke dalam Q secara sederhana*/
void Dequeue(queue *Q,MAKANAN *time);
/*Menghapus M pada Q*/
void Display(queue Q);
/*Menampilkan isi dari queue*/
#endif