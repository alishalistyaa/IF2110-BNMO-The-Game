// Alt 2
#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return Head(Q) == Nil && Tail(Q) == Nil;
}

boolean IsFull (PrioQueue Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return NBElmt(Q) == MaxEl(Q); 
}

int NBElmt (PrioQueue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)) {
        return 0;
    } else {
        return Tail(Q) - Head(Q) + 1;
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotypePrioQueue *)malloc((Max+1) * sizeof(infotypePrioQueue));
    if ((*Q).T == NULL) {
        MaxEl(*Q) = 0;
    } else {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void EnqueueExpired (PrioQueue * Q, infotypePrioQueue X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* Melakukan penggeseran elemen ketika Tail(Q) = MaxEl(Q) - 1*/
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
    int idx;
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        if (Tail(*Q) == MaxEl(*Q) - 1) { //penggeseran elemen
            for (int i = Head(*Q); i <= Tail(*Q); i++) {
                (*Q).T[i-Head(*Q)] = (*Q).T[i];
            }
            Tail(*Q) -= Head(*Q);
            Head(*Q) = 0;
        }
        Tail(*Q)++;
        InfoTail(*Q) = X;
        int count = Tail(*Q);
        while (count > Head(*Q) && TIMEToMenit(TimeExpired(Elmt((*Q), count))) < TIMEToMenit(TimeExpired(Elmt((*Q), count - 1)))) {
            infotypePrioQueue temp = Elmt((*Q), count - 1);
            Elmt(*Q, count - 1) = Elmt((*Q), count);
            Elmt((*Q), count) = temp;
            count--;
        }
    }
}

void EnqueueDelivery (PrioQueue * Q, infotypePrioQueue X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* Melakukan penggeseran elemen ketika Tail(Q) = MaxEl(Q) - 1*/
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
    int idx;
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        if (Tail(*Q) == MaxEl(*Q) - 1) { //penggeseran elemen
            for (int i = Head(*Q); i <= Tail(*Q); i++) {
                (*Q).T[i-Head(*Q)] = (*Q).T[i];
            }
            Tail(*Q) -= Head(*Q);
            Head(*Q) = 0;
        }
        Tail(*Q)++;
        InfoTail(*Q) = X;
        int count = Tail(*Q);
        while (count > Head(*Q) && TIMEToMenit(TimeDelivery(Elmt((*Q), count))) < TIMEToMenit(TimeDelivery(Elmt((*Q), count - 1)))) {
            infotypePrioQueue temp = Elmt((*Q), count - 1);
            Elmt(*Q, count - 1) = Elmt((*Q), count);
            Elmt((*Q), count) = temp;
            count--;
        }
    }
}

void Dequeue (PrioQueue * Q, infotypePrioQueue * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
    }
}

void CopyQueue(PrioQueue Q1,PrioQueue *Q2)
{   MakeEmpty(Q2,MaxEl(Q1));
    for (int i = Head(Q1); i <= Tail(Q1); i++) {
        Elmt(*Q2, i) = Elmt(Q1,i);   
    }
}

void decreaseTimeExpired(PrioQueue *Q, int N) {
    for (int i = Head(*Q); i <= Tail(*Q); i++) {
        PrevNMenit(&TimeExpired(Elmt(*Q, i)),N);
    }
}

void decreaseTimeDelivery(PrioQueue *Q, int N) {
    for (int i = Head(*Q); i <= Tail(*Q); i++) {
        
        PrevNMenit(&TimeDelivery(Elmt(*Q, i)),N);
    }
}

void printInventoryExpired (PrioQueue Q) {
    if (IsEmpty(Q)) {
        printf("Tidak terdapat bahan makanan apapun di inventory\n");
    } else if (Tail(Q) == Head(Q)) {
        printf("List Makanan di Inventory\n");
        printf("(nama - waktu sisa kedaluwarsa)\n");
        printf("\t1. ");
        printf("%s", NAME(InfoHead(Q)).TabWord); // nama makanan 
        printf(" - ");
        TulisTIME2(TimeExpired(InfoHead(Q))); // waktu expired
        printf("\n");
    } else {        
        printf("List Makanan di Inventory\n");
        printf("(nama - waktu sisa kedaluwarsa)\n");
        int count = 1;
        for (int i = Head(Q); i <= Tail(Q); i++) {
            printf("\t%d.", count);
            printf("%s", NAME(Elmt(Q, i)).TabWord); // nama makanan
            printf(" - ");
            TulisTIME2(TimeExpired(Elmt(Q, i))); // waktu expired
            printf("\n");
            count++;
        }
    }
}

void printInventoryDelivery (PrioQueue Q) {
    if (IsEmpty(Q)) {
        printf("Tidak terdapat bahan makanan yang sedang diantar!\n");
    } else if (Tail(Q) == Head(Q)) {
        printf("List Makanan di Perjalanan\n");
        printf("(nama - waktu sisa delivery)\n");
        printf("\t1. ");
        printf("%s", NAME(InfoHead(Q)).TabWord); // nama makanan 
        printf(" - ");
        TulisTIME2(TimeDelivery(InfoHead(Q))); // waktu expired
        printf("\n");
    } else {        
        printf("List Makanan di Perjalanan\n");
        printf("(nama - waktu sisa delivery)\n");
        int count = 1;
        for (int i = Head(Q); i <= Tail(Q); i++) {
            printf("\t%d.", count);
            printf("%s", NAME(Elmt(Q, i)).TabWord); // nama makanan
            printf(" - ");
            TulisTIME2(TimeDelivery(Elmt(Q, i))); // waktu expired
            printf("\n");
            count++;
        }
    }
}

// * DIPINDAH KE MAP YAAAAAAAAAAA!

// void isDeliveredQueue(PrioQueue *I, PrioQueue *D, boolean *delivered, Word *makanan){
//     infotypePrioQueue val;
//     if (!IsEmpty(*D)){
//         for (int i = Head(*D); i <= Tail(*D); i++) {
//             if(isDelivered(Elmt(*D, i))){
//                 Dequeue(D, &val);
//                 EnqueueExpired(I, val);
//                 *delivered = true;
//             }
//         }
//     }
//     *makanan = NAME(val); 
// }

// void isExpiredQueue(PrioQueue *I, boolean *expired, Word *makanan){
//     infotypePrioQueue val;
//     if (!IsEmpty(*I)){
//         for (int i = Head(*I); i <= Tail(*I); i++) {
//             if(isExpired(Elmt(*I, i))){
//                 Dequeue(I, &val);
//                 *expired = true;
//             }
//         }
//     }
//     *makanan = NAME(val);
// }

void delElmt(PrioQueue *Q, int id, infotypePrioQueue * X) {
    int delIdx = -1;
    for (int i = Head(*Q); i <= Tail(*Q); i++) {
        if (id == ID(Elmt(*Q,i))){
            delIdx = i;
            *X = Elmt(*Q,i);
            break;
        }
    }

    while (delIdx <  Tail(*Q))
    {
        Elmt(*Q,delIdx) = Elmt(*Q,delIdx+1);
        delIdx++;
    }
    Tail(*Q)--;
    
}