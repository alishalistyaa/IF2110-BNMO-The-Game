#include "notification.h"
#include "../wordmachine/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

/*********************************************/
/********************Notif********************/
/*********************************************/

Address newNode(ElTypeL N){
    /* KAMUS */
    Address P;

    /* ALGORITMA */
    P = (Address) malloc(sizeof(NodeList));
    if(P != NULL){
        INFO(P) = N;
        NEXT(P) = NULL;
    }
    return P;
}

Notif createNotif(char kasus, MAKANAN val){
    /* KAMUS */
    Notif N;
    int i;

    /* ALGORITMA */
    KASUS(N) = kasus;
    for(i=0; i<25; i++){
        ELMT_ITEM(N, i) = val.Name.TabWord[i];
    }
    return N;
}
/* Membentuk sebuah Notif dari komponen-komponennya */

/***************************************************/
/********************Linked List********************/
/***************************************************/


void createListLink(List_Link *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    FIRST(*L) = NULL;
}

boolean isEmptyListLink(List_Link L)
//mengembalikan true jika listlink kosong
{
    /* KAMUS */

    /* ALGORITMA */
    return (FIRST(L) == NULL);
}

void insertFirst(List_Link *L, char kasus, MAKANAN item)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Notif N jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. dan menampilkan "Allocation Error"*/
{
    /* KAMUS */
    Address P;
    Notif N;

    /* ALGORITMA */
    N = createNotif(kasus, item);
    P = newNode(N);
    if(P != NULL){
        NEXT(P) = FIRST(*L);
        FIRST(*L) = P;
    } else {
        printf("Alokasi Gagal\n");
    }
}

void deleteFirst(List_Link *L, ElTypeL *N)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Notif disimpan pada N */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* KAMUS */
    Address P;

    /* ALGORITMA */
    P = FIRST(*L);
    FIRST(*L) = NEXT(P);
    *N = INFO(P);
    free(P);
}

void concatDel(List_Link *L_bawah, List_Link *L_atas)
//L_bawah bakal habis masuk ke L_atas
{
    /* KAMUS */
    Address P;

    /* ALGORITMA */
    if(isEmptyListLink(*L_bawah)){
        printf("List bawah kosong\n");
    } else {
        P = FIRST(*L_bawah);
        while(NEXT(P) != NULL){
            P = NEXT(P);
        }
        NEXT(P) = FIRST(*L_atas);
        FIRST(*L_atas) = FIRST(*L_bawah);
        FIRST(*L_bawah) = NULL;
    }
}