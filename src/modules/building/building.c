#include <stdio.h>
#include "building.h"
#include "../point/point.h"
#include "../boolean/boolean.h"
#include "../map/map.h"

/* *** PROTOTYPE PRIMITIF  *** */
void CreateBuilding(BUILDING *B, POINT p, char name){
    /* Membentuk sebuah BUILDING dari komponen-komponennya yang valid */
    // Algoritma
    XCOORD(*B) = Absis(p);
    YCOORD(*B) = Ordinat(p);
    TYPE(*B) = name; 
}

boolean isBuildingSame(BUILDING B1, BUILDING B2){
    /* Mengembalikan true jika type building sama */
    // Algoritma
    return (TYPE(B1) == TYPE(B2));
}

boolean isBuildingExist(char C, MAP M){
    /* Mengembalikan true jika building exist */
        // Kamus Lokal
        int i, j;
        boolean isFound;
        POINT p;

    // Algoritma
        isFound = false;
        while (!isFound){
            for (i = 0; i <= ROW_MAP(M); i++ ){
                for (j = 0; j <= COL_MAP(M); j++){
                    if((char) ElmtMap(M,i,j) == (char) C){
                        isFound = true;
                    }
                }
            }
        }
    return(isFound);
}

POINT getLocBuilding(char C, MAP M){
    /* Mengembalikan lokasi bangunan */
    // Kamus Lokal
    int i, j;
    boolean isFound;
    POINT p;

    // Algoritma
    isFound = false;
    int idxb, idxk;
    while (!isFound){
        for (i = 0; i < ROW_MAP(M); i++ ){
            for (j = 0; j < COL_MAP(M); j++){
                if(ElmtMap(M,i,j) == C){
                    isFound = true;
                    idxb = i;
                    idxk = j;
                }
            }
        }
    }
    if (isBuildingExist(C, M)){
        CreatePoint(&p, idxb-1, idxk-1);
    } else {CreatePoint(&p, IDX_UNDEF, IDX_UNDEF);}
    
    return (p);

}

int getAction(char C){
    // KAMUS LOKAL
    // char C; //NOTE: ADA KESALAHAN DEKLARASI VARIABEL SEPERTINYA DISINI???????
    // ElmtMap(M,Absis(P), Ordinat(P)) = C;

    // ALGORITMA
    int idx;
    if (C == 'B'){
        idx = 0;
    } else if(C == 'F'){
        idx = 1;
    } else if(C == 'B'){
        idx = 2;
    } else if(C == 'M'){
        idx = 3;
    } else if(C == 'C'){
        idx = 4;
    }
    return idx;
}