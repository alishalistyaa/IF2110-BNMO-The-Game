#include <stdio.h>
#include "building.h"
#include "../point/point.c"
#include "../boolean/boolean.h"
#include "../map/map.c"

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

    return(0);
}