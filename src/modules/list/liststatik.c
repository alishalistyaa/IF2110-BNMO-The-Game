#include "liststatik.h"
#include "../boolean/boolean.h"
#include "../time/time.h"
#include "../point/point.h"
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
            printf("\n id makanan: %d\n",ID(ELMTLIST(l,j)));
            printf("%i. nama makanan: %s\n",(j+1), NAME(ELMTLIST(l,j)).TabWord);
            printf("delivery: ");
            TulisTIME2(DELIVERY(ELMTLIST(l,j)));
            printf("\n expired: ");
            TulisTIME2(EXPIRED(ELMTLIST(l,j)));
            printf("\n action: ");
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