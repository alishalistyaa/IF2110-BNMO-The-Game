#include <stdio.h>
#include "i_o.h"
#include "../wordmachine/wordmachine.h"
#include "../makanan/makanan.h"
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../list/liststatik.h"
#include "../matriks/matriks.h"
#include "../map/map.h"
#include "../building/building.h"
#include "../tree/tree.h"


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
