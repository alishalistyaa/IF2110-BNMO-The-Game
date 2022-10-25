#include "liststatik.h"
#include "../boolean/boolean.h"
#include <stdio.h>
void CreateListStatik(ListStatik *l)
{
    int i;
    for (i=0;i<CAPACITY;i++)
    {
        ELMT(*l,i)=MARK;
    }
}
int lengthList(ListStatik l)
{
    int i = 0;
    while(ELMT(l,i)!=MARK && i!=CAPACITY)
    {
        i++;
    }
    return (i);
}
boolean isValValid(ListStatik l, ElType val)
{
    boolean found = false;
    int i = 0;
    while(ELMT(l,i)!=MARK && i!=CAPACITY && !found)
    {
        if(ELMT(l,i)==val)
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
boolean isIdxEff(ListStatik l, IdxType i)
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
void bacaList(ListStatik *l)
{
    int n;
    int i;
    printf("Masukkan banyak item yang akan dimasukkan ke dalam list = ");
    scanf("%i",&n);
    while (n<0 || n>CAPACITY)
    {
        printf("Masukkan salah,silahkan input lagi = ");
        scanf("%i",&n);
    }
    CreateListStatik(l);
    if(n!=0)
    {
        for(i=0;i<n;i++)
        {
            printf("Masukkan ID makanan/resep %i = \n",(i+1));
            scanf("%i",&ELMT(*l,i));
        }
    }
}
void cetakList(ListStatik l)
{
    int panjang = lengthList(l);
    int i;
    if(panjang == 0)
    {
        printf("List kosong");
    }
    else
    {
        for(i = 0;i<panjang;i++)
        {
            printf("%i. %i\n",(i+1),ELMT(l,i));
        }
    }
}
void CopyList(ListStatik l1,ListStatik *l2)
{
    int i = 0;
    while(ELMT(l1,i)!=MARK && i != CAPACITY)
    {
        ELMT(*l2,i) = ELMT(l1,i);
        i++;
    }
}