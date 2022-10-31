/* File: makanan.h */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean/boolean.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../wordmachine/wordmachine.h"

/* *** Definisi TYPE MAKANAN *** */
typedef struct { 
	int ID;             /* integer [0... ] ID */
	char *Name;          /* WORD Nama Makanan */
	TIME Expired;    /* TIME <HH:MM:SS> Waktu Kadaluarsa */
    POINT Action;         /* POINT <x,y> Lokasi Aksi */   
    TIME Delivery;     /* TIME <HH:MM:SS> Lama Kirim Makanan */    
} MAKANAN;

/* *** Notasi Akses: selektor MAKANAN *** */
#define ID(M) (M).ID
#define NAME(M) (M).Name
#define EXPIRED(M) (M).Expired
#define ACTION(M) (M).Action
#define DELIVERY(M) (M).Delivery

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */


/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateMakanan(MAKANAN *M, int ID, char* Name, TIME Expired, POINT Action, TIME Delivery);
/* Membentuk sebuah MAKANAN dari komponen-komponen yang valid */
/* Prekondisi*/

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
void DecreaseExpired(MAKANAN *M);
/* Mengurangi waktu expired */
void IncreaseDelivery(MAKANAN *M);
/* Menambah waktu delivery */

boolean isExpired(MAKANAN M);
/* Mengirimkan true jika makanan sudah expired */
boolean isDelivered(MAKANAN M);
/* Mengirimkan true jika makanan sudah dikirimkan */

boolean isDeliveryEqual(MAKANAN M1, MAKANAN M2);
/* Mengirimkan true jika Delivery M1 = Delivery M2 */
boolean isDeliveryLonger(MAKANAN M1, MAKANAN M2);
/* Mengirimkan true jika Delivery M1 > Delivery M2 */
boolean isExpiredEqual(MAKANAN M1, MAKANAN M2);
/* Mengirimkan true jika Expired M1 = Expired M2 */
boolean isExpiredLonger(MAKANAN M1, MAKANAN M2);
/* Mengirimkan true jika Expired M1 > Expired M2 */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

#endif