/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../../boolean.h"
#include "../word/word.h"

#define IDX_UNDEF -1
#define QUEUECAPACITY 100

/* Definisi elemen dan address */
typedef Word ElType;
typedef struct
{
    ElType buffer[QUEUECAPACITY];
    int idxHead;
    int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]
#define QUEUEELMT(q, i) (q).buffer[(i)]

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
Queue MakeQueue();

/* ********* Prototype ********* */

/* Mengirim true jika q kosong */
boolean isQueueEmpty(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
boolean isQueueFull(Queue q);

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int queueLength(Queue q);

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah 1. */
void enqueue(Queue *q, ElType val);

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD dan indeks dari elemen-elemen berkurang 1;
        q mungkin kosong */
void dequeue(Queue *q, ElType *val);

/* *** Display Queue *** */

/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
void displayQueue(Queue q);

#endif