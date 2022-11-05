#include <stdio.h>
#include "stack.c"
#include "../time/time.c"
#include "../point/point.c"

int main () {
    Stack undo, redo;
    CreateEmpty(&undo);
    CreateEmpty(&redo);

    // Creating infotype
    Word s;
    s.TabWord[0] = 'B';
    s.TabWord[1] = 'U';
    s.TabWord[2] = 'Y';
    TIME t;
    CreateTime(&t, 0, 1, 23);
    POINT loc;
    Absis(loc) = 0;
    Ordinat(loc) = 0;
    MAKANAN m;
    ID(m) = 1;
    NAME(m) = "Ayam";
    EXPIRED(m) = t;
    ACTION(m) = loc;
    TIME delivery;
    CreateTime(&delivery, 0, 2, 0);
    DELIVERY(m) = delivery;

    updateState(s, m, t, loc, &undo);
    printf("State now:\n");
    TulisTIME1(InfoTop(undo).T);
    printf(" ");
    printf("%s ", InfoTop(undo).command.TabWord);
    printf("%s ", InfoTop(undo).M.Name);
    TulisPOINT(InfoTop(undo).l);
    printf("\n");
    printf("\n");

    // After receiving another input, update state again
    NextMenit(&t);
    s.TabWord[0] = 'F';
    s.TabWord[1] = 'R';
    s.TabWord[2] = 'Y';
    Day(delivery) = 0;
    Hour(delivery) = 3;
    Minute(delivery) = 0;
    loc = NextX(loc);

    updateState(s, m, t, loc, &undo);
    printf("State now: (after another input)\n");
    TulisTIME1(InfoTop(undo).T);
    printf(" ");
    printf("%s ", InfoTop(undo).command.TabWord);
    printf("%s ", InfoTop(undo).M.Name);
    TulisPOINT(InfoTop(undo).l);
    printf("\n");
    printf("\n");

    Undo(&undo, &redo, &s, &m, &t, &loc);
    printf("After undo:\n");
    TulisTIME1(InfoTop(undo).T);
    printf(" ");
    printf("%s ", InfoTop(undo).command.TabWord);
    printf("%s ", InfoTop(undo).M.Name);
    TulisPOINT(InfoTop(undo).l);
    printf("\n");
    printf("\n");

    Redo(&undo, &redo, &s, &m, &t, &loc);
    printf("After redo:\n");
    TulisTIME1(InfoTop(undo).T);
    printf(" ");
    printf("%s ", InfoTop(undo).command.TabWord);
    printf("%s ", InfoTop(undo).M.Name);
    TulisPOINT(InfoTop(undo).l);
    printf("\n");
    printf("\n");
}