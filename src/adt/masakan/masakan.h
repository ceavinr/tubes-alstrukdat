#ifndef __MASAKAN_H__
#define __MASAKAN_H__

#include "../../boolean.h"

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

/* I.S. sembarang */
/* F.S. Sebuah m terbentuk dengan nilai durasi, ketahanan, dan harga random */
/* Proses : Melakukan alokasi, membuat sebuah m */
void CreateMasakanRandom(Masakan *m, int nomor);

/* *** Selektor SET : Mengubah nilai masakan *** */

/* Proses: Mengeset nilai m menjadi val */
/* I.S. m terdefinisi, sembarang */
/* F.S. m berisi salinan dari val */
void copyMasakan(Masakan *m, Masakan val);

#endif