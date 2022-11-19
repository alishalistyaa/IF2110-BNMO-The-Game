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
#include "./modules/set/set.c"

//UNCOMMENT COMMAND DI BAWAH APABILA DIJALANKAN TANPA FILE .c NYA
// #include "./modules/boolean/boolean.h"
// #include "./modules/wordmachine/wordmachine.h"
// #include "./modules/charmachine/charmachine.h"
// #include "./modules/list/liststatik.h"
// #include "./modules/makanan/makanan.h"
// #include "./modules/matriks/matriks.h"
// #include "./modules/point/point.h"
// // #include "./modules/queue/queue.h"
// #include "./modules/prioqueue/prioqueue.h"
// #include "./modules/stack/stack.h"
// #include "./modules/time/time.h"
// #include "./modules/tree/tree.h"
// #include "./modules/i_o/i_o.h"
// #include "./modules/building/building.h"
// #include "./modules/simulator/simulator.h"
// #include "./modules/map/map.h"
// #include "./modules/resep/resep.h"
// #include "./modules/notification/notification.h"
// #include "./modules/set/set.h"


// VARIABEL
Word currentWord;
boolean endWord;
char currentChar;


int main(){
    /* KAMUS */
    boolean start;
    boolean isUndo;
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
    Word delivery;
    Word expiredword;
    Word buffer_word_makanan;
    Word buffer_command_before;
    infotypePrioQueue buffer_makanan;
    // PROGRAM MULAI
        // Splash Screen 
        // print_ss_dinamic("./utils/BMNOframes_Start");
        printf("\n");
        
            printf( 
                "     /\\ \\        /\\__\\       /\\__\\       /\\  \\    \n"
                "    /::\\  \\     /::|  |       /::|  |       /::\\  \\   \n"
                "   /:/\\:\\ \\   /:|:|  |      /:|:|  |      /:/\\:\\ \\  \n"
                "  /::\\~\\:\\__\\/:/|:| |__   /:/|:|__|__   /:/  \\:\\ \\ \n"
                " /:/\\:\\\\:|__| /:/ |:| /\\__\\ /:/|::::\\__\\/:/__/\\:\\__\\ \n"
                " \\:\\~\\:\\/://\\/__|:|/:/ / \\/__/~~/:/  / \\:\\ \\ /:/ /\n"
                "  \\:\\ \\::/  /     |:/:/ /         /:/  /   \\:\\  /:/ / \n"
                "   \\:\\/:/  /      |::/  /         /:/  /     \\:\\/:/ /  \n"
                "    \\::/__/        /:/  /         /:/  /       \\::/  /   \n"
                "     ~~            \\/__/         \\/__/         \\/__/    \n"
             );

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
        createListLink(&notifParser);
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
        
        // Undo-Redo
        CreateEmpty(&undo);
        CreateEmpty(&redo);

        
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
            normalizeFilename(&currentWord);
            filename = currentWord.TabWord;
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
            printAllNotif(&notifParser, &isUndo);
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
                                printf("%s selesai dibuat dan sudah masuk ke inventory!\n\n",NAME(ELMTLIST(mixlist,option-1)));
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
    
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n\n",NAME(ELMTLIST(choplist,option-1)));
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
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n\n",NAME(ELMTLIST(frylist,option-1)));
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
                                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n\n",NAME(ELMTLIST(boillist,option-1)));
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
                                   if (delivered) {
                                        delivery.Length = 8;
                                        delivery.TabWord[0] = 'D'; 
                                        delivery.TabWord[1] = 'E';
                                        delivery.TabWord[2] = 'L';
                                        delivery.TabWord[3] = 'I';
                                        delivery.TabWord[4] = 'V';
                                        delivery.TabWord[5] = 'E';
                                        delivery.TabWord[6] = 'R';
                                        delivery.TabWord[7] = 'Y';
                                        insertFirst(&notifParser, delivery, buffer_word_makanan);
                                    }
                                    decreaseTimeExpired(&curInv,plusMinute);
                                    isExpiredQueue(&curInv, &curStock, &expired, &buffer_word_makanan);
                                    if (expired) {
                                        expiredword.Length = 7;
                                        expiredword.TabWord[0] = 'E'; 
                                        expiredword.TabWord[1] = 'X';
                                        expiredword.TabWord[2] = 'P';
                                        expiredword.TabWord[3] = 'I';
                                        expiredword.TabWord[4] = 'R';
                                        expiredword.TabWord[5] = 'E';
                                        expiredword.TabWord[6] = 'D';
                                        insertFirst(&notifParser, expiredword, buffer_word_makanan);                    
                                    }

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
                    // CreateStock(&tempStock);
                    isUndo = true;
                    STOCK tempStock = curStock;
                    Word command_before = InfoTop(undo).command;
                    Undo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &(Location(SIMULATOR(peta))));
                    STOCK tempStockUndo = curStock;
                    int theID = -1;
                    for (int i = 0; i < CAPACITY; i++) {
                        if((ELMTSTOCK(tempStock, i) - ELMTSTOCK(tempStockUndo, i)) == 1){
                             theID = i;}
                    }
                    buffer_word_makanan = getNameMakanan(listMakanan, theID);
                    if (delivered) {
                        delivery.Length = 8;
                        delivery.TabWord[0] = 'D'; 
                        delivery.TabWord[1] = 'E';
                        delivery.TabWord[2] = 'L';
                        delivery.TabWord[3] = 'I';
                        delivery.TabWord[4] = 'V';
                        delivery.TabWord[5] = 'E';
                        delivery.TabWord[6] = 'R';
                        delivery.TabWord[7] = 'Y';
                        insertFirst(&notifParser, delivery, buffer_word_makanan);
                    }
                    if (expired) {
                        expiredword.Length = 7;
                        expiredword.TabWord[0] = 'E'; 
                        expiredword.TabWord[1] = 'X';
                        expiredword.TabWord[2] = 'P';
                        expiredword.TabWord[3] = 'I';
                        expiredword.TabWord[4] = 'R';
                        expiredword.TabWord[5] = 'E';
                        expiredword.TabWord[6] = 'D';
                        insertFirst(&notifParser, expiredword, buffer_word_makanan);
                    }
                    if (!same(command_before, "MOVE") && !same(command_before, "WAIT")) {
                        insertFirst(&notifParser, command_before, buffer_word_makanan);
                    }
                }
                break;
            case 12:
                printf("======================\n");
                printf("          REDO        \n");
                printf("======================\n");
                if (IsEmptyStack(redo)) {
                    printf("Tidak ada yang bisa di-redo!\n");
                } else {
                    STOCK tempStock = curStock;
                    TIME before = curTime;
                    PrioQueue curDelivbefore = curDeliv;
                    PrioQueue curInventorybefore = curInv;
                    Redo(&undo, &redo, &command, &curInv, &curDeliv, &curStock, &curTime, &(Location(SIMULATOR(peta))));
                    TIME after = curTime;
                    TIME gap;
                    gap.DD = Day(after) - Day(before);
                    gap.HH = Hour(after) - Hour(before);
                    gap.MM = Minute(after) - Minute(before);
                    int gap_menit = TIMEToMenit(gap);
                    decreaseTimeDelivery(&curDelivbefore, gap_menit);
                    decreaseTimeExpired(&curInventorybefore, gap_menit);
                    delivered = false;
                    expired = false;
                    isDeliveredQueue(&curInventorybefore, &curDelivbefore, &curStock, &delivered, &buffer_word_makanan);
                    if (delivered) {
                        delivery.Length = 8;
                        delivery.TabWord[0] = 'D'; 
                        delivery.TabWord[1] = 'E';
                        delivery.TabWord[2] = 'L';
                        delivery.TabWord[3] = 'I';
                        delivery.TabWord[4] = 'V';
                        delivery.TabWord[5] = 'E';
                        delivery.TabWord[6] = 'R';
                        delivery.TabWord[7] = 'Y';
                        insertFirst(&notifParser, delivery, buffer_word_makanan);
                    }
                    isExpiredQueue(&curInventorybefore, &curStock, &expired, &buffer_word_makanan);
                    if (expired) {
                        expiredword.Length = 7;
                        expiredword.TabWord[0] = 'E'; 
                        expiredword.TabWord[1] = 'X';
                        expiredword.TabWord[2] = 'P';
                        expiredword.TabWord[3] = 'I';
                        expiredword.TabWord[4] = 'R';
                        expiredword.TabWord[5] = 'E';
                        expiredword.TabWord[6] = 'D';
                        insertFirst(&notifParser, expiredword, buffer_word_makanan);                    
                    }
                    if (!same(command, "WAIT")) {
                        STOCK tempStockRedo = curStock;
                        int theID = -1;
                        displayStock(tempStock, listMakanan);
                        displayStock(tempStockRedo, listMakanan);
                        for (int i = 0; i < CAPACITY; i++) {
                            if((ELMTSTOCK(tempStockRedo, i) - ELMTSTOCK(tempStock, i)) == 1){
                                theID = i;}
                        }
                        buffer_word_makanan = getNameMakanan(listMakanan, theID);
                        insertFirst(&notifParser, command, buffer_word_makanan);
                    }
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
                    "14. REKOMEN_MAKANAN   | Melihat rekomendasi makanan berdasarkan barang yang ada di inventory\n"
                    );
                break;

            case 15:
                printf("Game berhenti\n");
                start = false;
                break;
            case 16:
                /*
                *******************************************************************
                *******************************************************************
                *******************************************************************
                ---------------------- BONUS 3 ------------------------------------
                *******************************************************************
                *******************************************************************
                *******************************************************************
                */
                printf("");
                SET stokk = StockToSet(curStock);
                
                if(isEmptySet(stokk)){
                    printf("Stok Inventory Kosong!\n");
                }
                else{
                    SET listrkm = ListRekomen(stokk,bookRsp);
                    if (isEmptySet(listrkm)) printf("Tidak dapat membuat makanan apapun! kekurangan bahan!\n");
                    else{
                        printf("======================\n");
                        printf(" REKOMENDASI MAKANAN \n");
                        printf("======================\n");
                        printListRekomen(listrkm,listMakanan);
                    } 
                }  
                break;
                

                break;
            default:
                printf("\nInput tidak valid! Coba lagi!\n");
                validinput = false;
                break;
            }

        if (!same(command, "UNDO") && !same(command, "REDO") && !same(command, "EXIT") && !same(command,"WAIT") && !same(command, "DELIVERY") && !same(command, "COOKBOOK") && !same(command, "INVENTORY") && validinput && !same(command,"REKOMEN_MAKANAN")) {
            decreaseTimeDelivery(&curDeliv,1);
            decreaseTimeExpired(&curInv,1);
            delivered = false;
            expired = false;
            isDeliveredQueue(&curInv, &curDeliv, &curStock, &delivered, &buffer_word_makanan);
            if (delivered) {
                delivery.Length = 8;
                delivery.TabWord[0] = 'D'; 
                delivery.TabWord[1] = 'E';
                delivery.TabWord[2] = 'L';
                delivery.TabWord[3] = 'I';
                delivery.TabWord[4] = 'V';
                delivery.TabWord[5] = 'E';
                delivery.TabWord[6] = 'R';
                delivery.TabWord[7] = 'Y';
                insertFirst(&notifParser, delivery, buffer_word_makanan);
            }
            isExpiredQueue(&curInv, &curStock, &expired, &buffer_word_makanan);
            if (expired) {
                expiredword.Length = 7;
                expiredword.TabWord[0] = 'E'; 
                expiredword.TabWord[1] = 'X';
                expiredword.TabWord[2] = 'P';
                expiredword.TabWord[3] = 'I';
                expiredword.TabWord[4] = 'R';
                expiredword.TabWord[5] = 'E';
                expiredword.TabWord[6] = 'D';
                insertFirst(&notifParser, expiredword, buffer_word_makanan);                    
            }
                updateState(command, curInv, curDeliv, curStock, curTime, Location(SIMULATOR(peta)), &undo);
            }
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