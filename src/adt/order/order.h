/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef ORDER_H
#define ORDER_H

#include "../../boolean.h"
#include "../masakan/masakan.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct
{
    Masakan buffer[CAPACITY];
    int idxHead;
    int idxTail;
} Order;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]
#define ELMT(q, i) (q).buffer[i]

/* *** Kreator *** */
void CreateOrder(Order *o);
/* I.S. sembarang */
/* F.S. Sebuah o kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah o kosong */

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

void deleteOrder(Order *o, Masakan *val);
/* Proses: Menghapus val pada o dengan aturan FIFO */
/* I.S. o tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        o mungkin kosong */

/* *** Find *** */
Masakan find(Order o, int val);
/* Melakukan pencarian pada order berdasarkan nomor makanan, jika ditemukan akan mereturn index*/
boolean isIn(Order o, int val);

/* *** Display *** */
void displayOrder(Order o);
void displayCooking(Order o);
void displayReady(Order o);

#endif