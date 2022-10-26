/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"

#define MARK '.'        // Menandakan mark string biasa
#define FILEMARK EOF    // Menandakan End of File
#define LINEMARK '\n'   // Menandakan End of Line
/* State Mesin */
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

/* OPERATOR TAMBAHAN */
boolean isFileExist();
/* Mengembalikan true apabila File yang dituju ada dan tidak kosong.*/
/* C tidak support exception handling, jadi alternatifnya pake ini. */

void ADVFile();
/* ADV() tetapi menerima input dari file */

#endif