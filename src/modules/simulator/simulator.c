/* File: simulator.c */
/* Realisasi Simulator*/

#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void displayLoc(Location l){
/*  I.S. : currentLoc sembarang
    F.S. : Mencetak tipe lokasi serta koordinatnya */
    printf("%c ", getTypeLocation(l));
    TulisPOINT(getCoordinate(l));
    printf("\n");
}

boolean isLocationEqual(Location l1, Location l2){
/*  I.S. : l1 & l2 sembarang
    F.S. : Melakukan cek apakah l1 & l2 adalah tempat yang sama */
    return EQ(l1.coor,l2.coor) && (l1.typeLoc == l2.typeLoc);
}