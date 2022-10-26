/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include "../boolean/boolean.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       if (EOP)
       {
              fclose(pita);
       }
}

/* OPERATOR TAMBAHAN */
boolean isFileExist(const char *filename){
       /* Mengembalikan true apabila File yang dituju ada dan tidak kosong.*/
       /* C tidak support exception handling, jadi alternatifnya pake ini. */
       // Kamus Lokal
       FILE *fp;
       // Algoritma
       fp = fopen(filename, "r");
       return(fp != NULL);
}

void ADVFile(const char *filename){
       /* ADV() tetapi menerima input dari file */
       pita = fopen(filename, "r");
       ADV();
}
