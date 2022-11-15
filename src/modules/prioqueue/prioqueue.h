/* File : PrioQueue.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef PrioQueue_H
#define PrioQueue_H

#include "../boolean/boolean.h"
#include "../makanan/makanan.h"
#include "../time/time.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef MAKANAN infotypePrioQueue;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotypePrioQueue * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotypePrioQueue dan Q adalah PrioQueue, maka akses elemen : */
#define TimeExpired(e)      (e).Expired
#define TimeDelivery(e)     (e).Delivery
#define Info(e)             (e).Name
#define Head(Q)             (Q).HEAD
#define Tail(Q)             (Q).TAIL
#define InfoHead(Q)         (Q).T[(Q).HEAD]
#define InfoTail(Q)         (Q).T[(Q).TAIL]
#define MaxEl(Q)            (Q).MaxEl
#define Elmt(Q,i)           (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueueExpired (PrioQueue * Q, infotypePrioQueue X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void EnqueueDelivery (PrioQueue * Q, infotypePrioQueue X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    
void Dequeue (PrioQueue * Q, infotypePrioQueue * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void CopyQueue(PrioQueue Q1,PrioQueue *Q2);
/* I.S. Q1 terdefinisi */
/* F.S. Q1 ter-copy ke Q2 */

/* Operasi Tambahan */
void decreaseTimeExpired(PrioQueue *Q, int N);
/* Proses: Mengurangi expired time sebanyak N detik */


void decreaseTimeDelivery(PrioQueue *Q, int N);
/* Proses: Mengurangi expired time sebanyak N detik */

void printInventoryExpired (PrioQueue Q);
/* Proses mencetak Inventory dengan Expired Time mengurut */

void printInventoryDelivery (PrioQueue Q);
/* Proses mencetak Inventory dengan Delivery Time mengurut */

void isDeliveredQueue(PrioQueue *I, PrioQueue *D, boolean *delivered, Word *makanan);

void isExpiredQueue(PrioQueue *I, boolean *expired, Word *makanan);

void delElmt(PrioQueue *Q, int ID, infotypePrioQueue * X);
/*Proses: menghapus elemen pada Queue*/
#endif