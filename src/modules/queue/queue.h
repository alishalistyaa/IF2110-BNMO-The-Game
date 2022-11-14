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
    MAKANAN * M;
    int HEAD;
    int TAIL;
    int MAXEL;
} queue;
/* AKSES SELEKTOR */
#define IDXHEAD(q) (q).HEAD
#define IDXTAIL(q) (q).TAIL
#define INFOHEAD(q) (q).M[(q).HEAD]
#define INFOTAIL(q) (q).M[(q).TAIL]
#define MAXEL(q) (q).MAXEL
#define ELMTQUEUE(q,i) (q).M[(i)]
#define Buffer(q) (q).M

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
void EnqueueInventory(queue *Q,MAKANAN food);
/*Menambah T ke dalam Q dengan aturan priority queue(Inventory),terurut membesar berdasarkan waktu*/
void EnqueueDelivery(queue *Q,MAKANAN food);
/*Menambah T ke dalam Q dengan aturan priority queue(Delivery),terurut membesar berdasarkan waktu*/
void Enqueue(queue *Q,MAKANAN food);
/*Menambah T ke dalam Q dan diletakkan di akhir Q*/
void DeleteAtInventory(queue *Q,MAKANAN food,MAKANAN *buang);
/*Membuang makanan sesuai food yang diinputkan*/
void Dequeue(queue *Q,MAKANAN *food);
/*Menghapus M pada Q*/
void Copy(queue Q,queue *copy);
/*Menyalin makanan ke inventory lain*/
void Display(queue Q);
/*Menampilkan isi dari queue*/
#endif