#include <stdio.h>
#include <stdlib.h>

#include "./modules/boolean/boolean.h"
#include "./modules/charmachine/charmachine.h"
#include "./modules/list/liststatik.h"
#include "./modules/makanan/makanan.h"
#include "./modules/map/map.h"
#include "./modules/matriks/matriks.h"
#include "./modules/point/point.h"
#include "./modules/queue/queue.h"
#include "./modules/simulator/simulator.h"
#include "./modules/stack/stack.h"
#include "./modules/time/time.h"
#include "./modules/tree/tree.h"
#include "./modules/wordmachine/wordmachine.h"
// #include "./modules/i_o/i_o.c.h"

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
    char *command[3];
    // PROGRAM MULAI
    while (start){
        // Splash Screen 

        // COMMAND AWAL
        printf("1. START\n");
        printf("2. EXIT\n");
        // Read command
        STARTWORD();
        command[0] = currentWord.TabWord;
        if (same(command[0], "START")) {
            // Variable to save the configuration
            MAP peta;
            ListStatik listMakanan;
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
                scanf("%c", filename);
                if (!isFileExist(filename)) {
                    printf("Masukan file tidak valid!");
                } else {
                    if (count == 0) {
                        configMakanan(filename, &listMakanan);
                    } else if (count == 1) {
                        configMap(filename, &peta);
                    } else if (count == 2) {
                        //configResep (filename, &resep);
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

            updateState(command[0], M, T, );           // GAME MULAI
 
            boolean start1 = true;           while (start){1
                 //  Update data

                                // IF FINISHED STATE THEN START = FALSE

               
            }
 
        } else if (same(command[0], "EXIT")) {
            start = false;
        }   }
}