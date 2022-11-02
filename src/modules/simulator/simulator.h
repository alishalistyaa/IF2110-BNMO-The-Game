/* File: simulator.h */
/* Definisi Simulator*/

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../matriks/matriks.h"
#include "../prioqueue/prioqueue.h"
#include "../makanan/makanan.h"
#include "../wordmachine/wordmachine.h"
#include "../map/map.h"

/***** Definisi TYPE LOKASI *****/
typedef struct{
    char NAME[100]; /* Nama User */
    POINT LOCATION; /* Koordinat Lokasi pada Map */
    PrioQueue INVENTORY; /* Inventory */
} SIMULATOR;

/* NOTASI AKSES: Selektor SIMULATOR */
#define Name(S) (S).NAME
#define Location(S) (S).LOCATION
#define Inventory(S) (S).INVENTORY

/* ** DEFINISI PROTOTIPE PRIMITIF ** */
/* ** Konstruktor PEMBENTUK SIMULATOR ***/
void CreateSimulator(SIMULATOR * S, char X[], POINT P, PrioQueue I);
/*  I.S. : sembarang
    F.S. : membentuk simulator yang tersusun atas
           currentUsername, currentlocation, and currentInventort */

/** Primitif SIMULATOR **/
void copySimulatorName(char input[], char output[]);
/*  I.S. : sembarang
    F.S. : melakukan traversal untuk mengcopy simulator */

POINT getLocation(SIMULATOR S);
/*  I.S. : sembarang
    F.S. : mendapatkan currentLocation dari SIMULATOR */

PrioQueue getInventory(SIMULATOR S);
/*  I.S. : sembarang
    F.S. : mendapatkan currentInventory dari SIMULATOR */

void setLocation(SIMULATOR * S, POINT P);
/*  I.S. : sembarang
    F.S. : meng-set currentLocation pada SIMULATOR */

void setInventory(SIMULATOR * S, PrioQueue I);
/*  I.S. : sembarang
    F.S. : meng-set currentInventory pada SIMULATOR */

#endif