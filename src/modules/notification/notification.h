#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "../wordmachine/wordmachine.h"

typedef struct {
    WordList notifInventory;    // list word makanan inventory
    WordList notifKedaluarsa;   // list word makanan kedaluarsa
    WordList notifUndoRedo;     // aksi, argumen dibatalkan
} Notif;

void addWord(Notif *N, Word Kata, int tipeMode);
/* Fungsi Menambah Kata pada WORDLIST */
/* Tipe Mode berdasarkan jenisnya 
1 -> notifInventory
2 -> notifKedaluarsa
3 -> notif UndoRedo */

void printNotifInventory(Notif N);
/* Fungsi mencetak ke layar*/

void printNotifUndo(Notif N);
/* Fungsi mencetak ke layar*/

void printNotifRedo(Notif N);
/* Fungsi mencetak ke layar*/

#endif