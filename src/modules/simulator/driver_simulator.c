/* File: driver_simulator.c */
/* Driver Simulator*/

#include <stdio.h>
#include <stdlib.h>
#include "simulator.c"

int main(){
    Location l1;
    Location l2;
    l1.coor.X = 1;
    l1.coor.Y = 1;
    l1.typeLoc = 'M';

    l2.coor.X = 2;
    l2.coor.Y = 3;
    l2.typeLoc = 'M';
    displayLoc(l1);
    displayLoc(l2);
    if(isLocationEqual(l1,l2)){
        printf("Sama");
    }else{
        printf("Beda");
    }
}