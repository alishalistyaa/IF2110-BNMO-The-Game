/* File: simulator.h */
/* Definisi Simulator*/

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../matriks/matriks.h"
#include "../list/liststatik.h"
#include "../makanan/makanan.h"
#include "../wordmachine/wordmachine.h"
#include "../map/map.h"

/***** Definisi TYPE LOKASI *****/
typedef struct{
    char typeLoc;
    POINT coor;
} Location;

/* State Simulator */
extern Word currentName;
extern Location currentLoc;
extern MAKANAN currentFood;

/* getter Simulator */
#define getTypeLocation(l) (l).typeLoc
#define getCoordinate(l) (l).coor

void displayLoc(Location l);
/*  I.S. : currentLoc sembarang
    F.S. : Mencetak tipe lokasi serta koordinatnya */

boolean isLocationEqual(Location l1, Location l2);
/*  I.S. : l1 & l2 sembarang
    F.S. : Melakukan cek apakah l1 & l2 adalah tempat yang sama */

#endif