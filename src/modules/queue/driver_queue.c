#include"queue.c"
#include"../time/time.c"
#include"../makanan/makanan.c"
#include"../point/point.c"

int main()
{
    MAKANAN M1;
    MAKANAN M2;
    MAKANAN M3;
    POINT P1;
    POINT P2;
    POINT P3;
    TIME K1;
    TIME K2;
    TIME K3;
    TIME D1;
    TIME D2;
    TIME D3;
    CreatePoint(&P1,0,0);
    CreatePoint(&P2,0,0);
    CreatePoint(&P3,0,0);
    CreateTime(&K1,1,2,3);
    CreateTime(&K2,4,1,2);
    CreateTime(&K3,2,4,5);
    CreateTime(&D1,1,2,3);
    CreateTime(&D2,4,1,2);
    CreateTime(&D3,2,4,5);

    int ID1 = 21;
    int ID2 = 31;
    int ID3 = 41;
    char Name1 = "Ayam";
    char Name2 = "Tahu";
    char Name3 = "Tempe";
    CreateMakanan(&M1,ID1,Name1,K1,P1,D1);
    CreateMakanan(&M2,ID2,Name2,K2,P2,D2);
    CreateMakanan(&M3,ID3,Name3,K3,P3,D3);
    MAKANAN buang;

    queue p;
    queue salin;
    MakeEmpty(&p,1);
    printf("\n Buat Queue\n");
    printf("apakah empty = %i (1 benar 0 salah)\n",isEmpty(p));
//---Enqueue---
    EnqueuePrio(&p,M1);
    EnqueuePrio(&p,M2);
    EnqueuePrio(&p,M3);
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
    TulisTIME2(buang.Expired);
    printf(" adalah waktu yang dibuang");
    printf("\nMaxEl = %i",MAXEL(p));
//---Dealokasi---
    Dealokasi(&p);
    printf("\n-----Dealokasi-------\n");
    printf("\nMaxEl = %i\n",MAXEL(p));
//--Inventory kosong-----
    printf("\n-----Inventory Kosong-------\n");
    Dequeue(&p,&buang);
    Dequeue(&p,&buang);
    Display(p);
}