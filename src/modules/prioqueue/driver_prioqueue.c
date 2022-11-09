#include "prioqueue.c"

int main() {
    PrioQueue Q;
    MakeEmpty(&Q, 3);
    infotypePrioQueue T, T1, T2, T3;
    T.info = 'c';
    T.time = 1;
    T1.info = 'c';
    T1.time = 2;
    T3.info = 'c';
    T3.time = 2;
    Enqueue(&Q, T);
    Enqueue(&Q, T1);
    Enqueue(&Q, T3);
    PrintPrioQueue(Q);
    printf("%d\n", NBElmt(Q));
    printf("%d\n", IsFull(Q));
    printf("%d\n", Head(Q));
    printf("%d\n", Tail(Q));
    // DeAlokasi(&Q);
    // printf("%d\n", NBElmt(Q));
}