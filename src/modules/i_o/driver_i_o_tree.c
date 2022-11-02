#include <stdio.h>
#include <stdlib.h>
#include "i_o.c"
#include "../wordmachine/wordmachine.c"
#include "../makanan/makanan.c"
#include "../boolean/boolean.h"
#include "../point/point.c"
#include "../time/time.c"
#include "../list/liststatik.c"
#include "../matriks/matriks.c"
#include "../tree/tree.c"

int main(){
    Tree *s;

    configResep("resep.txt",s);
    printf("\n");
    printTree(s[0],2);
    return 0;
}