/* File: driver_map.c */
/* Driver Map*/
/* Melakukan test fungsi pada map.c
    I.S. : sembarang
    F.S. : melakukan print peta dengan mencoba fungsi move */

#include <stdio.h>
#include <stdlib.h>
#include "map.c"
#include "../matriks/matriks.c"
#include "../point/point.c"
#include "../building/building.c"

int main(){
    MAP m;
    createMap(&m);
    configMap(&m, "peta.txt");
    printMap(m);
    printf("Simulator loc: ");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    POINT P = getLocBuilding('B',m);
    TulisPOINT(P);
    printf("%c", ElmtMap(m, 10, 7));
    Word w;
    w.Length=4;
    w.TabWord[0]='E';
    w.TabWord[1]='A';
    w.TabWord[2]='S';
    w.TabWord[3]='T';
    move_map(&m,w);
    move_map(&m,w);
    printMap(m);
    move_map(&m,w);
    printMap(m);
    return 0;
}