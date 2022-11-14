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