/* File: charmachine.c */
/* Definisi Driver Mesin Karakter */

#include <stdio.h>
#include "charmachine.c"

int main(){
    ADVFILE("../../config/resep.txt");
    while(currentChar!=EOF){
        printf("%c",currentChar);
        ADV();
    }
    return(0);
}