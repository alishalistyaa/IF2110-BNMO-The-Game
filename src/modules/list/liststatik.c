#include "liststatik.h"
#include "../boolean/boolean.h"
#include "../time/time.h"
#include "../point/point.h"
#include "../building/building.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l)
{
    int i;
    for (i=0;i<CAPACITY;i++)
    {
        ELMTLIST(*l,i).ID=MARKLIST;
    }
}

int lengthList(ListStatik l)
{
    int i = 0;
    while(ELMTLIST(l,i).ID!=MARKLIST && i!=CAPACITY)
    {
        i++;
    }
    return (i);
}
boolean isFoodValid(ListStatik l, MAKANAN val)
{
    boolean found = false;
    int i = 0;
    while(ELMTLIST(l,i).ID!=MARKLIST && i!=CAPACITY && !found)
    {
        if(ELMTLIST(l,i).ID==val.ID)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return (found);
}
boolean isIdxListEff(ListStatik l, IdxType i)
{
    return(i>=0 && i<lengthList(l));
}
boolean isEmpty(ListStatik l)
{
    return(lengthList(l)==0);
}
boolean isFull(ListStatik l)
{
    return(lengthList(l)==CAPACITY);
}
void insert(ListStatik *l,MAKANAN val)
{
    if(isFull(*l))
    {
        printf("List penuh\n");
    }
    else
    {
        ELMTLIST(*l,lengthList(*l)) = val;
    }
}
void delete(ListStatik *l,MAKANAN *val,IdxType i)
{
    int idx;
    if(i>=0 && i<lengthList(*l))
    {
        *val = ELMTLIST(*l,i);
        idx = 0;
        while(idx<lengthList(*l))
        {
            if(idx >= i)
            {
                ELMTLIST(*l,idx) = ELMTLIST(*l,idx+1);
                idx+=1;
            }
            else
            {
                idx+=1;
            }
        }
        ELMTLIST(*l,idx-1).ID = MARKLIST;
    }
    else
    {
        (*val).ID = MARKLIST;
        printf("Index tidak terdapat di list");
    }
}
void cetakList(ListStatik l)
{
    int panjang = lengthList(l);
    int j;
    if(panjang == 0)
    {
        printf("List kosong");
    }
    else
    {
        for(j = 0;j<panjang;j++)
        {

            // TESTING
            printf("\nid makanan: %d",ID(ELMTLIST(l,j)));
            printf("\nnama makanan: %s\n", NAME(ELMTLIST(l,j)).TabWord);
            printf("delivery: ");
            TulisTIME2(DELIVERY(ELMTLIST(l,j)));
            printf("\nexpired: ");
            TulisTIME2(EXPIRED(ELMTLIST(l,j)));
            printf("\naction: ");
            TulisPOINT(ACTION(ELMTLIST(l,j)));
            printf("\n");
            
        }
    }
}
void CopyList(ListStatik l1,ListStatik *l2)
{
    int i = 0;
    while(ELMTLIST(l1,i).ID!=MARKLIST && i != CAPACITY)
    {
        ELMTLIST(*l2,i) = ELMTLIST(l1,i);
        i++;
    }
}

void cetakCatalog(ListStatik l, MAP M){
    int panjang = lengthList(l);
    int j;
    // Header
    printf("\n");
    printf("List Makanan:\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");

    if (panjang == 0)
    {
        printf("List kosong");
    }
    else
    {
        for(j = 0; j < panjang; j++)
        {
            // Tulis Nomor
            printf("%d. ", (j+1));

            // Tulis Nama Makanan
            printf("%s - ", NAME(ELMTLIST(l,j)).TabWord);

            // Tulis Expired
            TulisTIME2(EXPIRED(ELMTLIST(l,j)));  
            
            printf(" - ");

            // Tulis Action
            char K;
            K = getAction(ACTION(ELMTLIST(l,j)), M);
            if(K == 'T'){
                printf("Buy");
            } else if(K == 'F'){
                printf("Fry");
            } else if(K == 'B'){
                printf("Boil");
            } else if(K == 'M'){
                printf("Mix");
            } else if(K == 'C'){
                printf("Chop");
            } else {printf("Tidak ada aksi");}
            
            printf(" - ");

            // Tulis Delivery
            TIME DelivKosong;
            CreateTime(&DelivKosong, 0, 0, 0); 
            if (TEQ(DELIVERY(ELMTLIST(l,j)), DelivKosong)){
                printf("Tidak perlu delivery");
            } else {
                TulisTIME2(DELIVERY(ELMTLIST(l,j)));
            }
            
            printf("\n");
            
        }
    }    
}
