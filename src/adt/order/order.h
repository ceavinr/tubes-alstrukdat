/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef ORDER_H
#define ORDER_H

#include "../../boolean.h"

#define IDX_UNDEF -1
#define ORDERCAPACITY 20
/* Definisi elemen dan address */
typedef int KeyType;

typedef struct
{
    KeyType nomor;
    int durasi;
    int ketahanan;
    int harga;
} Masakan;

typedef struct
{
    Masakan buffer[ORDERCAPACITY];
    int idxHead;
    int idxTail;
} Order;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]
#define ORDERELMT(q, i) (q).buffer[i]

#define NOMOR(m) (m).nomor
#define DURASI(m) (m).durasi
#define KETAHANAN(m) (m).ketahanan
#define HARGA(m) (m).harga

/* *** Kreator *** */
void CreateOrder(Order *o);
/* I.S. sembarang */
/* F.S. Sebuah o kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah o kosong */

void CreateMasakan(Masakan *m, KeyType nomor);
/* I.S. sembarang */
/* F.S. Sebuah m terbentuk dengan nilai durasi, ketahanan, dan harga random */
/* Proses : Melakukan alokasi, membuat sebuah m */

/* ********* Prototype ********* */
boolean isEmpty(Order o);
/* Mengirim true jika o kosong */
boolean isFull(Order o);
/* Mengirim true jika tabel penampung elemen o sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar */

int length(Order o);
/* Mengirimkan banyaknya elemen Order. Mengirimkan 0 jika o kosong. */

/* *** Primitif Add/Delete *** */
void addOrder(Order *o, Masakan val);
/* Proses: Menambahkan val pada o dengan aturan FIFO */
/* I.S. o mungkin kosong, tabel penampung elemen o TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void deleteOrderAt(Order *o, Masakan *val, KeyType idx);
/* Proses: Menghapus val pada o dengan aturan FIFO */
/* I.S. o tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        o mungkin kosong */

/* *** Find *** */
int indexOf(Order o, int val);
Masakan find(Order o, int val);
/* Melakukan pencarian pada order berdasarkan nomor makanan, jika ditemukan akan mereturn index*/
boolean isIn(Order o, int val);

void copyMasakan(Masakan *m, Masakan val);
/* Proses: Mengeset nilai m menjadi val */
/* I.S. m sembarang */
/* F.S. m = val */

/* *** Display *** */
void displayOrder(Order o);
void displayCooking(Order o);
void displayReady(Order o);

#endif