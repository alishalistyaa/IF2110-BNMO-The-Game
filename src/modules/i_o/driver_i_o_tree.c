#include <stdio.h>
#include <stdlib.h>
#include "i_o.c"
#include "../wordmachine/wordmachine.c"
#include "../makanan/makanan.c"
#include "../makanan/makanan.h"
#include "../makanan/makanan.h"
#include "../boolean/boolean.h"
#include "../point/point.c"
#include "../time/time.c"
#include "../list/liststatik.c"
#include "../matriks/matriks.c"
#include "../tree/tree.c"
#include "../resep/resep.c"
#include "../resep/resep.h"
#include "../building/building.c"

int main(){
    BukuResep b;
    BukuResep q;
    configResep("../../config/resep.txt",&b);
    for(int i =0; i < b.nResep; i++){
        printTree(b.contents[i],2);
    }
    return 0;
}