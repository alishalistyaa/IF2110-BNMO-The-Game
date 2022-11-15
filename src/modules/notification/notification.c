#include "notification.h"

void addWord(Notif *N, Word Kata, int tipeMode){
    /* Fungsi Menambah Kata pada WORDLIST */
    /* Tipe Mode berdasarkan jenisnya 
    1 -> notifInventory
    2 -> notifKedaluarsa
    3 -> notif UndoRedo */
    int i = 0;
    CreateMarkWord();
    if(tipeMode == 1){
        while(!same(MARKWORDLIST, ELMTWORDLIST(NOTIFINV(*N), i).TabWord && i != CAPACITYWORDLIST)){
            ELMTWORDLIST(NOTIFINV(*N), i+1) = Kata;
            i++;
        }
    } else if(tipeMode == 2){
        while(!same(MARKWORDLIST, ELMTWORDLIST(NOTIFEXP(*N), i).TabWord && i != CAPACITYWORDLIST)){
            ELMTWORDLIST(NOTIFEXP(*N), i+1) = Kata;
            i++;
        }

    } else if(tipeMode == 3){
        while(!same(MARKWORDLIST, ELMTWORDLIST(NOTIFUNDOREDO(*N), i).TabWord && i != CAPACITYWORDLIST)){
            ELMTWORDLIST(NOTIFUNDOREDO(*N), i+1) = Kata;
            i++;
        }
    }
}

void printNotifDelivery(Notif N){
    /* Fungsi mencetak ke layar*/
    int l;
    l = lengthWordList(NOTIFINV(N));
    for(int i=0; i<l; i++){
        printf("- %s sudah diterima oleh BNMO!\n", ELMTWORDLIST(NOTIFINV(N), i));
    }
}

void printNotifExpired(Notif N){
    /* Fungsi mencetak ke layar*/
    int l;
    l = lengthWordList(NOTIFEXP(N));
    for(int i=0; i<l; i++){
        printf("- %s kedaluwarsa...\n", ELMTWORDLIST(NOTIFEXP(N), i));
    }
}
void printNotifUndoAction(Notif N){
    /* Fungsi mencetak ke layar*/
    int l;
    l = lengthWordList(NOTIFUNDOREDO(N));
    for(int i=0; i<l; i++){
        printf("- Pembuatan %s dibatalkan.\n", ELMTWORDLIST(NOTIFUNDOREDO(N), i));
    }    
}

void printNotifUndoWaktu(Notif N){
    /* Fungsi mencetak ke layar*/
    int l;
    l = lengthWordList(NOTIFUNDOREDO(N));
    for(int i=0; i<l; i++){
        printf("- %s .\n", ELMTWORDLIST(NOTIFUNDOREDO(N), i));
    }     
}

void printallnotif(Notif N){
    printNotifUndoWaktu(N);
    printNotifUndoAction(N);
    printNotifExpired(N);
    printNotifDelivery(N);
}

// void printNotif(Word command, Word makanan) {
//     // PEMBATALAN ACTION
//     if (same(command, "FRY")) {
//         printf("Penggorengan ");
//         printf("%s ", makanan);
//         printf("dibatalkan\n");
//     } 
//     if (same(command, "CHOP")) {
//         printf("Pemotongan ");
//         printf("%s ", makanan);
//         printf("dibatalkan\n");
//     } 
//     if (same(command, "BOIL")) {
//         printf("Perebusan ");
//         printf("%s ", makanan);
//         printf("dibatalkan\n");
//     } 
//     if (same(command, "MIX")) {
//         printf("%d. ");
//         printf("%s ", makanan);
//         printf("dibatalkan\n");
//     } 

//     // Delivery Done
//     if (same(command, "DELIVERY")) {
//         printf("%d. ");
//         printf("%s ", makanan);
//         printf("sudah diterima oleh BNMO!\n");
//     }

//     // Kadaluwarsa
//     if (same(command, "EXPIRED")) {
//         printf("%s ", makanan);
//         printf("kedaluwarsa...\n");
//     }
// }