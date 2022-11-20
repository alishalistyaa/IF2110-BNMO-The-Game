#include <stdio.h>
#include <stdlib.h>
#include "i_o.h"
#include "../wordmachine/wordmachine.h"
#include "../makanan/makanan.h"
#include "../makanan/makanan.h"
#include "../makanan/makanan.h"
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../list/liststatik.h"
#include "../matriks/matriks.h"
#include "../tree/tree.h"
#include "../resep/resep.h"
#include "../resep/resep.h"
#include "../building/building.h"

int main(){
    BukuResep b;
    BukuResep q;
    configResep("../../config/resep.txt",&b);
    for(int i =0; i < b.nResep; i++){
        printTree(b.contents[i],2);
    }
    return 0;
}