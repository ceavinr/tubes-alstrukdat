/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "../../boolean.h"

typedef struct
{
   int X; /* absis   */
   int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */

/* Membentuk sebuah POINT dari komponen-komponennya */
POINT MakePOINT(int X, int Y);

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void BacaPOINT(POINT *P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
void TulisPOINT(POINT P);

/* *** Kelompok operasi relasional terhadap POINT *** */

/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean EQ(POINT P1, POINT P2);

/* *** Kelompok menentukan di mana P berada *** */

/* Menghasilkan true jika P adalah titik origin */
boolean IsOrigin(POINT P);
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbX(POINT P);
/* Menghasilkan true jika P terletak pada sumbu Y */
boolean IsOnSbY(POINT P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
int Kuadran(POINT P);

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */

/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT PlusDelta(POINT P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void Geser(POINT *P, int deltaX, int deltaY);
/* Menghitung jarak P ke (0,0) */
float Jarak0(POINT P);
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
float Panjang(POINT P1, POINT P2);

#endif