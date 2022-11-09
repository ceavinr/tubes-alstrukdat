#ifndef ORDER_H
#define ORDER_H

#include "../../boolean.h"
#include "../masakan/masakan.h"

#define IDX_UNDEF -1
#define ORDERCAPACITY 25
typedef int KeyType;

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

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah o kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah o kosong */
void CreateOrder(Order *o);

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
void deleteOrder(Order *o, Masakan *val);

/* *** Find *** */

/* Melakukan pencarian pada order berdasarkan key (nomor masakan), jika ditemukan akan mereturn index dari masakan yang ditemukan pertama kali. Jika tidak mereturn IDX_UNDEF */
int indexOfOrder(Order o, KeyType key);
/* Melakukan pencarian pada order berdasarkan key (nomor masakan), jika ditemukan akan mereturn Masakan yang ditemukan. key dipastikan terdapat pada order */
Masakan findOrder(Order o, KeyType key);
/* Melakukan pengecekan berdasarkan key apakah sebuah masakan terdapat masakan dalam sebuah order */
boolean isIn(Order o, KeyType key);

#endif