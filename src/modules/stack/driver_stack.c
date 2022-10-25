#include "stack.h"
#include <stdio.h>

boolean endWord;
Word currentWord;

int main () {
    Stack undo, redo;
    CreateEmpty(&undo);
    CreateEmpty(&redo);
    Word s, t, u, s1;
    s.TabWord[0] = 'B';
    s.TabWord[1] = 'U';
    s.TabWord[2] = 'Y';
    s.Length = 3;
    t.TabWord[0] = 'B';
    t.TabWord[1] = 'O';
    t.TabWord[2] = 'I';
    t.TabWord[3] = 'L';
    t.Length = 4;
    u.TabWord[0] = 'C';
    u.TabWord[1] = 'H';
    u.TabWord[2] = 'O';
    u.TabWord[3] = 'P';
    u.Length = 4;

    Push(&undo, s);
    Push(&undo, t);
    Push(&undo, u);

    /* Undo berisi 
    1. CHOP
    2. BOIL 
    3. BUY */
    printf("Pengecekkan undo-redo (push-pop)\n");
    Undo(&undo, &redo); /* Meng-undo CHOP */
    Undo(&undo, &redo); /* Meng-undo BOIL */
    Pop(&redo, &s1); /* Posisi teratas redo adalah BOIL */
    for (int i = 0; i < s1.Length; i++) {
        printf("%c", s1.TabWord[i]);
    }
    printf("\n");

    Redo(&undo, &redo);
    Pop(&undo, &s1); /* Posisi teratas undo adalah CHOP, karena BOIL telah ter-pop saat proses print */
    for (int i = 0; i < s1.Length; i++) {
        printf("%c", s1.TabWord[i]);
    }
    printf("\n");

/* Pengecekan operasi lain */
    printf("Pengecekkan operasi lain\n");
    printf("Print sisa undo\n");
    while (!IsEmpty(undo)) {
        Pop(&undo, &s1); 
        for (int i = 0; i < s1.Length; i++) {
            printf("%c", s1.TabWord[i]);
        }
        printf("\n");
    }

    printf("Print sisa redo\n");
    while (!IsEmpty(redo)) {
        Pop(&redo, &s1); 
        for (int i = 0; i < s1.Length; i++) {
            printf("%c", s1.TabWord[i]);
        }
        printf("\n");
    }
}