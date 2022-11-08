#include <stdio.h>
#include "point.h"
#include <math.h>
#define PI 3.141592654

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){

    float x,y;

    scanf("%f %f",&x,&y);
    CreatePoint(P,x,y);
}

void TulisPOINT (POINT P){
    printf("(%.0f,%.0f)",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return (Absis(P1) == Absis(P2) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1) != Absis(P2) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P){
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    float x = Absis(P);
    float y = Ordinat(P);

    if(x > 0 && y > 0){
        return 1;
    }
    else if(x < 0 && y > 0){
        return 2;
    }
    else if(x < 0 && y < 0){
        return 3;
    }
    else{
        return 4;
    }
}

POINT NextX (POINT P){
    Absis(P) += 1;
    return P;
}

POINT NextY (POINT P){
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if(SbX){
        Ordinat(P) *= -1;
    }
    else{
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0 (POINT P){
    return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
    float dx = Absis(P1) - Absis(P2);
    float dy = Ordinat(P1) - Ordinat(P2);
    return sqrt(dx*dx + dy*dy);
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if(SbX){
        Ordinat(*P) *= -1;
    }
    else{
        Absis(*P) *= -1;
    }
}

void Putar (POINT *P, float Sudut){
    float tempX = Absis(*P);
    float tempY = Ordinat(*P);
    Sudut = Sudut * PI/180; //ubah ke radian
    Absis(*P) = cos(Sudut) * tempX - sin(Sudut) * tempY;
    Ordinat(*P) = sin(Sudut) * tempX + cos(Sudut) * tempY;

}
