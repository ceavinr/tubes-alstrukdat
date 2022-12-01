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
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
void TulisPOINT(POINT P);

/* *** Kelompok operasi relasional terhadap POINT *** */

/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean EQ(POINT P1, POINT P2);

#endif