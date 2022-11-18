#ifndef SET_H
#define SET_H

#include "../boolean/boolean.h"

//#include "../simulator/simulator.h"
#define CAP 100
/* *** Definisi TYPE TIME <HH:MM:SS> *** */

typedef struct { 
	int buffer[CAP];
} SET;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM



#endif