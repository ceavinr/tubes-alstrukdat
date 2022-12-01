/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan addressDP adalah pointer */
/* char adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../../boolean.h"
#include "../point/point.h"

/* Definisi Type Data */

typedef struct tElmtlistDP *addressDP;
typedef struct tElmtlistDP
{
	int info;
	addressDP next;
	addressDP prev;
	POINT Pos;
} ElmtListDP;

typedef struct
{
	addressDP First;
	addressDP Last;
} ListDP;

;

/* Definisi list : */
/* List kosong : First(L) = NULL dan Last(L) = NULL */
/* Setiap elemen dengan addressDP P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define Pos(P) (P)->Pos
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/

/* Mengirim true jika list kosong. Lihat definisi di atas. */
boolean IsEmptyDP(ListDP L);

/****************** PEMBUATAN ListDP KOSONG ******************/

/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
void CreateEmptyDP(ListDP *L);

/****************** Manajemen Memori ******************/

/* Mengirimkan addressDP hasil alokasi sebuah elemen */
<<<<<<< HEAD
/* Jika alokasi berhasil, maka addressDP tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
=======
/* Jika alokasi berhasil, maka addressDP tidak NULL. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NULL, Prev(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
>>>>>>> 4e1eb9fc3a4e4dc5268ac9bb26569dd5656e2ba0
addressDP AlokasiDP(int X);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressDP P */
void DealokasiDP(addressDP *P);

/****************** PENCARIAN SEBUAH ELEMEN ListDP ******************/

/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressDP elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
addressDP SearchPointDP(ListDP L, POINT X);

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressDP P sebagai elemen pertama */
void InsertFirstDP(ListDP *L, addressDP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLastDP(ListDP *L, addressDP P);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfterDP(ListDP *L, addressDP P, addressDP Prec);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
void InsertBeforeDP(ListDP *L, addressDP P, addressDP Succ);

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirstDP(ListDP *L, addressDP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelLastDP(ListDP *L, addressDP *P);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressDP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelPDP(ListDP *L, POINT X);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelAfterDP(ListDP *L, addressDP *Pdel, addressDP Prec);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeDP(ListDP *L, addressDP *Pdel, addressDP Succ);

#endif