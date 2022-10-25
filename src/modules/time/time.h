#ifndef TIME_H
#define TIME_H

#include "../boolean/boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int DD; /* integer [0... ] Hari */
	int HH; /* integer [0..23] Jam */
	int MM; /* integer [0..59] Menit */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M);
/* Mengirim true jika D, H, M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, HH, MM valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME1 (TIME * T);
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM sehingga menampilkan T pada console */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   1 23
   Jam tidak valid
   1 24
   --> akan terbentuk TIME <1,3,4> */
   
void BacaTIME2 (TIME * T);
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen DD, JJ, MM sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Waktu kedaluwarsa/delivery tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   0 2 1 (0 hari 2 jam 1 menit)
   Jam tidak valid
   1 3 4 (1 hari 3 jam 4 menit)
   --> akan terbentuk TIME <1,3,4> */

void TulisTIME1 (TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH.MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH.MM */

void TulisTIME2 (TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD hari HH jam MM menit */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD hari HH jam MM menit */
/* Untuk menampilkan waktu kedaluwarsa/sisa delivery */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2);
/* Mengirimkan true jika T1>T2, false jika tidak */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
/* *** Operator aritmatika TIME *** */
long TIMEToMenit (TIME T);
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
TIME MenitToTime (long N);
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
void NextMenit(TIME *T);
/* Mengirim T setelah satu menit */
void NextNMenit (TIME *T, int N);
/* Mengirim N menit setelah T dalam bentuk TIME */
void PrevMenit (TIME *T);
/* Mengirim 1 menit sebelum T dalam bentuk TIME */
void PrevNMenit (TIME *T, int N);
/* Mengirim N menit sebelum T dalam bentuk TIME */
void NextJamMenit (TIME *T, int x, int y);
/* Mengirim T setelah ditambah x jam dan y menit */


#endif