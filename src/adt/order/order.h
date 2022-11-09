/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef ORDER_H
#define ORDER_H

#include "../../boolean.h"

#define IDX_UNDEF -1
#define ORDERCAPACITY 20
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

/* I.S. sembarang */
/* F.S. Sebuah o kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah o kosong */
void CreateOrder(Order *o);
/* I.S. sembarang */
/* F.S. Sebuah m terbentuk dengan nilai durasi, ketahanan, dan harga random */
/* Proses : Melakukan alokasi, membuat sebuah m */
void CreateMasakan(Masakan *m, KeyType nomor);

/* ********* Prototype ********* */

/* Mengirim true jika o kosong */
boolean isEmpty(Order o);
/* Mengirim true jika tabel penampung elemen o sudah penuh */
boolean isFull(Order o);

/* *** Banyaknya elemen *** */

/* Mengirimkan banyaknya elemen Order. Mengirimkan 0 jika o kosong. */
int orderLength(Order o);

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan val pada o dengan aturan FIFO */
/* I.S. o mungkin kosong, tabel penampung elemen o TIDAK penuh */
/* F.S. val dimasukan ke dalam o sedemikian sehingga key terurut membesar, IDX_TAIL bertambah. */
void addOrder(Order *o, Masakan val);
/* Proses: Menghapus val pada o dengan aturan FIFO */
/* I.S. o tidak mungkin kosong */
/* F.S. val = nilai elemen yang didelete, IDX_TAIL berkurang 1;
        o mungkin kosong */
void deleteOrderAt(Order *o, Masakan *val, KeyType key);

/* *** Find *** */

/* Melakukan pencarian pada order berdasarkan key (nomor masakan), jika ditemukan akan mereturn index dari masakan yang ditemukan. Jika tidak mereturn IDX_UNDEF */
int indexOf(Order o, KeyType key);
/* Melakukan pencarian pada order berdasarkan key (nomor masakan), jika ditemukan akan mereturn Masakan yang ditemukan. Masakan dipastikan terdapat pada order */
Masakan find(Order o, KeyType key);
/* Melakukan pengecekan berdasarkan key apakah sebuah masakan terdapat masakan dalam sebuah order */
boolean isIn(Order o, KeyType key);

/* *** Selektor SET : Mengubah nilai masakan *** */

/* Proses: Mengeset nilai m menjadi val */
/* I.S. m terdefinisi, sembarang */
/* F.S. m berisi salinan dari val */
void copyMasakan(Masakan *m, Masakan val);

#endif