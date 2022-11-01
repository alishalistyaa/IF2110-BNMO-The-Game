#include <stdio.h>
#include "wordmachinefile.h"

boolean endWordFile;
WordFile currentWordFile;

void IgnoreBlanksFile(){
/* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while(currentChar == BLANK){
        ADVFILE();
    }
}

void STARTWORDFILE(char dir[]){
/* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
    STARTFILE(dir);
    
    
    IgnoreBlanksFile();
    if(currentChar == MARK){
        endWordFile = true;
    }
    else{
        endWordFile = false;
        CopyWordFile();
        IgnoreBlanksFile();
    }
}

void ADVWORDFILE(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksFile();
    if (currentChar == MARK){
        endWordFile = true;
        ADVFILE();
        CopyWordFile();
    }
    else{
        endWordFile = false;
        CopyWordFile();
        IgnoreBlanksFile();
    }
}

void copyWordFile(){
    /*  Mengakuisisi kata, menyimpan dalam currentWordFile
    I.S. : CC adalah karakter pertama dari kata
    F.S. : currentWordFile berisi kata yang sudah diakuisisi;
        CC = BLANK atau CC = MARK;
        CC adalah karakter sesudah karakter terakhir yang diakuisisi. */
    int i = 0;

    while(currentChar != MARK && currentChar != BLANK){
        currentWordFile.TabWord[i] = currentChar;
        ADVFILE();
        i++;
    }
    if(i < NMax){
        currentWordFile.length = i;
        currentWordFile.TabWord[i] = '\0';
    }
    else{
        currentWordFile.length = NMax;
        currentWordFile.TabWord[NMax] = '\0';
    }
}

void lowerCaseWordFile(){
    /*  Mengubah semua huruf pada currentWordFile menjadi huruf kecil
    I.S. : currentWordFile terdefinisi
    F.S. : Semua huruf pada currentWordFile menjadi huruf kecil */
    int i = 0;
    while(currentWordFile.TabWord[i] != '\0'){
        if(currentWordFile.TabWord[i] >= 'A' && currentWordFile.TabWord[i] <= 'Z'){
            currentWordFile.TabWord[i] += 32;
        }
        i++;
    }
}

void copyIntegerFromWordFile(int *x, WordFile w){
    /*  Mengakuisisi integer dari currentWordFile
    I.S. : currentWordFile terdefinisi
    F.S. : x berisi integer yang sudah diakuisisi */
    *x = 0;
    for(int i = 0; i < w.length; i++){
        *x = *x * 10 + (w.TabWord[i] - '0');
    }
}