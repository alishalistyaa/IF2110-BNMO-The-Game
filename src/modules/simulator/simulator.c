/* File: simulator.c */
/* Realisasi Simulator*/

#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void CreateSimulator(SIMULATOR * S, char X[], POINT P, PrioQueue I, TIME T){
/*  I.S. : sembarang
    F.S. : membentuk simulator yang tersusun atas
           currentUsername, currentlocation, and currentInventort */
    copySimulatorName(X, Name(*S));
    Location(*S) = P; 
    Inventory(*S) = I;
    Time2(*S) = T;
    createListLink(&Notification(*S));
}

/** Primitif SIMULATOR **/
void copySimulatorName(char input[], char output[]){
/*  I.S. : sembarang
    F.S. : melakukan traversal untuk mengcopy simulator */
    for(int i=0; i<100; i++){
        if(input[i] != '\n'){
            output[i] = input[i];
        }
    }
}

POINT getLocation(SIMULATOR S){
/*  I.S. : sembarang
    F.S. : mendapatkan currentLocation dari SIMULATOR */
    return (Location(S));
}

PrioQueue getInventory(SIMULATOR S){
/*  I.S. : sembarang
    F.S. : mendapatkan currentInventory dari SIMULATOR */
    return (Inventory(S));
}

void setLocation(SIMULATOR * S, POINT P){
/*  I.S. : sembarang
    F.S. : meng-set currentLocation pada SIMULATOR */
    Location(*S) = P;
}

void setInventory(SIMULATOR * S, PrioQueue I){
/*  I.S. : sembarang
    F.S. : meng-set currentInventory pada SIMULATOR */
    Inventory(*S) = I;
}

void setTime(SIMULATOR * S, TIME T){
/*  I.S. : sembarang
    F.S. : meng-set currentTime pada SIMULATOR */
    Time2(*S) = T;
}

void passTime (SIMULATOR *S, long plus, TIME *T){  
/* I.S. : S terdefinisi, T terdefinisi, plus terdefinisi */
/* F.S. : T bertambah sebanyak plus menit */
    long minutes;
    minutes = TIMEToMenit(*T);
    minutes += plus;
    *T = MenitToTime(minutes);
    Time2(*S) = *T;
    }

void printNotification(Notif N){
/*  I.S. : sembarang
    F.S. : mencetak notifikasi */

    /* ALGORITMA */
    if(KASUS(N) == 'd'){
        printf("%s sudah berhasil diterima!\n", ITEM(N));
    }else if(KASUS(N) == 'e'){
        printf("%s kadaluwarsa!\n", ITEM(N));
    }else if(KASUS(N) == '1'){
        printf("Anda telah membatalkan pencampuran %s!\n", ITEM(N));
    }else if(KASUS(N) == '2'){
        printf("Anda telah membatalkan pemotongan %s!\n", ITEM(N));
    }else if(KASUS(N) == '3'){
        printf("Anda telah membatalkan penggorengan %s!\n", ITEM(N));
    }else if(KASUS(N) == '4'){
        printf("Anda telah membatalkan perebusan %s!\n", ITEM(N));
    }else if(KASUS(N) == '5'){
        printf("Anda telah membatalkan pembelian %s!\n", ITEM(N));
    }else if(KASUS(N) == '6'){
        printf("%s tidak jadi di-delivery!\n", ITEM(N));
    }else if(KASUS(N) == '7'){
        printf("%s tidak jadi kadaluwarsa!\n", ITEM(N));
    }else if(KASUS(N) == 'p'){
        printf("%s kembali dicampurkan\n", ITEM(N));
    }else if(KASUS(N) == 'o'){
        printf("%s kembali dipotong\n", ITEM(N));
    }else if(KASUS(N) == 'i'){
        printf("%s kembali digoreng\n", ITEM(N));
    }else if(KASUS(N) == 'u'){
        printf("%s kembali direbus\n", ITEM(N));
    }else if(KASUS(N) == 'y'){
        printf("%s kembali dibeli\n", ITEM(N));
    }else if(KASUS(N) == 't'){
        printf("%s kembali di-delivery\n", ITEM(N));
    }else if(KASUS(N) == 'r'){
        printf("%s kembali tidak kadaluwarsa\n", ITEM(N));
    }
}

void printAllNotif(List_Link *L)
/*  I.S. : sembarang
    F.S. : mencetak semua notifikasi */
{
    /* KAMUS */
    Notif N;
    int i=1;

    /* ALGORITMA */
    printf("Notifikasi:\n");
    if (isEmptyListLink(*L)){
        printf("Tidak ada notifikasi\n");
    }else{
        while(!isEmptyListLink(*L)){
            deleteFirst(L, &N);
            printf("%d. ", i);
            printNotification(N);
            i++;
        }
    }
}