#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(){
    Tree pohon1;
    Tree anak[3];

    for(int k = 0; k < 3; k++) anak[k] =  newTreeNode(2*k+1);
    //Menambah Cabang pohon
    pohon1 = newTree(5,anak,3);
    printf("Nilai dari akar: %d\n",Root(pohon1));
    for(int i = 0; i < nChild(pohon1);i++){
        printf("Nilai dari cabang ke-%d adalah %d\n",i,Root(getChild(pohon1, i)));
    }

    //Menambah cabang pohon dengan prosedur
    Tree anak2[5];
    Tree anak3[1];
    for(int k = 0; k < 5; k++) anak2[k] =  newTreeNode(k*k*k);
    for(int k = 0; k < 1; k++) anak3[k] =  newTreeNode(6);
    addLeaves(&anak[0],anak2,5);
    addLeaves(&anak[1],anak3,1);
    Tree poke[1];
    poke[0] = newTreeNode(30);
    addLeaves(&anak3[0],poke,1);
    
    //Cetak pohon
    printPreorder(pohon1);
    printf("\n\n");
    printTree(pohon1,2);

    //Uji fungsi
    printf("nilai dari daun ke 2: %d \n",Root(getChild(pohon1,1)));
    printf("Apakah ada 64? jawaban:%d \n",searchTree(pohon1,64));
    printf("Jumlah node:%d \n",NbElmt(pohon1));
    printf("Jumlah daun:%d \n",NbDaun(pohon1));
    printf("Level dari X=30 adalah: %d \n", Level(pohon1,30));
    printf("Kedalaman dari pohon1 adalah: %d",Depth(pohon1));


    return 0;
}