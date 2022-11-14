/* File: driver_wordmachine.c */
/* Driver Word Machine: Model Akuisisi Versi I */
/* Melakukan test fungsi pada wordmachine.c
    I.S. : kumpulan kata yang tersusun atas huruf-huruf lowercase
    F.S. : kumpulan kata tersusun atas huruf-huruf kapital */

#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.c"
#include "wordmachine.h"



int main(){
    int i;
    STARTWORD();
    while(!endWord){
        for(i=0; i<currentWord.Length; i++){
            int valWord = currentWord.TabWord[i];
            int val = (int)((valWord - 97) % 26 + 65);
            char huruf = val;
            printf("%c", huruf);
        }
        ADVWORD();
        if(!endWord){
            printf(" ");
        }
    }
    printf(".\n");
    return 0;
}