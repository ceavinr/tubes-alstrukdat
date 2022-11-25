#ifndef __STACK_HISTORY__
#define __STACK_HISTORY__

#include "../../boolean.h"
#include "../mesin/mesinkata.h"

#define NilHistory -1
#define MaxElHistory 100
/* Nil adalah stack dengan elemen kosong . */

typedef Word infotypeHistory;
typedef int addressHistory; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
        infotypeHistory T[MaxElHistory]; /* tabel penyimpan elemen */
        addressHistory TOP;       /* alamat TOP: elemen puncak */
} StackHistory;
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
void CreateStackHistory(StackHistory *S);

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackHistoryEmpty(StackHistory S);

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsStackHistoryFull(StackHistory S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushHistory(StackHistory *S, infotypeHistory X);

/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopHistory(StackHistory *S, infotypeHistory *X);

/* Fungsi yang melakukan inverse dari S kemudian mengembalikan hasil inverse */
void InverseStackHistory(StackHistory *S);

/* ************ Mengcopy sebuah Stack ************ */
/* I.S. S2  tidak mungkin kosong */
/* F.S. Melakukan copy elemen dari S2 ke S1 */
void CopyStackHistory(StackHistory *S1, StackHistory S2);

/* ************ Menampilkan Isi Stack ************ */
/* I.S. S  tidak mungkin kosong, banyak merupakan jumlah elemen yang ditampilkan */
/* F.S. Menampilkan elemen dari S */
void PrintStackHistory(StackHistory S, int banyak);

#endif