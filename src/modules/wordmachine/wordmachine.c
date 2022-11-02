/* File: wordmachine.c */
/* Realisasi Word Machine: Model Akuisisi Versi I */

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"
#include "wordmachine.h"

/* State Mesin Word */
boolean endWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while(currentChar == BLANK){
        ADV();
        printf("Detected blank!");
    }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    
    IgnoreBlanks();
    if(currentChar == LINEMARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == LINEMARK || currentChar == FILEMARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
        IgnoreBlanks();
        // testing
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (currentChar != LINEMARK) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
    currentWord.TabWord[i] = '\0';
}

void LowerCase(){
    /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
    /* F.S. currentword menjadi lowercase di setiap karakternya */
    for(int i=0; i<currentWord.Length; i++){
        if((currentWord.TabWord[i] >=65) && (currentWord.TabWord[i] <= 90)){
            currentWord.TabWord[i] += 32;
        }
    }
}