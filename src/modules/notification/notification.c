#include "notification.h"

printNotif(Word command, Word makanan) {
    // PEMBATALAN ACTION
    if (same(command, "FRY")) {
        printf("Penggorengan ");
        printf("%s ", makanan);
        printf("dibatalkan\n");
    } 
    if (same(command, "CHOP")) {
        printf("Pemotongan ");
        printf("%s ", makanan);
        printf("dibatalkan\n");
    } 
    if (same(command, "BOIL")) {
        printf("Perebusan ");
        printf("%s ", makanan);
        printf("dibatalkan\n");
    } 
    if (same(command, "MIX")) {
        printf("%d. ");
        printf("%s ", makanan);
        printf("dibatalkan\n");
    } 

    // Delivery Done
    if (same(command, "DELIVERY")) {
        printf("%d. ");
        printf("%s ", makanan);
        printf("sudah diterima oleh BNMO!\n");
    }

    // Kadaluwarsa
    if (same(command, "EXPIRED")) {
        printf("%s ", makanan);
        printf("kedaluwarsa...\n");
    }
}