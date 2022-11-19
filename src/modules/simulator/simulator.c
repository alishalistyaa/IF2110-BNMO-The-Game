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

void printNotification(Notif N, boolean isUndo){
/*  I.S. : sembarang
    F.S. : mencetak notifikasi */

    /* ALGORITMA */
    if(same(KASUS(N),"DELIVERY") && (isUndo)){
        printf("%s tidak jadi di-delivery!\n", ITEM(N));
    }else if(same(KASUS(N),"EXPIRED") && (isUndo)){
        printf("%s tidak jadi kadaluwarsa!\n", ITEM(N));
        // UNDO
    }else if(same(KASUS(N),"MIX") && (isUndo)){
        printf("Anda telah membatalkan pencampuran %s!\n", ITEM(N));
    }else if(same(KASUS(N),"CHOP") && (isUndo)){
        printf("Anda telah membatalkan pemotongan %s!\n", ITEM(N));
    }else if(same(KASUS(N),"FRY") && (isUndo)){
        printf("Anda telah membatalkan penggorengan %s!\n", ITEM(N));
    }else if(same(KASUS(N),"BOIL") && (isUndo)){
        printf("Anda telah membatalkan perebusan %s!\n", ITEM(N));
    }else if(same(KASUS(N),"BUY") && (isUndo)){
        printf("Anda telah membatalkan pembelian %s!\n", ITEM(N));
    }else if(same(KASUS(N),"MIX")){
        printf("%s kembali dicampurkan\n", ITEM(N));
    }else if(same(KASUS(N), "CHOP")){
        printf("%s kembali dipotong\n", ITEM(N));
    }else if(same(KASUS(N), "FRY")){
        printf("%s kembali digoreng\n", ITEM(N));
    }else if(same(KASUS(N), "BOIL")){
        printf("%s kembali direbus\n", ITEM(N));
    }else if(same(KASUS(N), "BUY")){
        printf("%s kembali dibeli\n", ITEM(N));
    }else if(same(KASUS(N),"DELIVERY")){
        printf("%s sudah berhasil diterima!\n", ITEM(N));
    }else if(same(KASUS(N),"EXPIRED")){
        printf("%s kadaluwarsa!\n", ITEM(N));
    }else if(same(KASUS(N), "DELIVERY")){
        printf("%s kembali di-delivery\n", ITEM(N));
    }else if(same(KASUS(N), "EXPIRED")){
        printf("%s kembali tidak kadaluwarsa\n", ITEM(N));
    }
}

void printAllNotif(List_Link *L, boolean *isUndo)
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
            printNotification(N, *isUndo);
            i++;
        }
    }
    *isUndo = false;
}