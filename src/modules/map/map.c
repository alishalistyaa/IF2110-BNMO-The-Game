#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "../i_o/i_o.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

/* Loader */
void createMap(MAP *M)
/* I.S. map sembarang */
/* F.S. map dengan ukuran row x col terbentuk */
{
    ROW_MAP(*M) = IDX_UNDEF;
    COL_MAP(*M) = IDX_UNDEF;
    int i,j;
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 50; j++)
        {
            ElmtMap(*M,i,j) = '*';
        }
    }
    Absis(S(*M))=IDX_UNDEF;
    Ordinat(S(*M))=IDX_UNDEF;
}

void loadMap(MAP *M, char *filename)
/* I.S. map sembarang */
/* F.S. map terbentuk dari file eksternal */
{
    ADVFILE(filename);
    int i = 0;
    int s[2];
    while (currentChar != LINEMARK) {
        int value = 0;
        while (currentChar != BLANK && currentChar != LINEMARK) {
            value = value * 10 + (currentChar - 48);
            ADV();
        }
        s[i] = value;
        if (currentChar == BLANK) {
            ADV();
        }
        i++;
    }    
    
    createMatrix(s[0] + 2, s[1] + 2, &MATRIX(*M));
    // creating border for matrix peta
    for (int i = 0; i < s[1] + 2; i++) {
        (*M).m.mem[0][i] = '*';
        (*M).m.mem[s[0] + 1][i] = '*';
    }
    for (int i = 0; i < s[0] + 2; i++) {
        (*M).m.mem[i][0] = '*';
        (*M).m.mem[i][s[1] + 1] = '*';
    }

    ADV(); // next after LINEMARK
    while (currentChar != FILEMARK) {
        for (int i = 1; i < s[0] + 1; i++) {
            if (currentChar == LINEMARK) {
                ADV();
            }
            for (int j = 1; j < s[1] + 1; j++) {
                if (currentChar == '#') {
                    (*M).m.mem[i][j] = BLANK;
                    ADV();
                } else if (currentChar != 'S') {
                    (*M).m.mem[i][j] = currentChar;
                    ADV();
                } else {
                    (*M).m.mem[i][j] = BLANK;
                    Absis(S(*M)) = i-1;
                    Ordinat(S(*M)) = j-1;
                    ADV();
                }
            }
        }
    }
    fclose(pita);
}
/* Validator */
boolean isEmptyMap(MAP M)
/* Mengembalikan true jika map kosong */
{
    return (ROW_MAP(M) == IDX_UNDEF && COL_MAP(M) == IDX_UNDEF);
}

boolean isIdxMapValid(int i, int j)
/* Mengembalikan true jika indeks map valid */
{
    return (i > IDX_MIN && i <= CAPACITYMAP && j > IDX_MIN && j <= CAPACITYMAP);
}

boolean isIdxMapEff(MAP M, int i, int j)
/* Mengembalikan true jika indeks map efektif */
{
    return (i > IDX_MIN && i <= ROW_MAP(M) && j > IDX_MIN && j <= COL_MAP(M));
}

void printMap(MAP M)
/* I.S. map terdefinisi */
/* F.S. map ditampilkan ke layar */
{
    for (int i = 0; i < ROW_MAP(M); i++) {
        for (int j = 0; j < COL_MAP(M); j++) {
            if (i == Absis(S(M)) + 1 && j == Ordinat(S(M)) + 1) {
                printf("S ");
            } else {
                printf("%c ", ElmtMap(M, i, j));
            }
        }
        printf("\n");
    } 
}

boolean isNear(MAP M, char ch) {
// /* Mengembalikan true jika ada bangunan dengan karakter ch yang berdekatan dengan bangunan lain */
// {
//     if(Absis(S(M)) != 0){
//         if(ElmtMap(M, (int)Absis(S(M))-1, (int)Ordinat(S(M))) == ch){
//             return true;
//         }
//     }

//     if(Absis(S(M)) != ROW_MAP(M)){
//         if(ElmtMap(M, (int)Absis(S(M))+1, (int)Ordinat(S(M))) == ch){
//             return true;
//         }
//     }

//     if(Ordinat(S(M)) != 0){
//         if(ElmtMap(M, (int)Absis(S(M)), (int)Ordinat(S(M))-1) == ch){
//             return true;
//         }
//     }

//     if(Ordinat(S(M)) != COL_MAP(M)-1){
//         if(ElmtMap(M, (int)Absis(S(M)), (int)Ordinat(S(M))+1) == ch){
//             return true;
//         }
//     }

//     return false;
    if (ElmtMap(M, (int)Absis(S(M)) + 1, (int)Ordinat(S(M))) == ch ||
        ElmtMap(M, (int)Absis(S(M)), (int)Ordinat(S(M)) + 1) == ch ||
        ElmtMap(M, (int)Absis(S(M)) + 1, (int)Ordinat(S(M)) + 2) == ch ||
        ElmtMap(M, (int)Absis(S(M)) + 2, (int)Ordinat(S(M)) + 1) == ch) {
            return true;
    } else {
        return false;
    }
}

