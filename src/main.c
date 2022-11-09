#include <stdio.h>
#include <stdlib.h>

#include "./modules/boolean/boolean.h"
#include "./modules/wordmachine/wordmachine.c"
#include "./modules/charmachine/charmachine.h"
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
#include "./modules/tree/tree.c"
#include "./modules/resep/resep.c"
#include "./modules/i_o/i_o.c"
#include "./modules/building/building.c"

Word currentWord;
boolean endWord;

int main(){
    /* KAMUS */
    boolean start;

    /* ALGORITMA */
    // Inisialisasi Game
    start = true;
    // Variable Main
    char* filename;
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
        MAP peta;
        ListStatik listMakanan;
        BukuResep bookRsp;
        // Reading all configuration
        int count = 0;
        do {
            printf("Pastikan file config sudah masuk ke folder config ya!\n");
            printf("Masukkan nama file config ");
            if (count == 0) {
                printf("makanan: ");
            } else if (count == 1) {
                printf("resep: ");
            } else if (count == 2) {
                printf("peta: ");
            }
            STARTWORD();
            filename = currentWord.TabWord;
            // printf("%s", filename);
            if (!isFileExist(filename)) {
                printf("Masukan file tidak valid!\n");
            } else {
                if (count == 0) {
                    // configMakanan(filename, &listMakanan);
                    printf("skip first\n");
                }  else if (count == 1) {
                    configResep (filename, &bookRsp);
                }
                    else if (count == 2) {
                    loadMap(&peta,filename);
                }
                count++;
            }

        }
        while (count < 3);
        printf("File konfigurasi telah selesai dibaca\n");
        // INISIALISASI SELURUH OBJECT DAN ADT
        // Posisi 
        SIMULATOR S;
        POINT P;
        CreatePoint(&P, 0, 0);
        // Waktu
        TIME T;
        BacaTIME1(&T);
        // Notifikasi 
        // Peta
        // Makanan
        MAKANAN M;
        // CreateMakanan(&M, 0, "Tahu", T, P, T);
        // Inventory
        PrioQueue I;
        MakeEmpty(&I, 100);
        // Enqueue(&I, M);
        // Simulator
        CreateSimulator(&S, "Coba", P, I);
        // CreateSimulator(SIMULATOR * S, nama, P, inventory)
        // GAME MULAI

        boolean start = true;  
        boolean first = true;      
        while (start){
            printf("BNMO di posisi: ");
            TulisPOINT(peta.sim.LOCATION);
            printf("\n");
            printf("Waktu: ");
            TulisTIME1(T);
            printf("\n");
            printf("Notifikasi: -\n");
            printMap(peta);
            printf("Enter command: ");
            STARTWORD();
            if(first) STARTWORD();
            printf("%s\n", currentWord);
            if (same(currentWord, "BUY")) {
                printf("test\n");
            }
            else if (same(currentWord, "EXIT")) {
                start = false;
            }
            
            else if (same(currentWord, "MOVE EAST")) {
                move_map(&peta, currentWord);
            }
            else if (same(currentWord, "MOVE WEST")) {
                move_map(&peta, currentWord);
            }
            else if (same(currentWord, "MOVE NORTH")) {
                move_map(&peta, currentWord);
            }
            else if (same(currentWord, "MOVE SOUTH")) {

                move_map(&peta, currentWord);
            }
            else if (same(currentWord, "MIX")) {
                printf("test\n");
            }
            else if (same(currentWord, "CHOP")) {
                printf("test\n");
            }
            else if (same(currentWord, "FRY")) {
                printf("test\n");
            }
            else if (same(currentWord, "BOIL")) {
                printf("test\n");
            }


            //KEADAAN SETELAH MELAKUKAN COMMAND

            first = false;
            NextMenit(&T);
        }

    } else if (same(currentWord, "EXIT")) {
        printf("Game berhenti\n");
    }  
}