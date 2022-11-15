#include "notification.c"
#include "../wordmachine/wordmachine.c"

int main() {
    Notif N;
    Word command, makanan;
    command.Length = 3;
    command.TabWord[0] = 'F';
    command.TabWord[1] = 'R';
    command.TabWord[2] = 'Y';
    makanan.Length = 4;
    makanan.TabWord[0] = 'A';
    makanan.TabWord[1] = 'Y';
    makanan.TabWord[2] = 'A';
    makanan.TabWord[3] = 'M';

    WordList inv, exp, redo;
    CreateWordList(&inv);
    CreateWordList(&exp);
    CreateWordList(&redo);

    addWord(&N, command, 1);
    addWord(&N, makanan, 2);
    printallnotif(N);


}