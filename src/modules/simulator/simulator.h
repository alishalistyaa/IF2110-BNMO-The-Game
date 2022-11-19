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
#include "../time/time.h"
#include "../notification/notification.h"

/***** Definisi TYPE LOKASI *****/
typedef struct{
    char NAME[100]; /* Nama User */
    POINT LOCATION; /* Koordinat Lokasi pada Map */
    PrioQueue INVENTORY; /* Inventory */
    TIME TIME; /* Waktu */
    List_Link NOTIFICATION;
} SIMULATOR;

/* NOTASI AKSES: Selektor SIMULATOR */
#define Name(S) (S).NAME
#define Location(S) (S).LOCATION
#define Inventory(S) (S).INVENTORY
#define Time2(S) (S).TIME
#define Notification(S) (S).NOTIFICATION

/* ** DEFINISI PROTOTIPE PRIMITIF ** */
/* ** Konstruktor PEMBENTUK SIMULATOR ***/
void CreateSimulator(SIMULATOR * S, char X[], POINT P, PrioQueue I, TIME T);
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

void setTime(SIMULATOR * S, TIME T);
/*  I.S. : sembarang
    F.S. : meng-set currentTime pada SIMULATOR */

void passTime (SIMULATOR *S, long plus, TIME *T);

void printNotif(Notif N);
/*  I.S. : sembarang
    F.S. : mencetak notifikasi */

void printAllNotif(List_Link *L);
/*  I.S. : sembarang
    F.S. : mencetak semua notifikasi */

#endif