/* File: makanan.h */
/* Definisi Iput / Output */

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "../point/point.h"
#include "../boolean/boolean.h"
#include "../makanan/makanan.h"
#include "../map/map.h"
#include "../tree/tree.h"
#include "../charmachine/charmachine.h"

void configMakanan(char *filename, MAKANAN *makanan);
/* Membaca file figurasi config dan membaca makanan */
/* I.S. Makanan sembarang */
/* F.S. Makanan terdefinisi dari file */

void configMap(char *filename, MAP *peta);
/* Membaca file figurasi config dan membaca map */
/* I.S. Map sembarang */
/* F.S. Map terdefinisi dari file */

// void configResep(char *filename, tree *resep);
/* Membaca file figurasi config dan membaca resep */
/* I.S. Resep sembarang */
/* F.S. Resep terdefinisi dari file */

boolean validateString();
/* Mengembalikan true jika string yang dimasukkan valid */





#endif