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
        printf("%s\n", "File ada!");
        loadMap(&peta, "peta.txt");
    } else {
        printf("%d\n", 0);
    }

    printMap(peta);
    ListStatik l;
    CreateListStatik(&l);
    if (isFileExist("../../config/makanan.txt")){
        printf("%s\n", "File ada!");
        configMakanan(peta, "makanan.txt", &l);
    } else {
        printf("%d\n", 0);
    }
    cetakCatalog(l, peta);
}
