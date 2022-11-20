#include "prioqueue.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"



int main() {
    PrioQueue Q;
    MakeEmpty(&Q, 1);
    infotypePrioQueue M1, M2, M3;
    ID(M1) = 1;
    NAME(M1).Length = 4;            
	NAME(M1).TabWord[0] = 'A' ;         
	NAME(M1).TabWord[1] = 'Y' ;         
	NAME(M1).TabWord[2] = 'A' ;          
	NAME(M1).TabWord[3] = 'M' ;
	NAME(M1).TabWord[4] = '\0';
    CreateTime(&EXPIRED(M1), 0, 2, 0);                                      
    CreatePoint(&ACTION(M1), 0, 0);                      
    CreateTime(&DELIVERY(M1), 0, 0, 15);  
    EnqueueDelivery(&Q, M1);
    printInventoryDelivery(Q);
    decreaseTimeDelivery(&Q,1);
    printInventoryDelivery(Q);
}