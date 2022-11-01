/* File: driver_simulator.c */
/* Driver Simulator*/
/* Melakukan test fungsi pada simulator.c
    I.S. : sembarang
    F.S. : melakukan getter dan setter pada sebuah simulator S */

#include <stdio.h>
#include <stdlib.h>
#include "../point/point.h"
#include "simulator.c"

int main(){
    SIMULATOR S;
    POINT P;
    POINT P1;
    char * name;
    char * name1;
    PrioQueue I;
    PrioQueue I1;
    name = "Coba";
    name1 = "Coba1";
    CreatePoint(&P, 1, 1);
    CreatePoint(&P1, 2, 2);
    CreatePrioQueue(&I);
    CreatePrioQueue(&I1);
    CreateSimulator(&S, name, P, I);
    printf("<%d,%d>", getLocation(S).X, getLocation(S).Y);
    printf("%s", getInventory(S));
    setLocation(&S, P1);
    setInventory(&S, I1);
    printf("<%d,%d>", getLocation(S).X, getLocation(S).Y);
    printf("%s", getInventory(S));
    return 0;   
}