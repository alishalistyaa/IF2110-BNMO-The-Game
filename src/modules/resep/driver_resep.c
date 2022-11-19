#include "resep.c"
#include "../tree/tree.c"
#include "../boolean/boolean.h"
#include "../makanan/makanan.c"
#include "../list/liststatik.c"
#include "../building/building.c"
#include "../prioqueue/prioqueue.c"
#include "../wordmachine/wordmachine.c"
#include "../charmachine/charmachine.c"
#include "../time/time.c"
#include "../point/point.c"

int main(){
    

    SET ayam_potong;
    createEmptySet(&ayam_potong);
    HEADSET(ayam_potong) = 21;
    ELMTSET(ayam_potong,11) = true;

    SET ayam_tepung;
    createEmptySet(&ayam_tepung);
    HEADSET(ayam_tepung) = 31;
    ELMTSET(ayam_tepung,21) = true;
    ELMTSET(ayam_tepung,10) = true;
    

    SET ayam_goreng;
    createEmptySet(&ayam_goreng);
    HEADSET(ayam_goreng) = 37;
    ELMTSET(ayam_goreng,31) = true;
    ELMTSET(ayam_goreng,15) = true;

    //CATATAN:
    //ADT Resep lebih banyak terkoneksi ke main, jadi belum banyak yang dapat dicoba disini
    //(karena konsepnya hampir sama dengan tree)
    
    



    return 0;
}