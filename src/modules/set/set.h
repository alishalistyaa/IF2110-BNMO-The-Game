#ifndef SET_H
#define SET_H

#include "../boolean/boolean.h"

#define CAPACITY 100

#define MARKSTOCK -11
/*ID_Makanan set dari stock adalah -11*/
#define MARKLISTREKOMEN -111
/*ID_Makanan set dari list Rekomen adalah -111*/
#define MARKEMPTYSET -1111
/*EmptySet memiliki Mark -1111*/


typedef struct {
   int ID_Makanan;
   int ID_Bahan[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} SET;

/* *** SELEKTOR *** */
#define HEADSET(S) (S).ID_Makanan
#define ELMTSET(S,i) (S).ID_Bahan[i]

/* *** Konstruktor *** */
void createEmptySet(SET* s);

/* *** Predikat dan fungsi lain *** */
boolean isEmptySet(SET s);

boolean isSubset(SET s1, SET s2); 

SET concatSet(SET s1, SET s2);

void printSet(SET s);
#endif