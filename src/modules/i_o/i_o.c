/* File: i_o.c */
/* Implementasi Input / Output */

#include <stdio.h>
#include "i_o.h"
#include "../charmachine/charmachine.c"

void configMakanan(char *filename, MAKANAN *makanan);
/* Membaca file figurasi config dan membaca makanan */
/* I.S. Makanan sembarang */
/* F.S. Makanan terdefinisi dari file */

void configMap(char *filename, MAP *peta){
    /* Membaca file figurasi config dan membaca map */
    /* I.S. Map sembarang */
    /* F.S. Map terdefinisi dari file */
    /* Prekondisi: filename pasti valid dan exist */
    // KAMUS LOKAL
    int M[2], i;
    // ALGORITMA
    ADVFile(filename);
    i = 0;
    while (currentChar != LINEMARK) {
        int value = 0;
        while (currentChar != BLANK && currentChar != LINEMARK) {
            value = value * 10 + (currentChar - 48);
            ADV();
        }
        M[i] = value;
        if (currentChar == BLANK) {
            ADV();
        }
        i++;
    }    
    
    createMatrix(M[0] + 2, M[1] + 2, &(MATRIX(*peta)));
    // creating border for matrix peta
    for (int i = 0; i < M[1] + 2; i++) {
        (*peta).m.mem[0][i] = '*';
        (*peta).m.mem[M[0] + 1][i] = '*';
    }
    for (int i = 0; i < M[0] + 2; i++) {
        (*peta).m.mem[i][0] = '*';
        (*peta).m.mem[i][M[1] + 1] = '*';
    }

    ADV(); // next after LINEMARK
    while (currentChar != FILEMARK) {
        for (int i = 1; i < M[0] + 1; i++) {
            if (currentChar == LINEMARK) {
                ADV();
            }
            for (int j = 1; j < M[1] + 1; j++) {
                if (currentChar == '#') {
                    (*peta).m.mem[i][j] = BLANK;
                    ADV();
                } else {
                    (*peta).m.mem[i][j] = currentChar;
                    ADV();
                }
            }
        }
    }
    fclose(pita);
}


// void configResep(char *filename, tree *resep);
/* Membaca file figurasi config dan membaca resep */
/* I.S. Resep sembarang */
/* F.S. Resep terdefinisi dari file */

boolean validateString();
/* Mengembalikan true jika string yang dimasukkan valid */