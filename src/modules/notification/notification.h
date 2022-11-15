#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "../wordmachine/wordmachine.h"

typedef struct {
    WordList notifInventory;    // list word makanan inventory
    WordList notifKedaluarsa;   // list word makanan kedaluarsa
    WordList notifUndoRedo;     // aksi, argumen dibatalkan
} Notif;

/* SELEKTOR */
#define NOTIFINV(Notif) (Notif).notifInventory
#define NOTIFEXP(Notif) (Notif).notifKedaluarsa
#define NOTIFUNDOREDO(Notif) (Notif).notifUndoRedo

void addWord(Notif *N, Word Kata, int tipeMode);
/* Fungsi Menambah Kata pada WORDLIST */
/* Tipe Mode berdasarkan jenisnya 
1 -> notifInventory
2 -> notifKedaluarsa
3 -> notif UndoRedo */

void printNotifDelivery(Notif N);
    /* Fungsi mencetak ke layar*/

void printNotifExpired(Notif N);
    /* Fungsi mencetak ke layar*/

void printNotifUndoAction(Notif N);
    /* Fungsi mencetak ke layar*/

void printNotifUndoWaktu(Notif N);
    /* Fungsi mencetak ke layar*/

#endif