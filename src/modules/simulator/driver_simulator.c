/* File: driver_simulator.c */
/* Driver Simulator*/
/* Melakukan test fungsi pada simulator.c
    I.S. : sembarang
    F.S. : melakukan getter dan setter pada sebuah simulator S */

#include <stdio.h>
#include <stdlib.h>
#include "../time/time.c"
#include "../prioqueue/prioqueue.c"
#include "../point/point.c"
#include "../makanan/makanan.c"
#include "simulator.c"

int main(){
    SIMULATOR S;
    POINT P;
    POINT P1;
    char * name;
    char * name1;
    char * namaMakanan;
    TIME T1, T2;
    CreateTime(&T1, 1, 1, 1);
    CreateTime(&T2, 2, 2, 2);
    namaMakanan = "Tahu";
    PrioQueue I;
    MAKANAN m;
    float x1=20, y1=20;
    float x2=30, y2=30;
    name = "Coba";
    name1 = "Coba1";
    CreatePoint(&P, x1, y1);
    CreatePoint(&P1, x2, y2);
    MakeEmpty(&I, 100);
    CreateSimulator(&S, name, P, I);
    printf("<%.2f,%.2f>\n", getLocation(S).X, getLocation(S).Y);
    printInventory(getInventory(S));
    setLocation(&S, P1);
    CreateMakanan(&m, 15, namaMakanan, T1, P, T2);
    Enqueue(&I, m);
    setInventory(&S, I);
    printf("<%.2f,%.2f>\n", getLocation(S).X, getLocation(S).Y);
    printInventory(getInventory(S));
    return 0;   
}