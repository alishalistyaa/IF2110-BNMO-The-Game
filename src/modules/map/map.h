#ifndef MAP_H
#define MAP_H

#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../matriks/matriks.h"
#include "../list/liststatik.h"

/* *** Definisi BATASAN MAP *** */
#define ROW_MIN 10
#define ROW_MAX 50
#define COL_MIN 10
#define COL_MAX 50

/* *** Definisi TYPE MAP *** */
typedef struct {
    int width; /* integer [10... 50] Lebar Map */
    int height;/* integer [10... 50] Panjang Map */
    ListStatik Lokasi; 
    ListStatik ListBuilding;
} MAP;

/* *** Notasi Akses: selektor MAP *** */


#endif