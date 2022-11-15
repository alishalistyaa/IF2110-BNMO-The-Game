#include <stdio.h>
#include <stdlib.h>

#include "./modules/boolean/boolean.h"
#include "./modules/wordmachine/wordmachine.c"
#include "./modules/charmachine/charmachine.h"
#include "./modules/list/liststatik.c"
#include "./modules/makanan/makanan.c"
#include "./modules/matriks/matriks.c"
#include "./modules/point/point.c"
// #include "./modules/queue/queue.c"
#include "./modules/prioqueue/prioqueue.c"
#include "./modules/stack/stack.c"
#include "./modules/time/time.c"
#include "./modules/tree/tree.c"
#include "./modules/i_o/i_o.c"
#include "./modules/building/building.c"
#include "./modules/simulator/simulator.c"
#include "./modules/map/map.c"
#include "./modules/resep/resep.c"
#include "./modules/notification/notification.c"

Word currentWord;
boolean endWord;
char currentChar;

int main(){
    /* KAMUS */
    boolean start;
    int inputCom1;
    int inputCom2;
    int inputCom3;
    int option;
    TIME wait;
    TIME curTime;
    POINT curLoc;
    STOCK curStock;
    PrioQueue curInv;
    PrioQueue curDeliv;
    SIMULATOR BNMO;
    Stack undo;
    Stack redo;
    ListStatik buylist;
    ListStatik mixlist;
    ListStatik choplist;
    ListStatik boillist;
    ListStatik frylist;

    /* ALGORITMA */
    // Inisialisasi Game
    CreateListStatik(&buylist);
    start = true;
    option = -1;
    // Variable Main
    char* filename;
    char* curName;
    // PROGRAM MULAI
        // Splash Screen 
        // printf(
        //     "======================================================================================\n"
        //     "\n"
        //     "▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ░█▀▀█ ▒█▀▄▀█ ░█▀▀█ ▀▀█▀▀ 　 ▒█▀▀▄ ░█▀▀█ ▀▀█▀▀ ░█▀▀█ ▒█▄░▒█ ▒█▀▀█ \n"
        //     "░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▄▄█ ▒█▒█▒█ ▒█▄▄█ ░▒█░░ 　 ▒█░▒█ ▒█▄▄█ ░▒█░░ ▒█▄▄█ ▒█▒█▒█ ▒█░▄▄ \n"
        //     "▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█░▒█ ▒█░░▒█ ▒█░▒█ ░▒█░░ 　 ▒█▄▄▀ ▒█░▒█ ░▒█░░ ▒█░▒█ ▒█░░▀█ ▒█▄▄█ \n"
        //     "\n"
        //     "======================================================================================\n"
        //     );

    // COMMAND AWAL
    printf("1. START\n");
    printf("2. EXIT\n");
    // Read command
    printf("Enter command: ");
    STARTWORD();
    if (same(currentWord, "START")) {
        // Variable to save the configuration
        Word command = currentWord;
        // Simulator
        CreateTime(&curTime, 0, 0, 0);
        CreatePoint(&curLoc, 0, 0);
        MakeEmpty(&curInv, 100);
        MakeEmpty(&curDeliv, 50);
        CreateSimulator(&BNMO, "test", curLoc, curInv, curTime);
        // PETA
        MAP peta;
        createMap(&peta);
        // List Makanan
        ListStatik listMakanan;
        CreateListStatik(&listMakanan); 
        // Resep
        BukuResep bookRsp;
        // Inisialisasi array of word
        Word undocommand[10];
        Word makanancommand[10];
        int count_undocommand = 0;
        // Undo-Redo
        CreateEmpty(&undo);
        CreateEmpty(&redo);
        CreateStock(&curStock);
        updateState(command, curInv, curDeliv, curStock, curTime, curLoc, &undo);
        // Reading all configuration
        int count = 0;
        do {
            printf("\nPastikan file config sudah masuk ke folder config ya!\n");
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
                printf("Masukan file tidak valid!\n");
            } else {
                if (count == 0) {
                    loadMap(&peta,filename);
                }  else if (count == 1) {
                    configResep (filename, &bookRsp);
                }
                    else if (count == 2) {
                    configMakanan(peta, filename, &listMakanan);
                }
                count++;
            }
        }
        while (count < 3);
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
            if (same(command, "UNDO")) { 
                printf("masi diperbaiki");   
                // printNotif(InfoTop(undo));
            } else {
                printf("Notifikasi: -\n");
            }
            printMap(peta);
            printf("Enter command: ");
            STARTWORDBlank();
            command = currentWord;
            inputCom1 = commandToInt(currentWord);
            inputCom2 = -1;
            inputCom3 = -1;
            switch (inputCom1)
            {
            case 1:
                if(isNear(peta,'M')){
                printf("======================\n");
                printf("         MIX          \n");
                printf("======================\n");
                

                } else printf("\nBNMO tidak berada di area mix (M)!\n");
                
                break;

            case 2:
                if(isNear(peta,'C')){
                printf("======================\n");
                printf("         CHOP         \n");
                printf("======================\n");
                // CHOP HERE

                } else printf("\nBNMO tidak berada di area chop (C)!\n");
                break;

            case 3:
                if(isNear(peta,'F')){
                printf("======================\n");
                printf("         FRY          \n");
                printf("======================\n");
                // FRY HERE
                
                } else printf("\nBNMO tidak berada di area fry (F)!\n");
                break;

            case 4:
                if(isNear(peta,'B')){
                    while (option != 0)
                    {
                    printf("======================\n");
                    printf("         BOIL         \n");
                    printf("======================\n");
                    // BOIL HERE
                    displayCookMethod(listMakanan,&boillist,"Boil");
                    printf("\nEnter Command: ");
                    STARTWORDBlank();
                    option = transformToInt(currentWord);
                    if(option != 0){
                                int ID_Root = ID(ELMTLIST(buylist,option-1));
                                boolean bisaboil = isResepOlahable(bookRsp,ID_Root,curStock);
                                if(bisaboil){
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!",NAME(ELMTLIST(buylist,option-1)));
                                }
                            }
                    }
                    
                
                
                } else printf("\nBNMO tidak berada di area boil (B)!\n");
                break;
            case 5:
                if(isNear(peta,'T')){
                    while (option != 0)
                    {
                        printf("======================\n");
                        printf("         BUY          \n");
                        printf("======================\n");

                        // BUY HERE
                        displayBuyable(listMakanan,&buylist);
                        printf("\nEnter Command: ");
                        STARTWORDBlank();
                        option = transformToInt(currentWord);
                        if(option != 0){
                            printf("\n\nBerhasil memesan %s. %s akan diantar dalam ",NAME(ELMTLIST(buylist,option-1)).TabWord,NAME(ELMTLIST(buylist,option-1)).TabWord);
                            TulisTIME2(DELIVERY(ELMTLIST(buylist,option-1)));
                            printf(".\n");

                            EnqueueDelivery(&curDeliv,ELMTLIST(buylist,option-1));
                        }
                    }
                } else printf("\nBNMO tidak berada di area telepon (T)!\n");
                break;

            case 6:
                ADVWORDBlank();
                inputCom2 = move_detector(currentWord);

                switch(inputCom2)
                {
                case 1:
                    ADVWORDBlank();
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
                        move_map(&peta, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                    break;
                case 2:
                    ADVWORDBlank();
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
                        move_map(&peta, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                    break;
                case 3:
                    ADVWORDBlank();
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
                        move_map(&peta, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                    break;
                case 4:
                    ADVWORDBlank();
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
                        move_map(&peta, w);
                        passTime(&BNMO, 1, &curTime);
                    }
                    break;
                default:
                    printf("Arah tidak valid\n");
                    break;
                }
                break;
                // ADVWORDBlank();
                // if(currentChar == '\n'){
                //     move_map(&peta, currentWord);
                //     passTime(&BNMO, 1, &curTime);
                // } else {
                //     printf("Input berlebihan\n");
                // }
                // break;

            case 7:
                ADVWORDBlank();
                if(currentWord.Length > 0){
                    inputCom2 = transformToInt(currentWord);
                    ADVWORDBlank();
                    if(currentWord.Length > 0 && inputCom2 >= 0){
                        inputCom3 = transformToInt(currentWord);

                        ADVWORDBlank();
                        if(currentChar == '\n'){
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
                        else{
                            printf("Input berlebihan\n");
                            
                        }
                    }
                    else{
                        printf("Input Waktu tidak valid\n");
                    }
                }
                else{
                    printf("Input Waktu tidak valid\n");
                }
                break;

            case 8:
                printf("======================\n");
                printf("        CATALOG       \n");
                printf("======================\n");
                cetakCatalog(listMakanan, peta);
                break;

            case 9:
                printf("======================\n");
                printf("       INVENTORY      \n");
                printf("======================\n");
                printInventoryExpired(curInv);
                break;

            case 10:
                printf("======================\n");
                printf("        DELIVERY      \n");
                printf("======================\n");
                printInventoryDelivery(curDeliv);

                break;
            case 11:
                printf("======================\n");
                printf("          UNDO        \n");
                printf("======================\n");
                STOCK tempStock = curStock;    
                undocommand[count_undocommand] = command;            
                Undo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &curLoc);
                STOCK tempStockUndo = curStock;
                int theID = -1;
                CreateStock(&count);
                for (int i = 0; i < CAPACITY; i++) {
                    if(ELMTSTOCK(tempStockUndo, i) - ELMTSTOCK(tempStock, i) == 1); theID = i;       
                }
                makanancommand[count_undocommand] = getNameMakanan(listMakanan, theID);
                count_undocommand++;
                break;

            case 12:
                printf("======================\n");
                printf("          REDO        \n");
                printf("======================\n");
                Redo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &curLoc);
                break;

            case 13:
                printf("======================\n");
                printf("        COOKBOOK      \n");
                printf("======================\n");
                cetakBukuResep(bookRsp,listMakanan,peta);
                break;
            case 14:
                printf("======================\n");
                printf("          HELP        \n");
                printf("======================\n");
                printf(
                    "Berikut merupakan command yang bisa kamu lakukan!\n"
                    " 1. MOVE EAST  | Untuk berpindah satu langkah ke kiri\n"
                    " 2. MOVE WEST  | Untuk berpindah satu langkah ke kanan\n"
                    " 3. MOVE NORTH | Untuk berpindah satu langkah ke atas\n"
                    " 4. MOVE SOUTH | Untuk berpindah satu langkah ke bawah\n"
                    " 5. BUY        | Membeli bahan makanan   (Harus dekat lokasi T)\n"
                    " 6. MIX        | Mencampur bahan makanan (Harus dekat Lokasi M)\n"
                    " 7. BOIL       | Merebus makanan         (Harus dekat Lokasi B)\n"
                    " 8. CHOP       | Memotong makanan        (Harus dekat Lokasi C)\n"
                    " 9. FRY        | Menggoreng makanan      (Harus dekat Lokasi F)\n"
                    "10. CATALOG    | Melihat bahan dan makanan yang tersedia\n"
                    "11. COOKBOOK   | Melihat resep yang dapat dibuat \n"
                    "12. INVENTORY  | Melihat inventory \n"
                    "13. DELIVERY   | Melihat barang yang sedang diantar\n"
                    );
                break;

            case 15:
                printf("Game berhenti\n");
                start = false;
                break;
            default:
                printf("\nInput tidak valid! Coba lagi!\n");
                break;
            }
        }
        if (!same(command, "UNDO") && !same(command, "REDO")) {
            decreaseTimeDelivery(&curDeliv);
            decreaseTimeExpired(&curInv);
            boolean delivered = false;
            boolean expired = false;
            Word makanan;
            isDeliveredQueue(&curInv, &curDeliv, &delivered, &makanan);
            if (delivered) {
                undocommand[count_undocommand].Length = 8;
                undocommand[count_undocommand].TabWord[0] = 'D'; 
                undocommand[count_undocommand].TabWord[1] = 'E';
                undocommand[count_undocommand].TabWord[2] = 'L';
                undocommand[count_undocommand].TabWord[3] = 'I';
                undocommand[count_undocommand].TabWord[4] = 'V';
                undocommand[count_undocommand].TabWord[5] = 'E';
                undocommand[count_undocommand].TabWord[6] = 'R';
                undocommand[count_undocommand].TabWord[7] = 'Y';
                makanancommand[count_undocommand] = makanan;
                count_undocommand++;
            }
            isExpiredQueue(&curInv, &expired, &makanan);
                if (expired) {
                    undocommand[count_undocommand].Length = 7;
                    undocommand[count_undocommand].TabWord[0] = 'E'; 
                    undocommand[count_undocommand].TabWord[1] = 'X';
                    undocommand[count_undocommand].TabWord[2] = 'P';
                    undocommand[count_undocommand].TabWord[3] = 'I';
                    undocommand[count_undocommand].TabWord[4] = 'R';
                    undocommand[count_undocommand].TabWord[5] = 'E';
                    undocommand[count_undocommand].TabWord[6] = 'D';
                    makanancommand[count_undocommand] = makanan;
                    count_undocommand++;
            }
            updateState(command, curInv, curDeliv, curStock, curTime, curLoc, &undo);
        }
    } else if (same(currentWord, "EXIT")) {

        // printf(
        //     "\n"
        //     "======================================================================================\n"
        //     "\n"
        //     "                            █▀▀▄ █░░█ █▀▀ 　 █▀▀▄ █░░█ █▀▀ 　 ▄ ▄▀ \n"
        //     "                            █▀▀▄ █▄▄█ █▀▀ 　 █▀▀▄ █▄▄█ █▀▀ 　 ░ █░ \n"
        //     "                            ▀▀▀░ ▄▄▄█ ▀▀▀ 　 ▀▀▀░ ▄▄▄█ ▀▀▀ 　 ▀ ▀▄ \n"
        //     "\n"
        //     "======================================================================================\n"
        // );
    }  
}