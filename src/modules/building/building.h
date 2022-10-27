#ifndef BUILDING_H
#define BUILDING_H

#include <stdio.h>
#include "../point/point.h"
#include "../boolean/boolean.h"

typedef struct {
    POINT coordinate;
    char name;
} BUILDING;

/* *** Notasi Akses: Selektor Building *** */
#define XCOORD(B) Absis((B).coordinate)
#define YCOORD(B) Ordinat((B).coordinate)
#define COORD(B) (B).coordinate
#define TYPE(B) B.name

/* *** PROTOTYPE PRIMITIF  *** */
void CreateBuilding(BUILDING *B, POINT p, char name);
/* Membentuk sebuah BUILDING dari komponen-komponennya yang valid */

boolean isBuilding(BUILDING B1, BUILDING B2);
/* Mengembalikan true jika type building sama */

boolean isBuildingExist(BUILDING B);
/* Mengembalikan true jika building exist */

#endif