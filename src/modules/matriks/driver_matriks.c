#include "matriks.h"
#include <stdio.h>

int main () {
    Matrix M, MCopy;
    int b, k;

    printf("Masukkan baris dan kolom matrix: ");    
    scanf("%d %d", &b, &k);
    createMatrix(b, k, &M);
    readMatrix(&M, b, k);
    displayMatrix(M);
    if (isSquare(M)) {
        printf("Matriks M adalah matriks persegi\n");
    }
    printf("Banyak elemen matriks M adalah %d\n", countElmt(M));
    printf("Indeks baris terakhir: %d\n", getLastIdxRow(M));
    printf("Indeks kolom terakhir: %d\n", getLastIdxCol(M));
    copyMatrix(M, &MCopy);
    printf("Matriks copy dari M\n");
    displayMatrix(MCopy);

/* Pengecekan dengan dua matrix */
    Matrix M1, M2;
    printf("Masukkan baris dan kolom matriks: ");    
    scanf("%d %d", &b, &k);
    createMatrix(b, k, &M1);
    readMatrix(&M1, b, k);
    displayMatrix(M1);

    printf("Masukkan baris dan kolom matriks: ");    
    scanf("%d %d", &b, &k);
    createMatrix(b, k, &M2);
    readMatrix(&M2, b, k); 
    displayMatrix(M2);

    if (isMatrixEqual(M1, M2)) {
        printf("Matriks 1 sama dengan matriks 2\n");
    }
    if (isMatrixNotEqual(M1, M2)) {
        printf("Matriks 1 berbeda dengan matriks 2\n");
    }

    if (isMatrixSizeEqual(M1, M2)) {
        printf("Matriks 1 berukuran sama dengan matriks 2\n");
    }   
}