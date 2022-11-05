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


void cetakBukuResep(BukuResep b){
/* I.S. BukuResep boleh kosong */
/* F.S. Jika BukuResep tidak kosong akan mencetak secara terurut dari indeks 1 ke indeks (length-1) */
    for(int i = 0; i < BanyakResep(b);i++){
        printf("Resep %d:\n",(i+1));
        printTree(ELMTBUKURESEP(b,i),2);
        printf("\n");
    }
}

//void printResep(Resep r);

boolean isResepOlah_able(Resep r){
    
}


//Resep concatResep(Resep r1, Resep r2);
/*Melakukan konkatenasi Resep 2 ke resep 1*/