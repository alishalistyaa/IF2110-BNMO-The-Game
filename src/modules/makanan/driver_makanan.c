#include <stdio.h>
#include "makanan.h"

int main(){
     MAKANAN m1;
    MAKANAN m2;
    MAKANAN m3;
    MAKANAN buang;

    POINT p1;
    POINT p2;
    POINT p3;

    int ID1 = 13;
    int ID2 = 23;
    int ID3 = 14;

    TIME ex1;
    TIME ex2;
    TIME ex3;

    TIME del1;
    TIME del2;
    TIME del3;
    Word nm1, nm2, nm3;

    nm1.Length = 4;
    nm1.TabWord[0] = 'a';
    nm1.TabWord[1] = 'y';
    nm1.TabWord[2] = 'a';
    nm1.TabWord[3] = 'm';

    nm2.Length = 6;
    nm2.TabWord[0] = 'c';
    nm2.TabWord[1] = 'e';
    nm2.TabWord[2] = 'n';
    nm2.TabWord[3] = 'd';
    nm2.TabWord[4] = 'o';
    nm2.TabWord[5] = 'l';

    nm3.Length = 4;
    nm3.TabWord[0] = 't';
    nm3.TabWord[1] = 'a';
    nm3.TabWord[2] = 'h';
    nm3.TabWord[3] = 'u';

    // ALGORITMA

    CreatePoint(&p1,0,0);
    CreatePoint(&p2,0,0);
    CreatePoint(&p3,0,0);

    CreateTime(&ex1,1,2,3);
    CreateTime(&ex2,2,4,5);
    CreateTime(&ex3,4,1,2);

    CreateTime(&del1,1,2,3);
    CreateTime(&del2,2,4,5);
    CreateTime(&del3,4,1,2);

    CreateMakanan(&m1,ID1,nm1,ex1,p1,del1);
    CreateMakanan(&m2,ID2,nm2,ex2,p2,del2);
    CreateMakanan(&m3,ID3,nm3,ex3,p3,del3);
    return(0);
}