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
#include "../wordmachine/wordmachine.h"
#include "../matriks/matriks.h"
#include "../resep/resep.h"

<<<<<<< HEAD
void configMakanan(MAP M, char *filename, ListStatik *listofMakanan);
=======
// void configMakanan(char *filename, ListStatik *listofMakanan);
>>>>>>> c7e2daa286204bacb11dd9812f12424d48c45025
/* Membaca file figurasi config dan membaca makanan */
/* I.S. Makanan sembarang */
/* F.S. Makanan terdefinisi dari file */

 void configMap(char *filename, Matrix *m);
/* Membaca file figurasi config dan membaca map */
/* I.S. Map sembarang */
/* F.S. Map terdefinisi dari file */


void configResep(char *filename, BukuResep *b);
/* Membaca file figurasi config dan membaca resep */
/* I.S. Resep sembarang */
/* F.S. Resep terdefinisi dari file */

int stringlen(char *s);

boolean same(Word one, char *s);

boolean validateString();
/* Mengembalikan true jika string yang dimasukkan valid */

#endif