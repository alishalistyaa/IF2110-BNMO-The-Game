/* File: wordmachinefike.h */
/* Definisi Word Machine File: Model Akuisisi Versi I */

#ifndef __MESINKATAFILE_H__
#define __MESINKATAFILE_H__

#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 50
#define BLANK ' '

typedef struct 
{
    char TabWord[NMax]; /* Penyimpan kata, idx = [0..NMax-1] */   
    int length; /* Panjang kata yang disimpan */
} WordFile;

/* State Mesin Kata */
extern boolean endWordFile;
extern WordFile currentWordFile;

void IgnoreBlankFile();
/* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC ≠ BLANK atau CC = MARK */

void STARTWORDFILE(char dir[]);
/*  I.S. : CC sembarang
    F.S. : EndWordFile = true, dan CC = MARK;
        atau EndWordFile = false, currentWordFile adalah kata yang sudah diakuisisi,
        CC karakter pertama sesudah karakter terakhir kata */   

void ADVWORDFILE();
/*  I.S. : CC adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWordFile adalah kata terakhir yang sudah diakuisisi,
        CC adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika CC = MARK, EndWordFile = true. */

void CopyWordFile();
/*  Mengakuisisi kata, menyimpan dalam currentWordFile
    I.S. : CC adalah karakter pertama dari kata
    F.S. : currentWordFile berisi kata yang sudah diakuisisi;
        CC = BLANK atau CC = MARK;
        CC adalah karakter sesudah karakter terakhir yang diakuisisi. */

void LowerCaseWordFile();
/*  Mengubah kata menjadi huruf kecil
    I.S. : currentWordFile terdefinisi
    F.S. : currentWordFile berisi kata yang sudah diubah menjadi huruf kecil */

void copyIntegerFromWordFile(int *x, WordFile w);
/*  Mengakuisisi integer dari currentWordFile
    I.S. : currentWordFile berisi integer
    F.S. : x berisi integer yang sudah diakuisisi */

#endif