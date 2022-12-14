/* File: makanan.h */
/* Definisi Iput / Output */

#ifndef IO_H
#define IO_H

#include "../point/point.h"
#include "../boolean/boolean.h"
#include "../makanan/makanan.h"
#include "../map/map.h"
#include "../building/building.h"
#include "../tree/tree.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../matriks/matriks.h"
#include "../resep/resep.h"

void loadMap(MAP *M, char *filename);

void configMakanan(MAP M, char *filename, ListStatik *listofMakanan);
/* Membaca file figurasi config dan membaca makanan */
/* I.S. Makanan sembarang */
/* F.S. Makanan terdefinisi dari file */

void configResep(char *filename, BukuResep *b);
/* Membaca file figurasi config dan membaca resep */
/* I.S. Resep sembarang */
/* F.S. Resep terdefinisi dari file */

void normalizeFilename(Word *x);






#endif