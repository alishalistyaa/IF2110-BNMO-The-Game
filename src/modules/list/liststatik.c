#include "liststatik.h"

#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

/* STOCK */
void CreateStock(STOCK *s){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    for(int i = 0; i < CAPACITY; i++){
        ELMTSTOCK(*s,i)= 0;
    }
}

void IncreaseStock(STOCK *s, int ID){
    /* Menambahkan satu stock pada ID tertentu */
    ELMTSTOCK(*s, ID)++;
}

void DecreaseStock(STOCK *s, int ID){
    /* Mengurangi satu stock pada ID tertentu */
    ELMTSTOCK(*s, ID)--;
}

void CopyStock(STOCK S1, STOCK *S2){
    for(int i = 0; i < CAPACITY; i++){
        ELMTSTOCK(*S2,i)= ELMTSTOCK(S1,i);
    }
}

void displayStock(STOCK S, ListStatik l){
    boolean stockempty = true;
    for(int i = 0; i < CAPACITY; i++){
        for(int k = 0; k < lengthList(l); k++){
            if((ID(ELMTLIST(l,k)) == i) && (ELMTSTOCK(S,i) > 0)){
                printf("%s: %d buah\n", NAME(ELMTLIST(l,k)).TabWord,ELMTSTOCK(S,i));
                stockempty = false;
            }
        }
                
    }
    if(stockempty) printf("Stok kosong!");
}

// boolean isFoodValid(ListStatik l, int ID_Makanan){
//     /* Mengirimkan true jika i adalah elemen yang valid dari makanan */
//     boolean found = false;
//     int i = 0;
//     while(ELMTLIST(l,i).ID!=MARKLIST && i!=CAPACITY && !found)
//     {
//         if(ELMTLIST(l,i).ID==ID_Makanan)
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return (found);
// }

/* LIST STATIK */
void CreateListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    int i;
    for (i=0;i<CAPACITY;i++)
    {
        ELMTLIST(*l,i).ID=MARKLIST;
    }
}

int lengthList(ListStatik l){
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */ 
    int i = 0;
    while(ELMTLIST(l,i).ID!=MARKLIST && i!=CAPACITY)
    {
        i++;
    }
    return (i);
}

Word getNameMakanan(ListStatik l, int ID){
    /* Mengirimkan nama makanan dari ID */
    boolean isFound = false;
    Word makanan;
    int i = 0;
    while(!isFound && i!=CAPACITY){
        if (ID(ELMTLIST(l, i)) == ID){
            makanan = NAME(ELMTLIST(l, i));
            isFound = true;
        }
        i++;
    }
    return makanan;
}

MAKANAN getMakanan(ListStatik l, int ID){
    boolean isFound = false;
    MAKANAN mkn;
    int i = 0;
    while(!isFound && i!=CAPACITY){
        if (ID(ELMTLIST(l, i)) == ID){
            mkn = ELMTLIST(l, i);
            isFound = true;
        }
        else i++;
    }
    return mkn;
}


boolean isIdxListEff(ListStatik l, IdxType i){
    return(i>=0 && i<lengthList(l));}
boolean isEmpty(ListStatik l){
    return(lengthList(l)==0);}
boolean isFull(ListStatik l){
    return(lengthList(l)==CAPACITY);}

void insert(ListStatik *l,MAKANAN val){
    /* Menambah elemen val sebagai elemen terakhir list*/
    if(isFull(*l)){
        printf("List penuh\n");
    }
    else { ELMTLIST(*l,lengthList(*l)) = val; }
}

void delete(ListStatik *l,MAKANAN *val,IdxType i){
    /*Menghapus elemen indeks ke i pada list*/
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


// void displayBuyable(ListStatik l, ListStatik *buylist){
//     int length = lengthList(l);
//     int ctr = 1;
//     for(int i = 0; i < length; i++){
//         if(same(NAME(ELMTLIST(l,i)) ,"Buy")){
//             printf("   %d. %s (",ctr,NAME(ELMTLIST(l,i)));
//             TulisTIME2(DELIVERY(ELMTLIST(l,i)));
//             printf(")\n");

//             ELMTLIST(*buylist,ctr-1) = ELMTLIST(l,i);
//             ctr++;
//         }
//     }
//     printf("\nKirim 0 untuk exit.\n");
// }

// void displayCookMethod(ListStatik l, ListStatik *methodlist, char *method){
//     int length = lengthList(l);
//     int ctr = 1;
//     printf("List Bahan Makanan yang Bisa Dibuat:\n");
//     for(int i = 0; i < length; i++){
//         if(same(NAME(ELMTLIST(l,i)),method)){
//             printf("   %d. %s (",ctr,NAME(ELMTLIST(l,i)));
//             TulisTIME2(DELIVERY(ELMTLIST(l,i)));

//             ELMTLIST(*methodlist,ctr-1) = ELMTLIST(l,i);
//             ctr++;
//         }
//     }
//     printf("\nKirim 0 untuk exit.\n");
// }


