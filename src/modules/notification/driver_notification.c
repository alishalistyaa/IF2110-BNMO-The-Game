#include "notification.c"
#include "../wordmachine/wordmachine.c"

int main() {
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
    printNotif(command, makanan);

}