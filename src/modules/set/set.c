#include "set.h"
#include <stdio.h>


void createEmptySet(SET* s){
    HEADSET(*s) = MARKEMPTYSET;
    for(int i = 0; i < CAPACITY; i++) ELMTSET(*s,i) = false;
}

boolean isEmptySet(SET s){
    boolean emp = false;
    for(int i = 0; i < CAPACITY; i++) emp |= ELMTSET(s,i);
    return !emp;
}


SET concatSet(SET s1, SET s2){
    SET s3;
    createEmptySet(&s3);
    for(int i = 0; i < CAPACITY; i++){
        ELMTSET(s3,i) = ELMTSET(s2,i) | ELMTSET(s1,i);
    }
    return s3;
}

boolean isSubset(SET s1, SET s2){
    boolean state = true;
    for(int i = 0; i < CAPACITY; i++){
        if(ELMTSET(s1,i) == 0 && ELMTSET(s2,i) == 1) state = false;
    }
    return state;
}

void printSet(SET s){
    printf("(");
    boolean first = true;
    for(int i = 0; i < CAPACITY; i++){
        if(ELMTSET(s,i) && first){
            printf("%d",i);
            first = false;
        }
        else if(ELMTSET(s,i) && !first) printf(",%d",i);
    }
    printf(")\n");
    
}