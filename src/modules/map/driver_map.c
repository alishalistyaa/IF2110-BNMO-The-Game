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
#include "../i_o/i_o.c"
#include "../wordmachine/wordmachine.c"
#include "../tree/tree.c"
#include "../makanan/makanan.c"
#include "../list/liststatik.c"
#include "../time/time.c"


int main(){
    MAP m;
    createMap(&m);
    loadMap(&m, "peta.txt");
    printMap(m);
    printf("Simulator loc: ");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    if (isNear(m,'*')) {
        printf("Near *\n");
    }
    Word w;
    w.Length=4;
    w.TabWord[0]='E';
    w.TabWord[1]='A';
    w.TabWord[2]='S';
    w.TabWord[3]='T';
    move_map(&m, w);
    printf("\n");
    printf("MOVE EAST\n");
    printMap(m);
    printf("Simulator loc: \n");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    printf("\n");
    w.Length=5;
    w.TabWord[0]='S';
    w.TabWord[1]='O';
    w.TabWord[2]='U';
    w.TabWord[3]='T';
    w.TabWord[4]='H';
    move_map(&m, w);
    printf("MOVE SOUTH\n");
    printMap(m);
    printf("Simulator loc: \n");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    if (isNear(m, 'M')) {
        printf("Near M");
    }
    printf("\n");
    printf("\n");
    w.Length=4;
    w.TabWord[0]='W';
    w.TabWord[1]='E';
    w.TabWord[2]='S';
    w.TabWord[3]='T';
    move_map(&m, w);
    printf("MOVE WEST\n");
    printMap(m);
    printf("Simulator loc: \n");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    printf("\n");
    w.Length=5;
    w.TabWord[0]='N';
    w.TabWord[1]='O';
    w.TabWord[2]='R';
    w.TabWord[3]='T';
    w.TabWord[4]='H';
    move_map(&m, w);
    printf("MOVE NORTH\n");
    printMap(m);
    printf("Simulator loc: \n");
    TulisPOINT(m.sim.LOCATION);
    printf("\n");
    printf("\n");
    // check if building is wall
    // w.Length=5;
    // w.TabWord[0]='N';
    // w.TabWord[1]='O';
    // w.TabWord[2]='R';
    // w.TabWord[3]='T';
    // w.TabWord[4]='H';
    // move_map(&m, w);
    // printMap(m);
    // printf("Simulator loc: \n");
    // TulisPOINT(m.sim.LOCATION);
    // printf("\n");
    // w.Length=4;
    // w.TabWord[0]='W';
    // w.TabWord[1]='E';
    // w.TabWord[2]='S';
    // w.TabWord[3]='T';
    // move_map(&m, w);
    // printMap(m);
    // printf("Simulator loc: \n");
    // TulisPOINT(m.sim.LOCATION);
    // printf("\n");
    return 0;
}