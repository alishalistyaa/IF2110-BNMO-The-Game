/* File: i_o.c */
/* Implementasi Input / Output */

#include <stdio.h>
#include "i_o.h"
#include "../building/building.h"

void configMakanan(MAP peta, char *filename, ListStatik *listofMakanan){
    /* Membaca file figurasi config dan membaca makanan */
    /* I.S. Makanan sembarang */
    /* F.S. Makanan terdefinisi dari file */
    // KAMUS LOKAL
    int countMakanan;
    int i;
    int tempID;
    TIME tempExpired;
    POINT tempActionPoint;
    TIME tempDelivery;
    Word tempName;    
    Word tempActionWord;    


    // ALGORITMA
    // Membaca berapa makanan yang ada di file config
    ADVFILE(filename);
    countMakanan = 0;
    while (currentChar != LINEMARK){
            countMakanan = countMakanan * 10 + (currentChar - 48);
            ADV();
            IgnoreBlanks();    
    }
    // testing
    printf("%d\n", countMakanan);

    // Membaca makanan sebanyak countMakanan
    for(i = 0; i < countMakanan; i++){
        // TESTING
        printf("i: %d\n", i);
        /* BACA ID */
        tempID = 0;
        ADV(); // next after LINEMARK
        while (currentChar != LINEMARK){
            while (currentChar != BLANK && currentChar != LINEMARK) {
                tempID = tempID * 10 + (currentChar - 48);
                ADV();
            }      
    }        
        // testing
        printf("%d\n", tempID);

        /* BACA JUDUL */
        ADV(); // next after LINEMARK
        CopyWord();
        tempName = currentWord;
        // tempName = currentWord.TabWord;
        printf("%s\n", tempName.TabWord);

        // TESTING
        // printf("DONE JUDUL\n");

        /* BACA EXPIRED */
        ADV(); // next after LINEMARK
        int LEx[3];
        int countEx = 0;
        while (currentChar != LINEMARK) {
            int value = 0;
                while (currentChar != BLANK && currentChar != LINEMARK) {
                    value = value * 10 + (currentChar - 48);
                    ADV();
                }
                LEx[countEx] = value;
                if (currentChar == BLANK) {
                    ADV();
                }
                countEx++;
        } 
        
        // Masukkan ke dalam time
        CreateTime(&tempExpired, LEx[0], LEx[1], LEx[2]); 

        //TESTING
        // printf("Done EXPIRED\n");     

        /* BACA DELIVERY */
        ADV(); //Next after LINEMARK
        int LDeliv[3];
        int countDeliv = 0;
        while (currentChar != LINEMARK) {
            int value = 0;
                while (currentChar != BLANK && currentChar != LINEMARK) {
                    value = value * 10 + (currentChar - 48);
                    ADV();
                }
                LDeliv[countDeliv] = value;
                if (currentChar == BLANK) {
                    ADV();
                }
                countDeliv++;
        } 
        // Masukkan ke dalam time
        CreateTime(&tempDelivery, LDeliv[0], LDeliv[1], LDeliv[2]); 

        // TESTING
        // printf("Done DELIVERY\n");

        /* BACA ACTION */
        ADV();
        CopyWord(); // next after LINEMARK
        tempActionWord = currentWord;
        // printf("%s\n", tempActionWord);

        // Convert Action to Point
        if (same(currentWord, "Buy")){
            Absis(tempActionPoint) = Absis(getLocBuilding('B', peta));
            Ordinat(tempActionPoint) = Ordinat(getLocBuilding('B', peta));
        } 
        else if (same(currentWord, "Fry")){
            Absis(tempActionPoint) = Absis(getLocBuilding('F', peta));
            Ordinat(tempActionPoint) = Ordinat(getLocBuilding('F', peta));
        }
        else if (same(currentWord, "Boil")){
            Absis(tempActionPoint) = Absis(getLocBuilding('B', peta));
            Ordinat(tempActionPoint) = Ordinat(getLocBuilding('B', peta));            
        }
        else if (same(currentWord, "Mix")){
            Absis(tempActionPoint) = Absis(getLocBuilding('M', peta));
            Ordinat(tempActionPoint) = Ordinat(getLocBuilding('M', peta));
        }
        else if (same(currentWord, "Chop")){
            Absis(tempActionPoint) = Absis(getLocBuilding('C', peta));
            Ordinat(tempActionPoint) = Ordinat(getLocBuilding('C', peta));
        } else { CreatePoint(&tempActionPoint, 0, 0); }

        // TESTING
        // printf("Done ACTION\n");
        // printf("%s\n", tempName.TabWord);
        MAKANAN M;
        CreateMakanan(&M, tempID, tempName, tempExpired, tempActionPoint, tempDelivery);
        insert(listofMakanan, M);

        // TESTING
        // printf("Done MAKANAN\n");
    }
    fclose(pita);
}

