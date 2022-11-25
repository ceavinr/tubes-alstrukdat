#ifndef STACK_H
#define STACK_H

#include "../../boolean.h"

#define Nil -1
#define MaxEl 9
/* Nil adalah stack dengan elemen kosong . */

typedef int infotypeStack;
typedef int addressStack; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
        infotypeStack T[MaxEl]; /* tabel penyimpan elemen */
        addressStack TOP;       /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
void CreateStack(Stack *S);

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsStackFull(Stack S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh. Succeed bernilai false */
/* F.S. Bila nilai elemen TOP lebih besar dari X, X menjadi TOP yang baru, TOP bertambah 1, succeed diubah menjadi true;
        Bila nilai elemen TOP lebih kecil dari X, succeed diubah menjadi false */
void Push(Stack *S, infotypeStack X, boolean *succeed);

/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus X dari Stack S. */
/* I.S. S mungkin kosong. Succeed bernilai false */
/* F.S. Bila tabel penampung elemen tidak kosong, X adalah nilai elemen TOP yang lama, TOP berkurang 1, succeed diubah menjadi true;
        Bila tabel penampung elemen kosong, succeed diubah menjadi false */
void Pop(Stack *S, infotypeStack *X, boolean *succeed);

#endif