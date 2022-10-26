/* File: charmachine.c */
/* Definisi Driver Mesin Karakter */

#include <stdio.h>
#include "charmachine.h"

int main(){
    /* Memulai Mesin Karakter */
    START();
    while ((currentChar != ' ') && (currentChar != MARK)){
        ADV();
    }

    /* Pengecekan Mesin Karakter */
    if ((currentChar != ' ') && (currentChar != MARK)){
        printf("MESIN KATA SELESAI.");
    } else {
        printf("%c", currentChar);
        ADV();
    }

    return(0);
    
}