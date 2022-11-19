#include "resep.h"
#include <stdio.h>



void CreateBukuResep(BukuResep *b){
/* I.S. r sembarang */
/* F.S. Terbentuk buku resep kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    for(int i = 0; i < CAPACITY; i++){
        ELMTBUKURESEP(*b,i) = NULL;
    }
    BanyakResep(*b) = 0;
}  

//boolean isResepValid(BukuResep b, Resep r);
/* Mengirimkan true jika i adalah elemen yang valid dari BukuResep */


boolean isBukuResepEmpty(BukuResep b){
/* Mengirimkan true jika Buku Resep kosong, mengirimkan false jika tidak */
    return BanyakResep(b) == 0;
}

boolean isBukuResepFull(BukuResep b){
/* Mengirimkan true jika Buku Resep penuh, mengirimkan false jika tidak */
     return BanyakResep(b) == CAPACITY;
}

//Fungsi2 lainnya
void insertResep(BukuResep *b,Resep r){
/* Menambah Resep pada buku resep; apabila sudah penuh tidak perlu ditambahkan*/
    if(!isBukuResepFull(*b)){
        ELMTBUKURESEP(*b,BanyakResep(*b)) = r;
        BanyakResep(*b) += 1;
    }
}

void delResep(BukuResep *b, Resep *buffer,IdxResep i){
    /*Menghapus elemen indeks ke i pada list*/
    //PREKONDISI: Indeks i valid;
    *buffer = ELMTBUKURESEP(*b,i);
    free(ELMTBUKURESEP(*b,i));
    int ctr = i;
    while(ctr <= BanyakResep(*b)-2){
        ELMTBUKURESEP(*b,ctr) = ELMTBUKURESEP(*b,ctr+1);
        ctr++; 
    }
    BanyakResep(*b) -= 1;
}


void cetakBukuResep(BukuResep b, ListStatik listmakanan, MAP M){
/* I.S. BukuResep boleh kosong */
/* F.S. Jika BukuResep tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
    int j,k;
    printf("List Resep\n (aksi yang diperlukan - bahan...)\n");
    for(int i = 0; i < BanyakResep(b);i++){
        //Mendapatkan Root:
        j = 0;
        while(Root(ELMTBUKURESEP(b,i)) != ID(ELMTLIST(listmakanan,j)) ) j++;
        //Cetak baris 1
        printf("%d. %s\n",(i+1),ELMTLIST(listmakanan,j).Name);
        //Mendapatkan action:
        char K;
        K = getAction(ACTION(ELMTLIST(listmakanan,j)), M);
        if(K == 'F'){
            printf("   FRY ");
        } else if(K == 'B'){
            printf("   BOIL ");
        } else if(K == 'M'){
            printf("   MIX ");
        } else if(K == 'C'){
            printf("   CHOP ");
        }
        for(k = 0; k < nChild(ELMTBUKURESEP(b,i)); k++){
            j = 0;
            
            while(Root(getChild(ELMTBUKURESEP(b,i),k)) != ID(ELMTLIST(listmakanan,j)) ) j++;
            printf("- %s ", NAME(ELMTLIST(listmakanan,j)).TabWord);
        }
        printf("\n");
    }
}

//void printResep(Resep r);

boolean isResepOlahable(BukuResep b, int ID_Root, STOCK s){
    boolean olahable = true;
    for(int i = 0; i < BanyakResep(b); i++){
        if(ID_Root == Root(ELMTBUKURESEP(b,i))){
            for(int k = 0; k < nChild(ELMTBUKURESEP(b,i));k++){
                int ID_bahan = Root(getChild(ELMTBUKURESEP(b,i),k));
                olahable &= (ELMTSTOCK(s, ID_bahan) > 0);
                }             
            }                                                
        }
    return olahable;
}

Resep getResep(BukuResep b, int ID_Root){
    int i = 0;
    boolean notfound = true;
    while( i < BanyakResep(b) && notfound){
        if(ID_Root == Root(ELMTBUKURESEP(b,i))) notfound = false;
        i++;
    }
    return ELMTBUKURESEP(b,i-1);
}

void printBahanMissing(Resep r, STOCK S, ListStatik listmakanan){
    int ctr = 1;
    for(int i = 0; i < nChild(r);i++){
        if(ELMTSTOCK(S,Root(getChild(r,i))) <= 0){
            for(int k = 0; k < lengthList(listmakanan); k++){
                if(ID(ELMTLIST(listmakanan,k)) == Root(getChild(r,i))){
                    printf("   %d. %s\n",ctr,NAME(ELMTLIST(listmakanan,k)));
                    ctr++;
                }
            }
        }
    }
}


SET StockToSet(STOCK St){
    SET s;
    createEmptySet(&s);
    HEADSET(s) = MARKSTOCK;
    for(int i = 0; i < CAPACITY; i++){
        if(ELMTSTOCK(St,i) > 0) ELMTSET(s,i) = true;
        else ELMTSET(s,i) = false;
    }
    return s;
}

SET ResepToSet(Resep r){
    SET s;
    createEmptySet(&s);
    HEADSET(s) = Root(r);
    for(int i = 0; i < nChild(r); i++){
        ELMTSET(s,Root(getChild(r,i))) = true;
    }
    return s;
}



void ListRekomenn(SET stock, BukuResep b, SET *listrkm){
    for(int i = 0; i < BanyakResep(b); i++){
        //KAMUS
        // ResepToSet(ELMTBUKURESEP(b,i)) : Resep representasi Set
        if(isSubset(stock,ResepToSet(ELMTBUKURESEP(b,i)))){
            //Buat Stock baru
            SET newstock;
            createEmptySet(&newstock);
            HEADSET(newstock) = MARKSTOCK;
            //Update elemen newstock
            for(int k = 0; k < CAPACITY; k++){
                if(ELMTSET(stock,k) && ELMTSET(ResepToSet(ELMTBUKURESEP(b,i)),k)) ELMTSET(newstock,k) = false;
                else ELMTSET(newstock,k) = ELMTSET(stock,k);
            }
            //Untuk ELMT dari newstocknya HEADSETnya resep diupdate
            ELMTSET(newstock,HEADSET(ResepToSet(ELMTBUKURESEP(b,i)))) = true;
            ELMTSET(*listrkm,HEADSET(ResepToSet(ELMTBUKURESEP(b,i)))) = true;

            //Rekurens
            ListRekomenn(newstock, b, listrkm);




        }
    }
}

/*
*******************************************************************
*******************************************************************
*******************************************************************
---------------------- BONUS 3 ------------------------------------
*******************************************************************
*******************************************************************
*******************************************************************
*/
SET ListRekomen(SET stock, BukuResep b){
    SET listrkm;
    createEmptySet(&listrkm);
    HEADSET(listrkm) = MARKLISTREKOMEN;
    ListRekomenn(stock, b, &listrkm);
    return listrkm;
}



void printListRekomen(SET s, ListStatik l){
    int counter = 1;
    for(int i = 0; i < CAPACITY; i++){
        if(ELMTSET(s,i)){
            printf("%d. %s\n",counter,getNameMakanan(l,i).TabWord);
            counter++;  
        }
    }

    
}


//Resep concatResep(Resep r1, Resep r2);
/*Melakukan konkatenasi Resep 2 ke resep 1*/