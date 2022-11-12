#include <stdio.h>
#include <stdlib.h>

#include "./modules/boolean/boolean.h"
#include "./modules/wordmachine/wordmachine.c"
#include "./modules/charmachine/charmachine.c"
#include "./modules/list/liststatik.c"
#include "./modules/makanan/makanan.c"
#include "./modules/map/map.c"
#include "./modules/matriks/matriks.c"
#include "./modules/point/point.c"
// #include "./modules/queue/queue.c"
#include "./modules/prioqueue/prioqueue.c"
#include "./modules/simulator/simulator.c"
#include "./modules/stack/stack.c"
#include "./modules/time/time.c"
// #include "./modules/tree/tree.c"
#include "./modules/i_o/i_o.c"
#include "./modules/building/building.c"

Word currentWord;
boolean endWord;

int main(){
    /* KAMUS */
    boolean start;
    int inputCom1;
    int inputCom2;
    int inputCom3;
    MAP map;
    TIME wait;
    TIME curTime;
    POINT curLoc;
    PrioQueue curInv;
    SIMULATOR BNMO;

    /* ALGORITMA */
    // Inisialisasi Game
    start = true;
    // Variable Main
    char* filename;
    char* curName;
    // PROGRAM MULAI
        // Splash Screen 
    

    // COMMAND AWAL
    printf("1. START\n");
    printf("2. EXIT\n");
    // Read command
    printf("Enter command: ");
    STARTWORD();
    Word command = currentWord;
    if (same(currentWord, "START")) {
        // Variable to save the configuration
        printf("It should enter here\n");
        CreateTime(&curTime, 0, 0, 0);
        CreatePoint(&curLoc, 0, 0);
        MakeEmpty(&curInv, 10);
        CreateSimulator(&BNMO, curName, curLoc, curInv, curTime);
        Matrix peta;
        ListStatik listMakanan;
        // Reading all configuration
        int count = 0;
        do {
            printf("Pastikan file config sudah masuk ke folder config ya!\n");
            printf("Masukkan nama file config ");
            if (count == 0) {
                printf("peta: ");
            } else if (count == 1) {
                printf("resep: ");
            } else if (count == 2) {
                printf("makanan: ");
            }
            STARTWORD();
            filename = currentWord.TabWord;
            // printf("%s", filename);
            if (!isFileExist(filename)) {
                printf("Masukan file tidak valid!");
            } else {
                if (count == 0) {
                    // configMakanan(filename, &listMakanan);
                    printf("skip first\n");
                } else if (count == 1) {
                    configMap("peta.txt", &peta);
                } else if (count == 2) {
                    //configResep (filename, &resep);
                }
                count++;
            }
        }
        while (count < 2);
        printf("File konfigurasi telah selesai dibaca\n");

        boolean start = true;  
        boolean first = true;      
        while (start){
            printf("\n");
            printf("BNMO di posisi: ");
            TulisPOINT(curLoc);
            printf("\n");
            printf("Waktu: ");
            TulisTIME1(curTime);
            printf("\n");
            printf("Notifikasi: -\n");
            displayMatrix(peta);
            printf("Enter command: ");
            STARTWORD();
            inputCom1 = commandToInt(currentWord);
            inputCom2 = -1;
            inputCom3 = -1;

            switch (inputCom1)
            {
            case 1:
                printf("======================\n");
                printf("         MIX          \n");
                printf("======================\n");
            case 2:
                printf("======================\n");
                printf("         CHOP         \n");
                printf("======================\n");
            case 3:
                printf("======================\n");
                printf("         FRY          \n");
                printf("======================\n");
            case 4:
                printf("======================\n");
                printf("         BOIL         \n");
                printf("======================\n");
            case 5:
                printf("======================\n");
                printf("          BUY         \n");
                printf("======================\n");
            case 6:
                ADVWORD();
                inputCom2 = move_detection(currentWord);

                switch(inputCom2)
                {
                case 1:
                    ADVWORD();
                    if(currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        Word w;
                        w.Length=4;
                        w.TabWord[0]='W';
                        w.TabWord[1]='E';
                        w.TabWord[2]='S';
                        w.TabWord[3]='T';
                        move_map(&map, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                case 2:
                    ADVWORD();
                    if(currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        Word w;
                        w.Length=5;
                        w.TabWord[0]='S';
                        w.TabWord[1]='O';
                        w.TabWord[2]='U';
                        w.TabWord[3]='T';
                        w.TabWord[4]='H';
                        move_map(&map, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                case 3:
                    ADVWORD();
                    if(currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        Word w;
                        w.Length=4;
                        w.TabWord[0]='E';
                        w.TabWord[1]='A';
                        w.TabWord[2]='S';
                        w.TabWord[3]='T';
                        move_map(&map, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                case 4:
                    ADVWORD();
                    if(currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        Word w;
                        w.Length=5;
                        w.TabWord[0]='N';
                        w.TabWord[1]='O';
                        w.TabWord[2]='R';
                        w.TabWord[3]='T';
                        w.TabWord[4]='H';
                        move_map(&map, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                deafult:
                    printf("Input tidak valid\n");
                    break;
                }
            case 7:
                ADVWORD();
                if(currentWord.Length > 0){
                    inputCom2 = transformToInt(currentWord);
                    ADVWORD();
                    if(currentWord.Length > 0 && inputCom2 >= 0){
                        inputCom3 = transformToInt(currentWord);

                        ADVWORD();
                        if(currentWord.Length>0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            if(inputCom3 >= 0){
                                if(inputCom2 == 0 && inputCom3 == 0){
                                    printf("Input Waktu tidak valid\n");
                                } else {
                                    printf("Menunggu untuk %d jam, %d menit\n", inputCom2, inputCom3);
                                    CreateTime(&wait, 0, inputCom2, inputCom3);
                                    long plusMinute = TIMEToMenit(wait);
                                    passTime(&BNMO, plusMinute, &curTime);
                                }
                            }
                            else{
                                printf("Input Waktu tidak valid\n");
                            }
                        }
                    }
                    else{
                        printf("Input Waktu tidak valid\n");
                    }
                }
                else{
                    printf("Input Waktu tidak valid\n");
                }
            case 8:
                printf("======================\n");
                printf("        CATALOG       \n");
                printf("======================\n");
            case 9:
                printf("======================\n");
                printf("       INVENTORY      \n");
                printf("======================\n");
            case 10:
                printf("======================\n");
                printf("        DELIVERY      \n");
                printf("======================\n");
            case 11:
                printf("======================\n");
                printf("          UNDO        \n");
                printf("======================\n");
            case 12:
                printf("======================\n");
                printf("          REDO        \n");
                printf("======================\n");
            case 13:
                printf("======================\n");
                printf("        COOKBOOK      \n");
                printf("======================\n");
            default:
                break;
            }
        }

    } else if (same(currentWord, "EXIT")) {
        printf("Game berhenti\n");
    }  
}