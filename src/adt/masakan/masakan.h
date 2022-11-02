/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef MASAKAN_H
#define MASAKAN_H

#include "../../boolean.h"
#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct
{
    int nomor;
    int durasi;
    int ketahanan;
    int harga;
} Masakan;

#define NOMOR(m) (m).nomor
#define DURASI(m) (m).durasi
#define KETAHANAN(m) (m).ketahanan
#define HARGA(m) (m).harga

/* *** Kreator *** */
void CreateMasakan(Masakan *m, int nomor);
/* I.S. sembarang */
/* F.S. Sebuah m terbentuk dengan nilai durasi, ketahanan, dan harga random */
/* Proses : Melakukan alokasi, membuat sebuah m */

/* ********* Predikat ********* */
boolean isFinished(Masakan m);
/* Mengirim true jika m sudah selesai diproses */

/* *** Set *** */
void copyMasakan(Masakan *m, Masakan val);
/* Proses: Mengeset nilai m menjadi val */
/* I.S. m sembarang */
/* F.S. m = val */

/* *** Find *** */
#endif