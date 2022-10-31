/* File: i_o.c */
/* Implementasi Input / Output */

#include <stdio.h>
#include "i_o.h"
#include "../charmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../makanan/makanan.h"
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../list/liststatik.h"
#include "../matriks/matriks.h"

static FILE *pita;
static int retval;

void configMakanan(char *filename, ListStatik *listofMakanan){
    /* Membaca file figurasi config dan membaca makanan */
    /* I.S. Makanan sembarang */
    /* F.S. Makanan terdefinisi dari file */
    // KAMUS LOKAL
    int countMakanan;
    int i;
    int tempID;
    char *tempName;
    TIME tempExpired;
    char *tempActionWord;
    POINT tempActionPoint;
    TIME tempDelivery;

    // ALGORITMA
    // Membaca berapa makanan yang ada di file config
    ADVFILE(filename);
    countMakanan = 0;
    while (currentChar != LINEMARK){
            countMakanan = countMakanan * 10 + (currentChar - 48);
            ADV();    
    }
    printf("%d\n", countMakanan);

    // Membaca makanan sebanyak countMakanan
    for(i = 0; i < countMakanan; i++){
        /* BACA ID */
        tempID = 0;
        ADV(); // next after LINEMARK
        while (currentChar != LINEMARK){
            while (currentChar != BLANK && currentChar != LINEMARK) {
                tempID = tempID * 10 + (currentChar - 48);
                ADV();
            }      
    }        

        /* BACA JUDUL */
        ADVWORD(); // next after LINEMARK
            while (!endWord){
                tempName = currentWord.TabWord;
            }

        /* BACA EXPIRED */
        ADV(); // next after LINEMARK
        int LEx[3];
        int countEx = 0;
        while (currentChar != LINEMARK) {
            int value = 0;
                while (currentChar != BLANK && currentChar != LINEMARK) {
                    value = value * 10 + (currentChar - 48);
                    ADV();
                }
                LEx[countEx] = value;
                if (currentChar == BLANK) {
                    ADV();
                }
                countEx++;
        } 
        // Masukkan ke dalam time
        CreateTime(&tempExpired, LEx[0], LEx[1], LEx[2]);      

        /* BACA DELIVERY */
        ADV(); //Next after LINEMARK
        int LDeliv[3];
        int countDeliv = 0;
        while (currentChar != LINEMARK) {
            int value = 0;
                while (currentChar != BLANK && currentChar != LINEMARK) {
                    value = value * 10 + (currentChar - 48);
                    ADV();
                }
                LDeliv[countDeliv] = value;
                if (currentChar == BLANK) {
                    ADV();
                }
                countDeliv++;
        } 
        // Masukkan ke dalam time
        CreateTime(&tempDelivery, LDeliv[0], LDeliv[1], LDeliv[2]); 


        /* BACA ACTION */
        ADVWORD(); // next after LINEMARK
            while (!endWord){
                tempActionWord = currentWord.TabWord;
            }

        // Convert Action to Point
        CreatePoint(&tempActionPoint, 0, 0);

        MAKANAN M;
        CreateMakanan(&M, tempID, tempName, tempExpired, tempActionPoint, tempDelivery);
        insert(listofMakanan, M);
    }
    fclose(pita);
}


void configMap(char *filename, MAP *peta){
    /* Membaca file figurasi config dan membaca map */
    /* I.S. Map sembarang */
    /* F.S. Map terdefinisi dari file */
    /* Prekondisi: filename pasti valid dan exist */
    // KAMUS LOKAL
    int i;
    int M[2];

    // ALGORITMA
    ADVFILE(filename);
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

int stringlen(char *s) {
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}

boolean same(char *s1, char *s2) {
    if (stringlen(s1) == stringlen(s2)) {
        for (int i = 0; i < stringlen(s1); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
boolean validateString();
/* Mengembalikan true jika string yang dimasukkan valid */