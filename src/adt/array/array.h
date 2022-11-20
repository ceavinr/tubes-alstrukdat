#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../../boolean.h"
#include "../masakan/masakan.h"

#define MaxArrayEl 25
#define IDX_UNDEF -1

typedef struct
{
	Masakan Elements[MaxArrayEl];
	int Count;
} Array;

#define COUNT(arr) (arr).Count
#define ARRELMT(arr, i) (arr).Elements[i]

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Array arr kosong berkapasitas MaxArrayEl */
/* Ciri Array kosong : count bernilai Nil */
void CreateArray(Array *arr);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

/* Mengirim true jika Array arr kosong*/
/* Ciri Array kosong : count bernilai Nil */
boolean IsArrayEmpty(Array arr);
/* Mengirim true jika Array arr penuh */
/* Ciri Array penuh : count bernilai MaxArrayEl */
boolean IsArrayFull(Array arr);

/* ********** Operator Dasar Array ********* */

/* Menambahkan Elmt sebagai elemen Array arr. */
/* I.S. arr mungkin kosong, arr tidak penuh
		arr mungkin sudah beranggotakan val */
/* F.S. v menjadi anggota dari arr. */
void Insert(Array *arr, Masakan val);

/* Menghapus Elmt dari Array arr berdasarkan nomor. */
/* I.S. arr tidak kosong
		element dengan nomor nomor mungkin anggota / bukan anggota dari arr */
/* F.S. element dengan nomor nomor yang pertama kali ditemukan dihapus dari arr */
void DeleteArrayAt(Array *arr, Masakan *val, int idx);

/* *** Find *** */

/* Melakukan pencarian pada array berdasarkan nomor (nomor masakan), jika ditemukan akan mereturn index dari masakan yang ditemukan pertama kali. Jika tidak mereturn IDX_UNDEF */
int indexOf(Array arr, int nomor);
/* Melakukan pencarian pada array berdasarkan nomor (nomor masakan), jika ditemukan akan mereturn Masakan yang ditemukan pertama kali . Masakan dipastikan terdapat pada array */
Masakan find(Array arr, int nomor);
/* Melakukan pengecekan berdasarkan nomor apakah sebuah masakan terdapat masakan dalam sebuah array */
boolean isMember(Array arr, int nomor);

#endif