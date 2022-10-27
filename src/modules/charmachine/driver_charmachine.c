/* File: charmachine.c */
/* Definisi Driver Mesin Karakter */

#include <stdio.h>
#include "charmachine.h"

int main(){
    // /* Memulai Mesin Karakter */
    // START();
    // while ((currentChar != ' ') || (currentChar != LINEMARK)){
    //     ADV(); }
    
    // /* Pengecekan Mesin Karakter */
    // if (currentChar == LINEMARK){
    //     printf("MESIN KATA SELESAI.");
    // } else {
    //     while((currentChar != ' ') && (currentChar != LINEMARK)){
    //         printf("%c", currentChar);
    //         ADV();
    //     } 
    // }

    // Memulai mesin Karakter dari file
    // Kamus Lokal
    char str[100];
    // do {
    printf("Masukkan filename: ");
    scanf("%s", str);
        // gets(str);
    // } while (!isFileExist(str));

    printf("%s", str);
    return(0);
}