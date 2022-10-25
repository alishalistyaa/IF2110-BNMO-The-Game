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
	Word Nama;          /* WORD Nama Makanan */
	TIME Kedaluarsa;    /* TIME <HH:MM:SS> Waktu Kadaluarsa */
    POINT Aksi;         /* POINT <x,y> Lokasi Aksi */   
    TIME LamaKirim;     /* TIME <HH:MM:SS> Lama Kirim Makanan */    
} MAKANAN;

/* *** Notasi Akses: selektor MAKANAN *** */
#define ID(M) (M).ID
#define Nama(M) (M).Nama
#define Kedaluarsa(M) (M).Kedaluarsa
#define Aksi(M) (M).Aksi
#define LamaKirim(M) (M).LamaKirim

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

#endif