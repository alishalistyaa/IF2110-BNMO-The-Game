/* File: simulator.c */
/* Realisasi Simulator*/

#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void CreateSimulator(SIMULATOR * S, char X[], POINT P, PrioQueue I){
/*  I.S. : sembarang
    F.S. : membentuk simulator yang tersusun atas
           currentUsername, currentlocation, and currentInventort */
    Location(*S) = P;
    Name(*S) = X; 
    PrioQueue(*S) = Q;
}

/** Primitif SIMULATOR **/
char * getName(SIMULATOR S){
/*  I.S. : sembarang
    F.S. : mendapatkan currentName dari SIMULATOR */
    return (Name(S));
}

POINT getLocation(SIMULATOR S){
/*  I.S. : sembarang
    F.S. : mendapatkan currentLocation dari SIMULATOR */
    return (Locatiion(S));
}

PrioQueue getInventory(SIMULATOR S){
/*  I.S. : sembarang
    F.S. : mendapatkan currentInventory dari SIMULATOR */
    return (Inventory(S));
}

void setName(SIMULATOR * S, char X[]){
/*  I.S. : sembarang
    F.S. : meng-set currentName pada SIMULATOR */
    Name(*S) = X;
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