void configMap(char *filename, Matrix *m){
    /* Membaca file figurasi config dan membaca map */
    /* I.S. Map sembarang */
    /* F.S. Map terdefinisi dari file */
    /* Prekondisi: filename pasti valid dan exist */
    // KAMUS LOKAL
    ADVFILE("peta.txt");
    int i = 0;
    int M[2];
    while (currentChar != LINEMARK) {
        int value = 0;
        while (currentChar != BLANK && currentChar != LINEMARK) {
            value = value * 10 + (currentChar - 48);
            ADV();
        }
        M[i] = value;
        if (currentChar == BLANK) {
            ADV();
        }
        i++;
    }    
    
    createMatrix(M[0] + 2, M[1] + 2, m);
    // creating border for matrix peta
    for (int i = 0; i < M[1] + 2; i++) {
        (*m).mem[0][i] = '*';
        (*m).mem[M[0] + 1][i] = '*';
    }
    for (int i = 0; i < M[0] + 2; i++) {
        (*m).mem[i][0] = '*';
        (*m).mem[i][M[1] + 1] = '*';
    }

    ADV(); // next after LINEMARK
    while (currentChar != FILEMARK) {
        for (int i = 1; i < M[0] + 1; i++) {
            if (currentChar == LINEMARK) {
                ADV();
            }
            for (int j = 1; j < M[1] + 1; j++) {
                if (currentChar == '#') {
                    (*m).mem[i][j] = BLANK;
                    ADV();
                } else {
                    (*m).mem[i][j] = currentChar;
                    ADV();
                }
            }
        }
    }
    fclose(pita);
}


void configResep(char *filename, BukuResep *b){
    /* Membaca file figurasi config dan membaca resep */
    /* I.S. Resep sembarang */
    /* F.S. Resep terdefinisi dari file */
    //KAMUS LOKAL
    int i,j,k;
    int nResep;
    int child[100];
    int ctr;

    nResep = 0;
    //ALGORITMA
    ADVFILE(filename);
    while(currentChar != LINEMARK){
        nResep = nResep * 10 + (currentChar - 48);
        ADV();
    }
    BanyakResep(*b) = nResep;
    ADV(); // next after LINEMARK
    

    for(j = 0; j < nResep; j++){
        i = 0;
        while (currentChar == BLANK || currentChar == LINEMARK) ADV();
        while (currentChar != BLANK)
        {
            i = i * 10 + (currentChar - 48);
            ADV();
        }
        //currentChar == BLANK
        ELMTBUKURESEP(*b,j) = newTreeNode(i);
        ADV();
        
        ctr = 0;
        while (currentChar != BLANK)
        {
            ctr = ctr * 10 + (currentChar - 48);
            ADV();
        }
        //currentChar == BLANK
        ADV();

        nChild(ELMTBUKURESEP(*b,j)) = ctr;
        addressChild(ELMTBUKURESEP(*b,j)) = (Tree) malloc(ctr *sizeof(Tree));
        i = 0;
        int k = 0;
        while(currentChar != FILEMARK && currentChar != LINEMARK){
            while (currentChar != BLANK  && currentChar != LINEMARK && currentChar != FILEMARK)
                {
                i = i * 10 + (currentChar - 48);
                ADV();
                }
            //currentChar == BLANK or LINEMARK or FILEMARK
            getChild(ELMTBUKURESEP(*b,j),k) = newTreeNode(i);
            if(currentChar == BLANK){
                k++;
                i = 0;
                ADV(); //Lanjut ke angka selanjutnya  
            }
        }

        }
    
    fclose(pita);
}

int stringlen(char *s) {
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}

boolean same(Word one, char *s) {
    if (one.Length == stringlen(s)) {
        for (int i = 0; i < one.Length; i++) {
            if (one.TabWord[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
boolean validateString();
/* Mengembalikan true jika string yang dimasukkan valid */