/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 50
#define BLANK ' '
#define CAPACITYWORDLIST 50

/* *** Definisi TYPE WORD *** */
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* *** Definisi LIST WORD *** */
typedef struct 
{
    Word buffer[NMax]; /* container penyimpan word*/
} WordList;

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

#define ELMTWORDLIST(l, i) (l).buffer[(i)]
#define LengthWord(l) (l).Length


void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void CopyWordBlank();
/* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void LowerCase();
    /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
    /* F.S. currentword menjadi lowercase di setiap karakternya */

// void CreateMarkWord();

void ADVWORDBlank();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */

void STARTWORDBlank();
/* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
            
int commandToInt(Word x);
    /* Mengembalikan nilai base dari currentword */
    /* Prekondisi: currentword terdefinisi dan tidak kosong */

int transformToInt(Word x);
    /* Mengubah input currentword menjadi int */
    /* Prekondisi: currentword terdefinisi dan tidak kosong */

void ignoreUntilEnter();
      /* Mengabaikan semua input sampai enter */
    
int stringlen(char *s);
/* Mengembalikan panjang string */
      
boolean same(Word one, char *s);
/* Mengembalikan true jika kedua string sama */


// void CreateWordList(WordList *l);

// int lengthWordList (WordList l);

#endif
