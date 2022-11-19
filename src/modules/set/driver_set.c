#include "set.c"
#include <stdio.h>

int main(){
    SET s1;
    createEmptySet(&s1);
    ELMTSET(s1,2) = true;
    ELMTSET(s1,4) = true;
    printSet(s1);
}