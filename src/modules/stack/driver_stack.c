#include <stdio.h>
#include "stack.h"
#include "../time/time.h"
// #include "../point/point.h"
// #include "../prioqueue/prioqueue.h"
// #include "../makanan/makanan.h"
// #include "../simulator/simulator.h"
// #include "../list/liststatik.h"

int main () {
    Word command;
    PrioQueue I;
    PrioQueue ICopy;
    PrioQueue D;
    TIME T;
    POINT l;
    STOCK stock;
    command.Length = 3;
    command.TabWord[0] = 'F';
    command.TabWord[1] = 'R';
    command.TabWord[2] = 'Y';
    MakeEmpty(&D, 100);
    MakeEmpty(&I, 100);
    MakeEmpty(&ICopy, 100);
    CreateTime(&T, 0, 1, 0);
    CreatePoint(&l, 0, 0);
    CreateStock(&stock);
    CopyQueue(I, &ICopy);
    printInventoryExpired(ICopy);
    Stack undo;
    CreateEmpty(&undo);
    Stack redo;
    CreateEmpty(&redo);
    updateState(command, I, D, stock, T, l, &undo);
    command.Length = 3;
    command.TabWord[0] = 'B';
    command.TabWord[1] = 'U';
    command.TabWord[2] = 'Y';
    updateState(command, I, D, stock, T, l, &undo);
    displayStack(undo);
    if (IsEmptyStack(undo)) {
        printf("Tidak ada yang bisa di-undo\n");
    } else {
        Undo(&undo, &redo, &command, &I, &D, &stock, &T, &l);
        displayStack(undo);
    }
}