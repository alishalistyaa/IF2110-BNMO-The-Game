#include "point.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    POINT p;

    CreatePoint(&p,1,1);
    Putar(&p,180);
    TulisPOINT(p);

    return 0;
}