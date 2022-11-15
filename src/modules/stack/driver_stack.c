#include <stdio.h>
#include "stack.c"
#include "../time/time.c"
#include "../point/point.c"
#include "../prioqueue/prioqueue.c"
#include "../makanan/makanan.c"
#include "../simulator/simulator.c"
#include "../list/liststatik.c"

int main () {
    Word command;
    PrioQueue I;
    PrioQueue D;
    TIME T;
    POINT l;
    STOCK stock;
    command.Length = 4;
    command.TabWord[0] = 'F';
    command.TabWord[1] = 'R';
    command.TabWord[2] = 'Y';
    MakeEmpty(&D, 100);
    MakeEmpty(&I, 100);
    CreateTime(&T, 0, 1, 0);
    CreatePoint(&l, 0, 0);
    CreateStock(&stock);
    Stack undo;
    CreateEmpty(&undo);
    updateState(command, I, D, stock, T, l, &undo);
    printf("State Now:\n");
    printf("%s\n", command.TabWord);
    printInventoryExpired(I);
    printf("\n");
    printInventoryDelivery(I);
    printf("\n");
    TulisTIME2(T);
    printf("\n");
    TulisPOINT(l);   
}