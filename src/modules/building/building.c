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
    while (!isFound){
        for (i = 0; i <= ROW_MAP(M); i++ ){
            for (j = 0; j <= COL_MAP(M); j++){
                if(ElmtMap(M,i,j) == C){
                    isFound = true;
                }
            }
        }
    }
    if (isBuildingExist(C, M)){
        CreatePoint(&p, i, j);
    } else {CreatePoint(&p, IDX_UNDEF, IDX_UNDEF);}
    
    return (p);

}
