#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q)
{
    return (((IDX_TAIL(q) + 1) % CAPACITY) == IDX_HEAD(q));
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q)
{
    if (!isEmpty(q))
    {
        if (IDX_TAIL(q) > IDX_HEAD(q))
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
        else
        {
            return (CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q)) + 1);
        }
    }
    else
    {
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
    if (!isEmpty(*q))
    {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    else
    {
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
    }
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val)
{
    *val = HEAD(*q);
    if (length(*q) == 1)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        printf("[%d,", HEAD(q));
        for (int i = 1; i < length(q) - 1; ++i)
        {
            printf("%d,", q.buffer[(IDX_HEAD(q) + i) % CAPACITY]);
        }
        printf("%d]\n", TAIL(q));
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
