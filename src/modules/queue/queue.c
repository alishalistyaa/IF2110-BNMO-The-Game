#include"queue.h"

boolean isEmpty(queue Q)
{
    return (IDXHEAD(Q)==Nil && IDXTAIL(Q)==Nil);
}
boolean isFull(queue Q)
{
    return(NBELMT(Q)==MAXEL(Q));
}
int NBELMT (queue Q)
{
    if(isEmpty(Q))
    {
        return 0;
    }
    else
    {
        return((IDXTAIL(Q) - IDXHEAD(Q)) + 1);
    }
}
void MakeEmpty(queue * Q,int Max)
{
    Buffer(*Q) = (MAKANAN *)malloc((Max+1) *sizeof(MAKANAN));
    if(Buffer(*Q)==NULL)
    {
        MAXEL(*Q) = 0;
    }
    else{
        MAXEL(*Q) = Max;
        IDXHEAD(*Q) = Nil;
        IDXTAIL(*Q) = Nil;
    }
}
void Dealokasi(queue *Q)
{
    free(Buffer(*Q));
    MAXEL(*Q) = 0;
    IDXHEAD(*Q) = Nil;
    IDXTAIL(*Q) = Nil;
}
void EnqueueInventory(queue *Q,MAKANAN food)//Buat inventory(Berdasarkan time expired)
{
    if(isEmpty(*Q))
    {
        IDXHEAD(*Q)=0;
        IDXTAIL(*Q)=0;
        INFOTAIL(*Q) = food;
    }
    else
    {
        if(isFull(*Q))//Menambah MaxEl
        {
            queue copy;
            Copy(*Q,&copy);
            Dealokasi(Q);
            MakeEmpty(Q,MAXEL(copy)*2);
            for(int i=IDXHEAD(copy);i<=IDXTAIL(copy);i++)
            {
                Enqueue(Q,ELMTQUEUE(copy,i));
            }
            Dealokasi(&copy);

        }
        boolean swap = false;
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q);i++)
        {
            if(TLT(food.Expired,ELMTQUEUE(*Q,i).Expired))
            {
                swap = true;
                for(int j = IDXTAIL(*Q);j>=i;j--)
                {
                    ELMTQUEUE(*Q,i+1) = ELMTQUEUE(*Q,i);
                }
                ELMTQUEUE(*Q,i) = food;
                break;
            }
        }
        IDXTAIL(*Q) +=1;
        if(!swap)
        {
            INFOTAIL(*Q) = food;
        }
    }
}
void EnqueueDelivery(queue *Q,MAKANAN food)//Buat Delivery
{
    if(isEmpty(*Q))
    {
        IDXHEAD(*Q)=0;
        IDXTAIL(*Q)=0;
        INFOTAIL(*Q) = food;
    }
    else
    {
        if(isFull(*Q))//Menambah MaxEl
        {
            queue copy;
            Copy(*Q,&copy);
            Dealokasi(Q);
            MakeEmpty(Q,MAXEL(copy)*2);
            for(int i=IDXHEAD(copy);i<=IDXTAIL(copy);i++)
            {
                Enqueue(Q,ELMTQUEUE(copy,i));
            }
            Dealokasi(&copy);

        }
        boolean swap = false;
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q);i++)
        {
            if(TLT(food.Delivery,ELMTQUEUE(*Q,i).Delivery))
            {
                swap = true;
                for(int j = IDXTAIL(*Q);j>=i;j--)
                {
                    ELMTQUEUE(*Q,i+1) = ELMTQUEUE(*Q,i);
                }
                ELMTQUEUE(*Q,i) = food;
                break;
            }
        }
        IDXTAIL(*Q) +=1;
        if(!swap)
        {
            INFOTAIL(*Q) = food;
        }
    }
}
void Enqueue(queue *Q,MAKANAN food)
{
    if(isEmpty(*Q))
    {
        IDXHEAD(*Q)=0;
        IDXTAIL(*Q)=0;
        INFOTAIL(*Q) = food;
    }
    else
    {
        IDXTAIL(*Q)+=1;
        INFOTAIL(*Q)=food;
    }
}
void DeleteAtInventory(queue *Q,MAKANAN food,MAKANAN *buang)
{
    boolean cari = false;
    if(isEmpty(*Q))
    {
        printf("Inventory kosong\n");
    }
    else
    {
        int idx;
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q);i++)
        {
            if(ELMTQUEUE(*Q,i).ID==food.ID)
            {
                idx = i;
                cari = true;
                break;
            }
        }
        if(cari)
        {
            int j;
            if(idx==IDXTAIL(*Q))
            {
                *buang = INFOTAIL(*Q);
                IDXTAIL(*Q) -=1;
            }
            else
            {
                *buang = ELMTQUEUE(*Q,idx);
                for(int j = idx;j<IDXTAIL(*Q);j++);
                {
                    ELMTQUEUE(*Q,j) = ELMTQUEUE(*Q,j+1); 
                }
                IDXTAIL(*Q) -= 1;
            }
        }
        else
        {
            printf("Makanan tidak ada di inventory\n");
        }
    }
}
void Dequeue(queue *Q,MAKANAN *food)
{
    if(isEmpty(*Q))
    {
        printf("Inventory kosong");
    }
    else if(IDXHEAD(*Q)==IDXTAIL(*Q))
    {
        *food = INFOHEAD(*Q);
        IDXHEAD(*Q)=Nil;
        IDXTAIL(*Q)=Nil;
    }
    else
    {
        *food = INFOHEAD(*Q);
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q)-1;i++)
        {
            ELMTQUEUE(*Q,i) = ELMTQUEUE(*Q,i+1);
        }
        IDXTAIL(*Q)-=1;
    }
}
void Copy(queue Q,queue *copy)
{
    MakeEmpty(copy,MAXEL(Q));
    for(int i = IDXHEAD(Q);i<=IDXTAIL(Q);i++)
    {
        Enqueue(copy,ELMTQUEUE(Q,i));
    }
}
void Display(queue Q)
{
    printf("List Makanan di Inventory\n");
    if(isEmpty(Q))
    {
        printf("Tidak ada makanan di inventory\n");
    }
    else
    {
        printf("(nama - waktu kadaluarsa)\n");
        for(int i = IDXHEAD(Q);i<=IDXTAIL(Q);i++)
        {
            printf("%i. %s - ",i+1,ELMTQUEUE(Q,i).Name);
            TulisTIME2(ELMTQUEUE(Q,i).Expired);
            printf("\n");
        }
    }
}