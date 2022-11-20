#include "notification.h"
#include "../boolean/boolean.h"
#include "../simulator/simulator.h"
#include "../wordmachine/wordmachine.h"

int main() {
    Notif N;
    Word command, makanan;
    List_Link l;
    boolean isUndo = true;

    command.Length = 3;
    command.TabWord[0] = 'F';
    command.TabWord[1] = 'R';
    command.TabWord[2] = 'Y';

    makanan.Length = 4;
    makanan.TabWord[0] = 'A';
    makanan.TabWord[1] = 'Y';
    makanan.TabWord[2] = 'A';
    makanan.TabWord[3] = 'M';

    N = createNotif(command, makanan);
    createListLink(&l);
    insertFirst(&l, command, makanan);
    printAllNotif(&l, &isUndo);


}