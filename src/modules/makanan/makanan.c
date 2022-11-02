/* File: makanan.c */
/* Implementasi Makanan */

#include "makanan.h"
#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../wordmachine/wordmachine.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */


/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateMakanan(MAKANAN *M, int ID, char *Name, TIME Expired, POINT Action, TIME Delivery){
    /* Membentuk sebuah MAKANAN dari komponen-komponen yang valid */
    /* Prekondisi*/
    ID(*M) = ID;
    NAME(*M) = Name;
    EXPIRED(*M) = Expired;
    ACTION(*M) = Action;
    DELIVERY(*M) = Delivery;
}


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ConfigMakanan (MAKANAN *M, Word filename);
/* Membaca file figurasi config dan membaca makanan */
/* I.S. List terdefinisi  */
/* F.S. */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
void DecreaseExpired(MAKANAN *M){
    /* Mengurangi waktu expired */
    // Algoritma
    // PrevMenit(EXPIRED(*M));
}

void IncreaseDelivery(MAKANAN *M);
/* Menambah waktu delivery */

boolean isExpired(MAKANAN M){ 
    /* Mengirimkan true jika makanan sudah expired */
    return (Day(EXPIRED(M)) == 0 && Hour(EXPIRED(M)) == 0 && Minute(EXPIRED(M)));
}

boolean isDelivered(MAKANAN M){
    /* Mengirimkan true jika makanan sudah dikirimkan */
    return(Day(DELIVERY(M)) == 0 && Hour(DELIVERY(M)) == 0 && Minute(DELIVERY(M)));
}

boolean isDeliveryEqual(MAKANAN M1, MAKANAN M2){
    /* Mengirimkan true jika Delivery M1 = Delivery M2 */
    return ((Day(DELIVERY(M1)) == Day(DELIVERY(M2))) && (Hour(DELIVERY(M1)) == Hour(DELIVERY(M2))) && (Minute(DELIVERY(M1)) == Minute(DELIVERY(M2))));
}

boolean isDeliveryLonger(MAKANAN M1, MAKANAN M2){
    /* Mengirimkan true jika Delivery M1 > Delivery M2 */
    // Kamus Lokal
    boolean isLonger;

    // Algoritma
    isLonger = false;
    if (Day(DELIVERY(M1)) > Day(DELIVERY(M2))) {
        isLonger = true;
    } else if (Hour(DELIVERY(M1)) > Hour(DELIVERY(M2))){
        isLonger = true;
    } else if (Minute(DELIVERY(M1)) > Minute(DELIVERY(M2))){
        isLonger = true;
    }

    return(isLonger);
}

boolean isExpiredEqual(MAKANAN M1, MAKANAN M2){
    /* Mengirimkan true jika Expired M1 = Expired M2 */
    return ((Day(EXPIRED(M1)) == Day(EXPIRED(M2))) && (Hour(EXPIRED(M1)) == Hour(EXPIRED(M2))) && (Minute(EXPIRED(M1)) == Minute(EXPIRED(M2))));
}

boolean isExpiredLonger(MAKANAN M1, MAKANAN M2){
    /* Mengirimkan true jika Expired M1 > Expired M2 */
    // Kamus Lokal
    boolean isLonger;

    // Algoritma
    isLonger = false;
    if (Day(EXPIRED(M1)) > Day(EXPIRED(M2))) {
        isLonger = true;
    } else if (Hour(EXPIRED(M1)) > Hour(EXPIRED(M2))){
        isLonger = true;
    } else if (Minute(EXPIRED(M1)) > Minute(EXPIRED(M2))){
        isLonger = true;
    }

    return(isLonger);

}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
