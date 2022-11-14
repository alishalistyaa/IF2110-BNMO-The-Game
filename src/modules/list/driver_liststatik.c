#include <stdio.h>
#include <stdlib.h>
#include "liststatik.c"

int main(){
    // KAMUS
    ListStatik l;
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

    Word nm1 = 'ayam';
    Word nm2 = 'cendol';
    Word nm3 = 'tahu';

    // ALGORITMA

    CreateListStatik(&l);

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
    //Masukin makanan ke list
    insert(&l,m1);
    insert(&l,m2);
    insert(&l,m3);
    //panjang list
    printf("panjang = %i\n",lengthList(l));
    //delete makanan ke indeks tertentu
    delete(&l,&buang,1);//delete makanan di indeks 1
    //mencetak list
    cetakList(l);

}