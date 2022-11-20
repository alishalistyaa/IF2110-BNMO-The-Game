/* File: driver_simulator.c */
/* Driver Simulator*/
/* Melakukan test fungsi pada simulator.c
    I.S. : sembarang
    F.S. : melakukan getter dan setter pada sebuah simulator S */

#include <stdio.h>
#include <stdlib.h>
// #include "../time/time.h"
// #include "../prioqueue/prioqueue.h"
// #include "../point/point.h"
// #include "../makanan/makanan.h"
#include "simulator.h"

int main(){
    SIMULATOR S;
    POINT P;
    POINT P1;
    char * name;
    char * name1;
    Word namaMakanan;
    TIME T1, T2;
    CreateTime(&T1, 1, 1, 1);
    CreateTime(&T2, 2, 2, 2);
    namaMakanan.Length = 4;
    namaMakanan.TabWord[0] = 'T';
    namaMakanan.TabWord[1] = 'a';
    namaMakanan.TabWord[2] = 'h';
    namaMakanan.TabWord[3] = 'u';
    PrioQueue I;
    MAKANAN m;
    float x1=20, y1=20;
    float x2=30, y2=30;
    name = "Coba";
    name1 = "Coba1";
    CreatePoint(&P, x1, y1);
    CreatePoint(&P1, x2, y2);
    MakeEmpty(&I, 100);
    CreateSimulator(&S, name, P, I, T1);
    printf("<%.2d,%.2d>\n", getLocation(S).X, getLocation(S).Y);
    // printInventory(getInventory(S));
    setLocation(&S, P1);
    CreateMakanan(&m, 15, namaMakanan, T1, P, T2);
    EnqueueExpired(&I, m);
    setInventory(&S, I);
    printf("<%.2d,%.2d>\n", getLocation(S).X, getLocation(S).Y);
    // printInventory(getInventory(S));
    return 0;   
}