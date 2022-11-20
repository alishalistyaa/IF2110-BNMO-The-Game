#include "time.h"
#include <stdio.h>

int main() {
/* Pengecekan display waktu di console */
    TIME T;
    int h, m;

    BacaTIME1(&T);
    printf("Waktu: ");
    TulisTIME1(T);
    printf("\n");

    NextMenit(&T);
    printf("Satu menit setelahnya adalah: ");
    TulisTIME1(T);
    printf("\n");

/* Pengecekan untuk command WAIT*/
    printf("Masukkan waktu wait: ");
    scanf("%d %d", &h, &m);
    NextJamMenit(&T, h, m);
    printf("T setelah menunggu %d jam dan %d menit adalah ", h, m);
    TulisTIME1(T);
    printf("\n");

/* Pengecekan TIME untuk waktu kedaluwarsa dan sisa delivery time */
    TIME T1, T2;
    printf("Masukkan waktu kedaluwarsa dalam hari jam menit: ");
    BacaTIMEDelivery(&T1); 
    printf("Masukkan waktu sisa delivery dalam hari jam menit: ");
    BacaTIMEDelivery(&T2); // Kalau delivery gak bisa hari berarti pake bacatime1

    printf("Sisa waktu kedaluwarsa setelah satu menit: ");
    PrevMenit(&T1);
    TulisTIME2(T1);
    printf("\n");
    printf("Sisa waktu delivery setelah satu menit: ");
    PrevMenit(&T2);
    TulisTIME2(T2);
    printf("\n");

    printf("Sisa waktu kedaluwarsa setelah 3 menit: ");
    PrevNMenit(&T1, 3);
    TulisTIME2(T1);
    printf("\n");
    printf("Sisa waktu delivery setelah 3 menit: ");
    PrevNMenit(&T2, 3);
    TulisTIME2(T2);
    printf("\n");

/* Pengecekan kelompok yang menggunakan dua TIME */
    if (TEQ(T1, T2)) {
        printf("Sisa waktu delivery dan kedaluwarsa sama\n");
    } else if (TNEQ(T1, T2)) {
        printf("Sisa waktu delivery dan kedaluwarsa berbeda\n");
    }

    if (TLT(T1, T2)) {
        printf("Sisa waktu kedaluwarsa lebih sedikit daripada sisa waktu delivery");
    } else if (TGT(T1, T2)) {
        printf("Sisa waktu kedaluwarsa lebih banyak daripada sisa waktu delivery");
    }
}