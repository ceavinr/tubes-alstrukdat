#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
Queue MakeQueue()
{
    Queue q;
    IDX_HEAD(q) = IDX_UNDEF;
    IDX_TAIL(q) = IDX_UNDEF;

    return q;
}
/* Mengirimkan Queue kosong */

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong */
boolean isQueueFull(Queue q)
{
    return (IDX_TAIL(q) + 1 == QUEUECAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int queueLength(Queue q)
{
    if (!isQueueEmpty(q))
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
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
    if (isQueueEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
    }
    IDX_TAIL(*q) = IDX_TAIL(*q) + 1;

    CopyWord(&TAIL(*q), val);
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val)
{
    *val = HEAD(*q);
    for (int i = 0; i < queueLength(*q); i++)
    {
        CopyWord(&QUEUEELMT(*q, i), QUEUEELMT(*q, i + 1));
    }
    IDX_TAIL(*q) -= 1;

    if (queueLength(*q) == 0) {
        IDX_HEAD(*q) = IDX_UNDEF;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isQueueEmpty(q))
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else
    {
        int i;
        for (i = 0; i < queueLength(q); i++)
        {
            printf("%d. ", i + 1);
            int j;
            for (j = 0; j < QUEUEELMT(q, i).Length; j++)
            {
                printf("%c", QUEUEELMT(q, i).TabWord[j]);
            }
            printf("\n");
        }
    }
}
/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: Daftar Game
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */