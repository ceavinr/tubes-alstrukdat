#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
{
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S)
{
    return Top(S) == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X, boolean *succeed)
{
    if (IsStackEmpty(*S))
    {
        Top(*S) += 1;
        InfoTop(*S) = X;
        (*succeed) = true;
    }
    else
    {
        if (X < InfoTop(*S))
        {
            Top(*S) += 1;
            InfoTop(*S) = X;
            (*succeed) = true;
        }
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X, boolean *succeed)
{
    if (!IsStackEmpty(*S))
    {
        (*X) = InfoTop(*S);
        Top(*S) -= 1;
        (*succeed) = true;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
