#include"queue.c"
#include"../time/time.c"

int main()
{
    TIME T1;
    TIME T2;
    TIME T3;
    TIME T4;
    TIME T5;
    TIME buang;
    BacaTIMEKedaluwarsa(&T1);
    BacaTIMEKedaluwarsa(&T2);
    BacaTIMEKedaluwarsa(&T3);
//    BacaTIMEKedaluwarsa(&T4);
//    BacaTIMEKedaluwarsa(&T5);
    queue p;
    queue salin;
    MakeEmpty(&p,1);
    printf("\n Buat Queue\n");
    printf("apakah empty = %i (1 benar 0 salah)\n",isEmpty(p));
//---Enqueue---
    EnqueuePrio(&p,T1);
    EnqueuePrio(&p,T2);
    EnqueuePrio(&p,T3);
//    EnqueuePrio(&p,T4);
//    EnqueuePrio(&p,T5);

//---Info Head dan Tail----
    printf("-------Info Head Tail------------\n");
    printf("\nHead idx = %d\n",IDXHEAD(p));
    printf("\nTail idx = %d\n",IDXTAIL(p));
    printf("--------Isi Queue----------\n");
//----Isi Queue-----
    Display(p);
//----Salin Queue----
    printf("-------salin---------");
    printf("\n");
    Copy(p,&salin);
    Display(salin);
    printf("\n---------Dequeue--------------\n");
//----Dequeue--- 
    Dequeue(&p,&buang);
    Display(p);
    TulisTIME2(buang);
    printf(" adalah waktu yang dibuang");
    printf("\nMaxEl = %i",MAXEL(p));
//---Dealokasi---
    Dealokasi(&p);
    printf("\n-----Dealokasi-------\n");
    printf("\nMaxEl = %i",MAXEL(p));
}