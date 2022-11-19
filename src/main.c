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
#include "./modules/splash_screen/splash_screen.c"

// VARIABEL
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
    List_Link notifParser;

    /* ALGORITMA */
    // Inisialisasi Game
    
    start = true;
    boolean delivered;
    boolean expired;
    boolean validinput;
    boolean moveable;
    option = -1;
    // Variable Main
    char* filename;
    char* curName;
    Word buffer_word_makanan;
    infotypePrioQueue buffer_makanan;
    // PROGRAM MULAI
        // Splash Screen 
        print_ss_static();
        printf("\n");
        
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
        // Simulator
        Word command = currentWord;
        // printf("%s\n", command);
        CreateTime(&curTime, 0, 0, 0);
        CreatePoint(&curLoc, 0, 0);
        MakeEmpty(&curInv, 100);
        MakeEmpty(&curDeliv, 50);
        CreateStock(&curStock);
        CreateSimulator(&BNMO, "test", curLoc, curInv, curTime);
        // PETA
        MAP peta;
        createMap(&peta);
        // List Makanan
        ListStatik listMakanan;
        CreateListStatik(&listMakanan); 
        // Resep
        BukuResep bookRsp;
        // List Pengolahan dan Buy
        CreateListStatik(&buylist);
        CreateListStatik(&frylist);
        CreateListStatik(&boillist);
        CreateListStatik(&choplist);
        CreateListStatik(&mixlist);
        // Inisialisasi array of word
        Word undocommand[10];
        Word makanancommand[10];
        int count_undocommand = 0;
        // Undo-Redo
        CreateEmpty(&undo);
        CreateEmpty(&redo);

        // infotype X;
  
        // X.command = command;
        // X.I = curInv;
        // X.D = curDeliv;
        // X.T = curTime;
        // X.l = curLoc;
        // X.stock = curStock;
        // Top(undo) = 0;
        // InfoTop(undo) = X;

        // printf("%d",IsEmptyStack(undo));
        updateState(command, curInv, curDeliv, curStock, curTime, curLoc, &undo);
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
            normalizeFilename(filename);
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
        printf("\nFile konfigurasi telah selesai dibaca\n");
        boolean start = true;  
     
        while (start){
            curLoc = Location(SIMULATOR(peta));
            printf("\n\n");
            printf("BNMO di posisi: ");
            TulisPOINT(curLoc);
            printf("\n");
            printf("Waktu: ");
            TulisTIME1(curTime);
            printf("\n");
            printAllNotif(&Notification(BNMO));
            // if (same(command, "UNDO")) { 
            //     // printf("masi diperbaiki");   
            //     // printNotif(InfoTop(undo));
            // } else {
            //     printf("Notifikasi: -\n");
            // }
            printMap(peta);
            printf("Enter command: ");
            STARTWORDBlank();
            command = currentWord;
            inputCom1 = commandToInt(currentWord);
            inputCom2 = -1;
            inputCom3 = -1;
            validinput = true;
            switch (inputCom1)
            {
            case 1:
                if(isNear(peta,'M')){
                while (option != 0)
                    {
                    printf("======================\n");
                    printf("         MIX          \n");
                    printf("======================\n");
                    // BOIL HERE
                    displayCookMethod(listMakanan,&mixlist,'M',peta);
                    printf("\nEnter Command: ");
                    STARTWORDBlank();
                    option = transformToInt(currentWord);
                    if(option != 0 && option <= lengthList(mixlist)){
                                int ID_Root = ID(ELMTLIST(mixlist,option-1));
                                boolean bisamix = isResepOlahable(bookRsp,ID_Root,curStock);
                                Resep rsp = getResep(bookRsp,ID_Root);
                                MAKANAN hasil = getMakanan(listMakanan,ID_Root);

                                if(bisamix){
                                printf("%s selesai dibuat dan sudah masuk ke inventory!",NAME(ELMTLIST(mixlist,option-1)));
                                ELMTSTOCK(curStock,ID_Root)++;
                                    
                                    EnqueueExpired(&curInv,hasil);
                                    for(int i = 0; i < nChild(rsp); i++){
                                        delElmt(&curInv, Root(getChild(rsp,i)), &buffer_makanan);
                                        ELMTSTOCK(curStock,Root(getChild(rsp,i)))--;
                                    }
                                    
                                }
                                else{
                                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n",NAME(hasil).TabWord);
                                printBahanMissing(rsp,curStock,listMakanan);
                                printf("\n");
                                }
                    }
                    else if(option > lengthList(mixlist)) printf("Input invalid! ");
                    
                    }
                    option = -1;
                    passTime(&BNMO, 1, &curTime);

                } else printf("\nBNMO tidak berada di area mix (M)!\n");
                
                break;

            case 2:
                if(isNear(peta,'C')){
                 while (option != 0)
                    {
                    printf("======================\n");
                    printf("         CHOP         \n");
                    printf("======================\n");
                    displayCookMethod(listMakanan,&choplist,'C',peta);
                    printf("\nEnter Command: ");
                    STARTWORDBlank();
                    option = transformToInt(currentWord);
                    if(option != 0 && option <= lengthList(choplist)){
                                int ID_Root = ID(ELMTLIST(choplist,option-1));
                                boolean bisachop = isResepOlahable(bookRsp,ID_Root,curStock);
                                Resep rsp = getResep(bookRsp,ID_Root);
                                MAKANAN hasil = getMakanan(listMakanan,ID_Root);
                                if(bisachop){
    
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n",NAME(ELMTLIST(choplist,option-1)));
                                    //TO DO: kurangin stock bahan
                                    ELMTSTOCK(curStock,ID_Root)++;
                                    
                                    EnqueueExpired(&curInv,hasil);
                                    for(int i = 0; i < nChild(rsp); i++){
                                        delElmt(&curInv, Root(getChild(rsp,i)), &buffer_makanan);
                                        ELMTSTOCK(curStock,Root(getChild(rsp,i)))--;
                                    }
                                }
                                else{
                                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n",NAME(hasil).TabWord);
                                printBahanMissing(rsp,curStock,listMakanan);
                                printf("\n");
                                } 
                            }
                        else if(option > lengthList(choplist)) printf("Input invalid! ");
                        
                    }
                    
                    option = -1;
                    displayStock(curStock,listMakanan);
                    passTime(&BNMO, 1, &curTime);

                } else printf("\nBNMO tidak berada di area chop (C)!\n");
                break;

            case 3:
                if(isNear(peta,'F')){
                
                while (option != 0)
                    {
                    printf("======================\n");
                    printf("         FRY          \n");
                    printf("======================\n");
                    displayCookMethod(listMakanan,&frylist,'F',peta);
                    printf("\nEnter Command: ");
                    STARTWORDBlank();
                    option = transformToInt(currentWord);
                    if(option != 0 && option <= lengthList(frylist)){
                                int ID_Root = ID(ELMTLIST(frylist,option-1));
                                boolean bisafry = isResepOlahable(bookRsp,ID_Root,curStock);
                                Resep rsp = getResep(bookRsp,ID_Root);
                                MAKANAN hasil = getMakanan(listMakanan,ID_Root);
                                if(bisafry){
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n",NAME(ELMTLIST(frylist,option-1)));
                                    ELMTSTOCK(curStock,ID_Root)++;
                                    
                                    EnqueueExpired(&curInv,hasil);
                                    for(int i = 0; i < nChild(rsp); i++){
                                        delElmt(&curInv, Root(getChild(rsp,i)), &buffer_makanan);
                                        ELMTSTOCK(curStock,Root(getChild(rsp,i)))--;
                                    }
                                }
                                else{
                                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n",NAME(hasil).TabWord);
                                printBahanMissing(rsp,curStock,listMakanan);
                                printf("\n");
                                }          
                            }
                        else if(option > lengthList(frylist)) printf("Input invalid! ");
                    }
                    option = -1;
                    passTime(&BNMO, 1, &curTime);
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
                    displayCookMethod(listMakanan,&boillist,'B',peta);
                    printf("\nEnter Command: ");
                    STARTWORDBlank();
                    option = transformToInt(currentWord);
                    if(option != 0 && option <= lengthList(boillist)){
                                int ID_Root = ID(ELMTLIST(boillist,option-1));
                                boolean bisaboil = isResepOlahable(bookRsp,ID_Root,curStock);
                                Resep rsp = getResep(bookRsp,ID_Root);
                                MAKANAN hasil = getMakanan(listMakanan,ID_Root);
                                if(bisaboil){
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n",NAME(ELMTLIST(boillist,option-1)));
                                    ELMTSTOCK(curStock,ID_Root)++;
                                    
                                    EnqueueExpired(&curInv,hasil);
                                    for(int i = 0; i < nChild(rsp); i++){
                                        delElmt(&curInv, Root(getChild(rsp,i)), &buffer_makanan);
                                        ELMTSTOCK(curStock,Root(getChild(rsp,i)))--;
                                    }
                                    
                                }
                                else{
                                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n",NAME(hasil).TabWord);
                                printBahanMissing(rsp,curStock,listMakanan);
                                printf("\n");
                                }          
                            }
                        else if(option > lengthList(boillist)) printf("Input invalid! ");
                    }
                    option = -1;
                    passTime(&BNMO, 1, &curTime);
                
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
                        displayBuyable(listMakanan,&buylist,peta);
                        int lenBuyList = lengthList(buylist);
                        printf("\nEnter Command: ");
                        STARTWORDBlank();
                        option = transformToInt(currentWord);
                        if(option != 0 && option <= lenBuyList){
                            printf("\n\nBerhasil memesan %s. %s akan diantar dalam ",NAME(ELMTLIST(buylist,option-1)).TabWord,NAME(ELMTLIST(buylist,option-1)).TabWord);
                            TulisTIME2(DELIVERY(ELMTLIST(buylist,option-1)));
                            printf(".\n");

                            EnqueueDelivery(&curDeliv,ELMTLIST(buylist,option-1));
                        }
                    }
                    option = -1;
                    passTime(&BNMO, 1, &curTime);
                } else printf("\nBNMO tidak berada di area telepon (T)!\n");
                break;
            case 6:
                ADVWORDBlank();
                if ((same(currentWord, "EAST") ||
                    same(currentWord, "WEST") ||
                    same(currentWord, "SOUTH") ||
                    same(currentWord, "NORTH")) && (currentChar == '\n')) {
                        move_map(&peta, currentWord,&moveable);  
                        if(moveable) passTime(&BNMO, 1, &curTime);
                }   else {
                    printf("Input tidak valid! Coba lagi!\n");
                    validinput = false;
                }
                break;
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
                                    decreaseTimeDelivery(&curDeliv,plusMinute);
                                    

                                    delivered = false;
                                    expired = false;
                                    isDeliveredQueue(&curInv, &curDeliv, &curStock, &delivered, &buffer_word_makanan);
                                    // if (delivered) {
                                    //     undocommand[count_undocommand].Length = 8;
                                    //     undocommand[count_undocommand].TabWord[0] = 'D'; 
                                    //     undocommand[count_undocommand].TabWord[1] = 'E';
                                    //     undocommand[count_undocommand].TabWord[2] = 'L';
                                    //     undocommand[count_undocommand].TabWord[3] = 'I';
                                    //     undocommand[count_undocommand].TabWord[4] = 'V';
                                    //     undocommand[count_undocommand].TabWord[5] = 'E';
                                    //     undocommand[count_undocommand].TabWord[6] = 'R';
                                    //     undocommand[count_undocommand].TabWord[7] = 'Y';
                                    //     makanancommand[count_undocommand] = buffer_word_makanan;
                                    //     count_undocommand++;
                                    // }
                                    decreaseTimeExpired(&curInv,plusMinute);
                                    isExpiredQueue(&curInv, &curStock, &expired, &buffer_word_makanan);
                                    //     if (expired) {
                                    //         undocommand[count_undocommand].Length = 7;
                                    //         undocommand[count_undocommand].TabWord[0] = 'E'; 
                                    //         undocommand[count_undocommand].TabWord[1] = 'X';
                                    //         undocommand[count_undocommand].TabWord[2] = 'P';
                                    //         undocommand[count_undocommand].TabWord[3] = 'I';
                                    //         undocommand[count_undocommand].TabWord[4] = 'R';
                                    //         undocommand[count_undocommand].TabWord[5] = 'E';
                                    //         undocommand[count_undocommand].TabWord[6] = 'D';
                                    //         makanancommand[count_undocommand] = buffer_word_makanan;
                                    //         count_undocommand++;
                                    // }

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
                updateState(command, curInv, curDeliv, curStock, curTime, Location(SIMULATOR(peta)), &undo);
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
                if (IsEmptyStack(undo)) {
                    printf("Tidak ada yang bisa di-undo!\n");
                } else{
                    // printf("Go here\n");
                    STOCK tempStock = curStock;    
                    undocommand[count_undocommand] = InfoTop(undo).command;  
                    Undo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &(Location(SIMULATOR(peta))));
                    // STOCK tempStockUndo = curStock;
                    // int theID = -1;
                    // for (int i = 0; i < CAPACITY; i++) {
                    //     if(ELMTSTOCK(tempStockUndo, i) - ELMTSTOCK(tempStock, i) == 1); theID = i;       
                    // }
                    // makanancommand[count_undocommand] = getNameMakanan(listMakanan, theID);
                    // count_undocommand++;
                }
                break;
            case 12:
                printf("======================\n");
                printf("          REDO        \n");
                printf("======================\n");
                if (IsEmptyStack(redo)) {
                    printf("Tidak ada yang bisa di-redo!\n");
                } else {
                    Redo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &(Location(SIMULATOR(peta))));
                }
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
                validinput = false;
                break;
            }

        if (!same(command, "UNDO") && !same(command, "REDO") && !same(command, "EXIT") && !same(command,"WAIT") && !same(command, "DELIVERY") && !same(command, "COOKBOOK") && !same(command, "INVENTORY") && validinput) {
            decreaseTimeDelivery(&curDeliv,1);
            decreaseTimeExpired(&curInv,1);
            delivered = false;
            expired = false;
            isDeliveredQueue(&curInv, &curDeliv, &curStock, &delivered, &buffer_word_makanan);
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
                makanancommand[count_undocommand] = buffer_word_makanan;
                count_undocommand++;
            }
            isExpiredQueue(&curInv, &curStock, &expired, &buffer_word_makanan);
                if (expired) {
                    undocommand[count_undocommand].Length = 7;
                    undocommand[count_undocommand].TabWord[0] = 'E'; 
                    undocommand[count_undocommand].TabWord[1] = 'X';
                    undocommand[count_undocommand].TabWord[2] = 'P';
                    undocommand[count_undocommand].TabWord[3] = 'I';
                    undocommand[count_undocommand].TabWord[4] = 'R';
                    undocommand[count_undocommand].TabWord[5] = 'E';
                    undocommand[count_undocommand].TabWord[6] = 'D';
                    makanancommand[count_undocommand] = buffer_word_makanan;
                    count_undocommand++;
            }
                updateState(command, curInv, curDeliv, curStock, curTime, Location(SIMULATOR(peta)), &undo);
            }
        }
        //   if (!same(command, "UNDO") && !same(command, "REDO") && !same(command, "EXIT")) {
        //     decreaseTimeDelivery(&curDeliv);
        //     decreaseTimeExpired(&curInv);
        //     boolean delivered = false;
        //     boolean expired = false;
        //     Word makanan;
        //     isDeliveredQueue(&curInv, &curDeliv, &curStock, &delivered, &buffer_word_makanan);
        //     if (delivered) {
        //         undocommand[count_undocommand].Length = 8;
        //         undocommand[count_undocommand].TabWord[0] = 'D'; 
        //         undocommand[count_undocommand].TabWord[1] = 'E';
        //         undocommand[count_undocommand].TabWord[2] = 'L';
        //         undocommand[count_undocommand].TabWord[3] = 'I';
        //         undocommand[count_undocommand].TabWord[4] = 'V';
        //         undocommand[count_undocommand].TabWord[5] = 'E';
        //         undocommand[count_undocommand].TabWord[6] = 'R';
        //         undocommand[count_undocommand].TabWord[7] = 'Y';
        //         makanancommand[count_undocommand] = makanan;
        //         count_undocommand++;
        //     }
        //     isExpiredQueue(&curInv, &curStock, &expired, &buffer_word_makanan);
        //         if (expired) {
        //             undocommand[count_undocommand].Length = 7;
        //             undocommand[count_undocommand].TabWord[0] = 'E'; 
        //             undocommand[count_undocommand].TabWord[1] = 'X';
        //             undocommand[count_undocommand].TabWord[2] = 'P';
        //             undocommand[count_undocommand].TabWord[3] = 'I';
        //             undocommand[count_undocommand].TabWord[4] = 'R';
        //             undocommand[count_undocommand].TabWord[5] = 'E';
        //             undocommand[count_undocommand].TabWord[6] = 'D';
        //             makanancommand[count_undocommand] = makanan;
        //             count_undocommand++;
        //     }
        // }
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