void move_map(MAP *M, Word command, boolean *canmove) 
/* I.S. map terdefinisi */
/* F.S. map bergerak sesuai dengan command */
{
    if(same(command, "NORTH")){
        if(ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))+1) == ' '){
            Absis(S(*M))--;
            *canmove = true;
        }
        else{
            printf("Tidak dapat berpindah karena bukan petak kosong!");
            *canmove = false;
        } 
    }
    else if(same(command, "SOUTH")){
        if(ElmtMap(*M, (int)Absis(S(*M))+2, (int)Ordinat(S(*M))+1) == ' '){
            Absis(S(*M))++;
            *canmove = true;
        }
        else{
            printf("Tidak dapat berpindah karena bukan petak kosong!");
            *canmove = false;
        } 
    }
    else if(same(command, "EAST")){
        if(ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))+2) == ' '){
            Ordinat(S(*M))++;
            *canmove = true;
        }
        else{
            printf("Tidak dapat berpindah karena bukan petak kosong!");
            *canmove = false;
        } 
    }
    else if(same(command, "WEST")){
        if(ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))) == ' '){
            Ordinat(S(*M))--;
            *canmove = true;
        }
        else{
            printf("Tidak dapat berpindah karena bukan petak kosong!");
            *canmove = false;
        } 
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

void displayBuyable(ListStatik l, ListStatik *buylist, MAP M){
    int length = lengthList(l);
    int ctr = 1;
    for(int i = 0; i < length; i++){
        if(getAction(ACTION(ELMTLIST(l,i)), M) == 'T'){
            printf("   %d. %s (",ctr,NAME(ELMTLIST(l,i)));
            TulisTIME2(DELIVERY(ELMTLIST(l,i)));
            printf(")\n");

            ELMTLIST(*buylist,ctr-1) = ELMTLIST(l,i);
            ctr++;
        }
    }
    printf("\nKirim 0 untuk exit.\n");
}

void displayCookMethod(ListStatik l, ListStatik *methodlist, char action, MAP M){
    int length = lengthList(l);
    int ctr = 1;
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    for(int i = 0; i < length; i++){
        if(getAction(ACTION(ELMTLIST(l,i)), M) == action){
            printf("   %d. %s ",ctr,NAME(ELMTLIST(l,i)));
            TulisTIME2(DELIVERY(ELMTLIST(l,i)));

            ELMTLIST(*methodlist,ctr-1) = ELMTLIST(l,i);
            ctr++;
        }
    }
    printf("\nKirim 0 untuk exit.\n");
}


int move_detector(Word command){
/* Mengembalikan nilai base dari command move */
/* Prekondisi: command move terdefinisi dan tidak kosong */
    if(same(command, "WEST")){
        return 1;
    }
    else if(same(command, "SOUTH")){
        return 2;
    }
    else if(same(command, "EAST")){
        return 3;
    }
    else if(same(command, "NORTH")){
        return 4;
    }
    else{
        return 0;
    }
}

void isDeliveredQueue(PrioQueue *I, PrioQueue *D, STOCK *stk, boolean *delivered, Word *makanan){
    infotypePrioQueue val;
    if (!IsEmpty(*D)){
        for (int i = Head(*D); i <= Tail(*D); i++) {
            if(isDelivered(Elmt(*D, i))){
                Dequeue(D, &val);
                EnqueueExpired(I, val);
                ELMTSTOCK(*stk, ID(val))++;
                *delivered = true;
            }
        }
    }
    *makanan = NAME(val); 
}

void isExpiredQueue(PrioQueue *I, STOCK *stk, boolean *expired, Word *makanan){
    infotypePrioQueue val;
    if (!IsEmpty(*I)){
        for (int i = Head(*I); i <= Tail(*I); i++) {
            if(isExpired(Elmt(*I, i))){
                Dequeue(I, &val);
                ELMTSTOCK(*stk, ID(val))--;
                *expired = true;
            }
        }
    }
    *makanan = NAME(val);
}


