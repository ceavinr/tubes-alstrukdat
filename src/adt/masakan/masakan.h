#ifndef __MASAKAN_H__
#define __MASAKAN_H__

#include "../../boolean.h"
#include "../string/string.h"

#define Nil -1
typedef struct
{
    int nomor;
    string nama;
    int durasi;
    int ketahanan;
    int harga;
} Masakan;

#define NOMOR(m) (m).nomor
#define NAMA(m) (m).nama
#define DURASI(m) (m).durasi
#define KETAHANAN(m) (m).ketahanan
#define HARGA(m) (m).harga

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah m terbentuk dengan nilai durasi, ketahanan, dan harga random */
/* Proses : Membuat sebuah masakan */
void CreateMasakanRandom(Masakan *m, int nomor);

/* Membuat sebuah masakan dengan NOMOR(m) = Nil, DURASI(m) = Nil, KETAHANAN(m) = Nil, HARGA(m) = Nil */
Masakan CreateMasakan();

/* *** Selektor SET : Mengubah nilai masakan *** */

/* Proses: Mengeset nilai m menjadi val */
/* I.S. m terdefinisi, sembarang */
/* F.S. m berisi salinan dari val */
void copyMasakan(Masakan *m, Masakan val);

/* Proses: Menampilkan m */
/* I.S. m terdefinisi, sembarang */
/* F.S. Menampilkan nomor, nama, durasi, ketahanan, harga dari m */
void DisplayMasakan(Masakan m);

#endif