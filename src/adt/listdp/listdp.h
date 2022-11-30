/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan addressDP adalah pointer */
/* char adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../../boolean.h"
#include "../point/point.h"

#define NilDP NULL
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
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressDP P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
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
/* Jika alokasi berhasil, maka addressDP tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
addressDP AlokasiDP(char X);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressDP P */
void DealokasiDP(addressDP P);

/****************** PENCARIAN SEBUAH ELEMEN ListDP ******************/

/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressDP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addressDP SearchPointDP(ListDP L, int X,  int Y);

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirstDP(ListDP *L, char X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLastDP(ListDP *L, char X);

/*** PENGHAPUSAN ELEMEN ***/

/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVFirstDP(ListDP *L, char *X);
/* I.S. ListDP tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DelVLastDP(ListDP *L, char *X);

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
void DelPDP(ListDP *L, char X);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelAfterDP(ListDP *L, addressDP *Pdel, addressDP Prec);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeDP(ListDP *L, addressDP *Pdel, addressDP Succ);

/****************** PROSES SEMUA ELEMEN LIST ******************/

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintForwardDP(ListDP L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardDP(ListDP L);

#endif