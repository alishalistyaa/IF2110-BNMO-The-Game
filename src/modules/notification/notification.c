#include "notification.h"

// void printNotifInventory(Notif N){
//     int l;
//     l = 3;
//     for(int i=0; i<l; i++){
//         printf("- %s kedaluwarsa...\n", N.notifKedaluarsa[i]);
//     }
// }

/* Fungsi mencetak ke layar*/


void printNotifUndo(Notif N);
/* Fungsi mencetak ke layar*/

void printNotifRedo(Notif N);
/* Fungsi mencetak ke layar*/

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