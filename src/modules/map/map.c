#include <stdlib.h>
#include <stdio.h>
#include "map.h"


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
            ElmtMap(*M,i,j) = ' ';
        }
    }
    Absis(S(*M))=IDX_UNDEF;
    Ordinat(S(*M))=IDX_UNDEF;
}

void loadMap(MAP *M, char *filename)
/* I.S. map sembarang */
/* F.S. map terbentuk dari file eksternal */
{
    char *location;
    ADVFILE(filename);
    int i,j,ii,jj;
    int space;
    
    i = 1;
    j = 1;
    ii = 0;
    jj = 0;
    space = 0;
    while((currentChar >= '0' && currentChar <= '9') || currentChar == ' ')
    {
        if(space == 0){
            if(currentChar >= '0' && currentChar <= '9'){
                ii = ii*10 + (currentChar - '0');
            }
            else{
                space = 1;
            }
        }else{
            if(currentChar >= '0' && currentChar <= '9'){
                jj = jj*10 + (currentChar - '0');
            }
        }
        ADV();
    }

    for(i = 1; i <= ii; i++)
    {
        for(j = 1; j <= jj; j++)
        {
            if(currentChar == '\n'){
                ADV();
            }
            if(currentChar == 'S'){
                Absis(S(*M)) = i;
                Ordinat(S(*M)) = j;
            }
            ElmtMap(*M,i,j) = currentChar;
            ADV();
        }
        ADV();
    }
    ROW_MAP(*M) = ii;
    COL_MAP(*M) = jj;
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
    int i,j;
    for(i = 1; i <= ROW_MAP(M); i++)
    {
        for(j = 1; j <= COL_MAP(M); j++)
        {
            if(j!=0){
                printf(" ");
            }
            if(ElmtMap(M,i,j) == '#'){
                printf(" ");
            }else{
                printf("%c",ElmtMap(M,i,j));
            }
        }
        printf("\n");
    }
}

boolean isNear(MAP M, char ch)
/* Mengembalikan true jika ada bangunan dengan karakter ch yang berdekatan dengan bangunan lain */
{
    if(Absis(S(M)) != 0){
        if(ElmtMap(M, (int)Absis(S(M))-1, (int)Ordinat(S(M))) == ch){
            return true;
        }
    }

    if(Absis(S(M)) != ROW_MAP(M)){
        if(ElmtMap(M, (int)Absis(S(M))+1, (int)Ordinat(S(M))) == ch){
            return true;
        }
    }

    if(Ordinat(S(M)) != 0){
        if(ElmtMap(M, (int)Absis(S(M)), (int)Ordinat(S(M))-1) == ch){
            return true;
        }
    }

    if(Ordinat(S(M)) != COL_MAP(M)-1){
        if(ElmtMap(M, (int)Absis(S(M)), (int)Ordinat(S(M))+1) == ch){
            return true;
        }
    }

    return false;
}

void move_map(MAP *M, Word command)
/* I.S. map terdefinisi */
/* F.S. map bergerak sesuai dengan command */
{
    Word NORTH, SOUTH, EAST, WEST;
    NORTH.Length = 5;
    NORTH.TabWord[0] = 'N';
    NORTH.TabWord[1] = 'O';
    NORTH.TabWord[2] = 'R';
    NORTH.TabWord[3] = 'T';
    NORTH.TabWord[4] = 'H';
    SOUTH.Length = 5;
    SOUTH.TabWord[0] = 'S';
    SOUTH.TabWord[1] = 'O';
    SOUTH.TabWord[2] = 'U';
    SOUTH.TabWord[3] = 'T';
    SOUTH.TabWord[4] = 'H';
    EAST.Length = 4;
    EAST.TabWord[0] = 'E';
    EAST.TabWord[1] = 'A';
    EAST.TabWord[2] = 'S';
    EAST.TabWord[3] = 'T';
    WEST.Length = 4;
    WEST.TabWord[0] = 'W';
    WEST.TabWord[1] = 'E';
    WEST.TabWord[2] = 'S';
    WEST.TabWord[3] = 'T';

    if(isEqual(command, NORTH)){
        if(ElmtMap(*M, (int)Absis(S(*M))-1, (int)Ordinat(S(*M))) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M))-1, (int)Ordinat(S(*M))) = 'S';

            Absis(S(*M)) = Absis(S(*M)) - 1;
        }
    }
    else if(isEqual(command, SOUTH)){
        if(ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))) = 'S';

            Absis(S(*M)) = Absis(S(*M)) + 1;
        }
    }
    else if(isEqual(command, EAST)){
        if(ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))+1) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))+1) = 'S';

            Ordinat(S(*M)) = Ordinat(S(*M)) + 1;
        }
    }
    else if(isEqual(command, WEST)){
        if(ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))-1) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))-1) = 'S';

            Ordinat(S(*M)) = Ordinat(S(*M)) - 1;
        }
    }
}

void moveDirection(MAP *M, char direction)
/* I.S. map terdefinisi */
/* F.S. map bergerak sesuai dengan command */
{
    if(direction == 'w'){
        if(ElmtMap(*M, (int)Absis(S(*M))-1, (int)Ordinat(S(*M))) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M))-1, (int)Ordinat(S(*M))) = 'S';

            Absis(S(*M)) = Absis(S(*M)) - 1;
        }
    }
    else if(direction == 's'){
        if(ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M))+1, (int)Ordinat(S(*M))) = 'S';

            Absis(S(*M)) = Absis(S(*M)) + 1;
        }
    }
    else if(direction == 'd'){
        if(ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))+1) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))+1) = 'S';

            Ordinat(S(*M)) = Ordinat(S(*M)) + 1;
        }
    }
    else if(direction == 'a'){
        if(ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))-1) == '#'){
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))) = '#';
            ElmtMap(*M, (int)Absis(S(*M)), (int)Ordinat(S(*M))-1) = 'S';

            Ordinat(S(*M)) = Ordinat(S(*M)) - 1;
        }
    }
}