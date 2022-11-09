#include "../../boolean.h"

#ifndef ARRAY_H
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 10
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ArElType;

typedef struct
{
	ArElType TI[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
	int Neff;						  /* banyaknya elemen efektif */
} Array;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah Array, cara deklarasi dan akses: */
/* Deklarasi : T : Array */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create tabel kosong */
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
void ArMakeEmpty(Array *T);

/* ********** SELEKTOR ********** */

/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int ArNbElmt(Array T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
int ArMaxNbEl(Array T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType ArGetFirstIdx(Array T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
IdxType ArGetLastIdx(Array T);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
ArElType ArGetElmt(Array T, IdxType i);

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
void ArSetTab(Array Tin, Array *Tout);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void ArSetEl(Array *T, IdxType i, ArElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void ArSetNeff(Array *T, IdxType N);

/* ********** Test Indeks yang valid ********** */

/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean ArIsIdxValid(Array T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
boolean ArIsIdxEff(Array T, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test tabel kosong *** */
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean ArIsEmpty(Array T);
/* *** Test tabel penuh *** */
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
boolean ArIsFull(Array T);

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void ArTulisIsi(Array T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** OPERATOR ARITMATIKA ********** */

/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
Array ArPlusTab(Array T1, Array T2);
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
Array ArMinusTab(Array T1, Array T2);

/* ********** NILAI EKSTREM ********** */

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ArElType ArValMax(Array T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
ArElType ArValMin(Array T);

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
IdxType ArIdxMaxTab(Array T);
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
IdxType ArIdxMinTab(Array T);

#endif