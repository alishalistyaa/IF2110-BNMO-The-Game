/* File: wordmachine.c */
/* Realisasi Word Machine: Model Akuisisi Versi I */

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../simulator/simulator.h"
#include "../i_o/i_o.h"
#include "../charmachine/charmachine.c"
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
        // printf("Detected blank!");
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

    START();
    IgnoreBlanks();
    if(currentChar == LINEMARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWordBlank();
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

void CopyWordBlank(){
/* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (currentChar != BLANK && currentChar != LINEMARK) {
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

void ADVWORDBlank(){
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
        CopyWordBlank();
        IgnoreBlanks();
        // testing
    }
}

void STARTWORDBlank(){
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
        CopyWordBlank();
        IgnoreBlanks();
    }
}

int commandToInt(Word x){
    /* Mengembalikan nilai base dari currentword */
    /* Prekondisi: currentword terdefinisi dan tidak kosong */
    if(same(x, "MIX")){
        return 1;
    }
    else if(same(x, "CHOP")){
        return 2;
    }
    else if(same(x, "FRY")){
        return 3;
    }
    else if(same(x, "BOIL")){
        return 4;
    }
    else if(same(x, "BUY")){
        return 5;
    }
    else if(same(x, "MOVE")){
        return 6;
    }
    else if(same(x, "WAIT")){
        return 7;
    }
    else if(same(x, "CATALOG")){
        return 8;
    }
    else if(same(x, "INVENTORY")){
        return 9;
    }
    else if(same(x, "DELIVERY")){
        return 10;
    }
    else if(same(x, "UNDO")){
        return 11;
    }
    else if(same(x, "REDO")){
        return 12;
    }
    else if(same(x, "COOKBOOK")){
        return 13;
    }
    else if(same(x, "EXIT")){
        return 14;
    }
    return 0;
}

int transformToInt(Word x){
    /* Mengubah input currentword menjadi int */
    /* Prekondisi: currentword terdefinisi dan tidak kosong */
    int i = 0;
    int result = 0;
    while(i < x.Length){
        result = result * 10 + (x.TabWord[i] - '0');
        i++;
    }
    return result;
}

void ignoreUntilEnter(){
    /* Mengabaikan input sampai enter */
    while(currentChar != LINEMARK){
        ADV();
    }
}