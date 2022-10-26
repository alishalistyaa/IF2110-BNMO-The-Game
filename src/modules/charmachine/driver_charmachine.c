/* File: charmachine.c */
/* Definisi Driver Mesin Karakter */

#include <stdio.h>
#include "charmachine.h"

int main(){
    /* Memulai Mesin Karakter */
    START();
    while ((currentChar != ' ') || (currentChar != LINEMARK)){
        ADV(); }
    
    /* Pengecekan Mesin Karakter */
    if (currentChar == LINEMARK){
        printf("MESIN KATA SELESAI.");
    } else {
        while((currentChar != ' ') && (currentChar != LINEMARK)){
            printf("%c", currentChar);
            ADV();
        } 
    }
    return(0);
    
}