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
    Buffer(*Q) = (TIME *)malloc((Max+1) *sizeof(TIME));
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
void EnqueuePrio(queue *Q,TIME time)
{
    if(isEmpty(*Q))
    {
        IDXHEAD(*Q)=0;
        IDXTAIL(*Q)=0;
        INFOTAIL(*Q) = time;
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
                Enqueue(Q,ELMT(copy,i));
            }
            Dealokasi(&copy);

        }
        boolean swap = false;
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q);i++)
        {
            if(TLT(time,ELMT(*Q,i)))
            {
                swap = true;
                for(int j = IDXTAIL(*Q);j>=i;j--)
                {
                    ELMT(*Q,i+1) = ELMT(*Q,i);
                }
                ELMT(*Q,i) = time;
                break;
            }
        }
        IDXTAIL(*Q) +=1;
        if(!swap)
        {
            INFOTAIL(*Q) = time;
        }
    }
}
void Enqueue(queue *Q,TIME time)
{
    if(isEmpty(*Q))
    {
        IDXHEAD(*Q)=0;
        IDXTAIL(*Q)=0;
        INFOTAIL(*Q) = time;
    }
    else
    {
        IDXTAIL(*Q)+=1;
        INFOTAIL(*Q)=time;
    }
}
void Dequeue(queue *Q,TIME *time)
{
    if(IDXHEAD(*Q)==IDXTAIL(*Q))
    {
        *time = INFOHEAD(*Q);
        IDXHEAD(*Q)=Nil;
        IDXTAIL(*Q)=Nil;
    }
    else
    {
        *time = INFOHEAD(*Q);
        for(int i = IDXHEAD(*Q);i<=IDXTAIL(*Q)-1;i++)
        {
            ELMT(*Q,i) = ELMT(*Q,i+1);
        }
        IDXTAIL(*Q)-=1;
    }
}
void Copy(queue Q,queue *copy)
{
    MakeEmpty(copy,MAXEL(Q));
    for(int i = IDXHEAD(Q);i<=IDXTAIL(Q);i++)
    {
        Enqueue(copy,ELMT(Q,i));
    }
}
void Display(queue Q)
{
    for(int i = IDXHEAD(Q);i<=IDXTAIL(Q);i++)
    {
        printf("%i. ",i+1);
        TulisTIME2(ELMT(Q,i));
        printf("\n");
    }
}