#include "time.h"
#include <stdio.h>


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M) {
/* Mengirim true jika D, H, M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return D >= 0 && H >= 0 && H <= 23 && M >= 0 && M <= 59;
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM) {
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, HH, MM valid untuk membentuk TIME */
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME1 (TIME * T) {
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
    int h, m;
    printf("Masukan waktu awal BNMO dimulai (jam dan menit): ");
    scanf("%d %d", &h, &m);
    while (!IsTIMEValid(0, h, m)) {
        printf("Jam tidak valid\n");
        printf("Masukan waktu awal BNMO dimulai (jam dan menit): ");
        scanf("%d %d", &h, &m);
    }
    CreateTime(T, 0, h, m);
}
   
void BacaTIMEKedaluwarsa (TIME * T) {
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
    int h, m, s;
    printf("Masukkan waktu kedaluwarsa: ");
    scanf("%d %d %d", &h, &m, &s);
    while (!IsTIMEValid(h, m, s)) {
        printf("Waktu kedaluwarsa tidak valid\n");
        printf("Masukkan waktu kedaluwarsa: ");
        scanf("%d %d %d", &h, &m, &s);
    }
    CreateTime(T, h, m, s);
}
void BacaTIMEDelivery (TIME * T) {
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
    int h, m, s;
    printf("Masukkan waktu sisa delivery: ");
    scanf("%d %d %d", &h, &m, &s);
    while (!IsTIMEValid(h, m, s)) {
        printf("Waktu sisa delivery tidak valid\n");
        printf("Masukkan waktu sisa delivery: ");
        scanf("%d %d %d", &h, &m, &s);
    }
    CreateTime(T, h, m, s);
}

void TulisTIME1 (TIME T) {
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH.MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH.MM */
    printf("%d.%02d", Hour(T), Minute(T));
}

void TulisTIME2 (TIME T) {
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD hari HH jam MM menit */
/* Proses : menulis nilai setiap komponen T ke layar dalam format D hari H jam M menit */
/* Untuk menampilkan waktu kedaluwarsa/sisa delivery */
    if (Day(T) != 0) {
        printf("%d hari", Day(T));
    } 
    if (Day(T) != 0 && Hour(T) != 0) {
        printf(" ");
    }
    if (Hour(T) != 0) {
        printf("%d jam", Hour(T));
    }
    if (Hour(T) != 0 && Minute(T) != 0) {
        printf(" ");
    }
    if (Minute(T) != 0) {
        printf("%d menit", Minute(T));
    }
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T) {
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
    return 1440 * Day(T) + 60 * Hour(T) + Minute(T);
} 

TIME MenitToTime (long N) {
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
    TIME T;
    int sisa;
    Day(T) = N / 1440;
    N = N % 1440;
    Hour(T) = N / 60;
    sisa = N % 60;
    Minute(T) = sisa;
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1=T2, false jika tidak */
    return Day(T1) == Day(T2) && Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2);
}
boolean TNEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1 tidak sama dengan T2 */
    return !TEQ(T1, T2);
} 
boolean TLT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1<T2, false jika tidak */
    return TIMEToMenit(T1) < TIMEToMenit(T2);
}
boolean TGT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1>T2, false jika tidak */
    return TIMEToMenit(T1) > TIMEToMenit(T2);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Operator aritmatika TIME *** */
void NextMenit(TIME *T) {
/* Mengirim T setelah ditambah satu menit */
    long minutes;
    minutes = TIMEToMenit(*T);
    minutes++;
    *T = MenitToTime(minutes); 
}

void NextNMenit (TIME *T, int N) {
/* Mengirim N menit setelah T dalam bentuk TIME */
    long minutes;
    minutes = TIMEToMenit(*T);
    minutes += N;
    *T = MenitToTime(minutes); 
}
void PrevMenit (TIME *T) {
/* Mengirim 1 menit sebelum T dalam bentuk TIME */
    long minutes;
    minutes = TIMEToMenit(*T);
    minutes--;
    *T = MenitToTime(minutes);
}

void PrevNMenit (TIME *T, int N) {
/* Mengirim N menit sebelum T dalam bentuk TIME */
    long minutes;
    minutes = TIMEToMenit(*T);
    minutes -= N;
    *T = MenitToTime(minutes);
}

void NextJamMenit (TIME *T, int x, int y) {
/* Mengirim T setelah ditambah x jam dan y menit */
    int m1, m2, hasil;
    m1 = x * 60 + y;
    m2 = TIMEToMenit(*T);
    hasil = m1 + m2;
    *T = MenitToTime(hasil);
}
