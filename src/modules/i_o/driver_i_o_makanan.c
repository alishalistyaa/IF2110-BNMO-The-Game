#include <stdio.h>
#include "i_o.c"
#include "../wordmachine/wordmachine.c"
#include "../makanan/makanan.c"
#include "../boolean/boolean.h"
#include "../point/point.c"
#include "../time/time.c"
#include "../list/liststatik.c"
#include "../matriks/matriks.c"
#include "../map/map.c"
#include "../building/building.c"
#include "../tree/tree.c"

int main(){
    MAP peta;
    if (isFileExist("peta.txt")){
        printf("%d\n", 1);
        loadMap(&peta, "peta.txt");
    } else {
        printf("%d\n", 0);
    }
    displayMatrix(MATRIX(peta));

    ListStatik l;
    CreateListStatik(&l);
    if (isFileExist("makanan.txt")){
        printf("%d\n", 1);
        configMakanan(peta, "makanan.txt", &l);
    } else {
        printf("%d\n", 0);
    }
    cetakList(l);
}