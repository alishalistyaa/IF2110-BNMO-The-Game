#include <stdio.h>
#include "building.c"
#include "../point/point.c"
#include "../boolean/boolean.h"
#include "../wordmachine/wordmachine.c"
#include "../charmachine/charmachine.c"
#include "../map/map.c"
#include "../time/time.c"
#include "../list/liststatik.c"
#include "../matriks/matriks.c"

int main(){
    // KAMUS LOKAL
    BUILDING B1, B2;
    POINT P1, P2;
    char name1, name2;

    // ALGORITMA
    CreatePoint(&P1, 5, 5);
    CreatePoint(&P2, 10, 2);
    name1 = 'x';
    name1 = 'y';
    // Create Building
    CreateBuilding(&B1, P1, name1);
    CreateBuilding(&B2, P2, name2);
    
    if (isBuildingSame(B1, B2)){
        printf("Building satu dan dua sama\n");
    } else { printf("Building tidak sama.\n");}

    if(isBuildingExist('x', MAP M)){
        printf("Building x exist.\n");
    }

    return(0);
}