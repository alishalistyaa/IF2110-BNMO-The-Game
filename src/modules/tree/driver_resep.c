//Implementasi resep dengan ADT tree
#include <stdio.h>
#include "tree.h"
#include "../i_o/i_o.h"



int main(){
    Tree *resep;
    configResep("../../config/resep.txt",resep);
    return 0;
}