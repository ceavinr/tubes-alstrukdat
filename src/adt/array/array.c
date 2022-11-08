#include <stdio.h>
#include "array.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void ArMakeEmpty(Array *T)
{
    (*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int ArNbElmt(Array T)
{
    return ((T).Neff);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int ArMaxNbEl(Array T)
{
    return (IdxMax);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType ArGetFirstIdx(Array T)
{
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType ArGetLastIdx(Array T)
{
    return ArNbElmt(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ArElType ArGetElmt(Array T, IdxType i)
{
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void ArSetTab(Array Tin, Array *Tout)
{
    int i;
    for (i = IdxMin; i <= IdxMax; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
    (*Tout).Neff = Tin.Neff;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void ArSetEl(Array *T, IdxType i, ArElType v)
{
    (*T).TI[i] = v;
    if (i == ArGetLastIdx(*T) + 1)
    {
        (*T).Neff++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void ArSetNeff(Array *T, IdxType N)
{
    (*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean ArIsIdxValid(Array T, IdxType i)
{
    return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean ArIsIdxEff(Array T, IdxType i)
{
    return ((i >= ArGetFirstIdx(T)) && (i <= ArGetLastIdx(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean ArIsEmpty(Array T)
{
    return (ArNbElmt(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean ArIsFull(Array T)
{
    return (ArNbElmt(T) == ArMaxNbEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void ArTulisIsi(Array T)
{
    if (ArIsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        int i;
        for (i = ArGetFirstIdx(T); i <= ArGetLastIdx(T); i++)
        {
            printf("%d:%d\n", i, T.TI[i]);
        }
    }
}
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
Array ArPlusTab(Array T1, Array T2)
{
    Array Tsum;
    ArMakeEmpty(&Tsum);
    Tsum.Neff = T1.Neff;
    for (int i = ArGetFirstIdx(T1); i <= ArGetLastIdx(T1); i++)
    {
        ArSetEl(&Tsum, i, ArGetElmt(T1, i) + ArGetElmt(T2, i));
    }
    return Tsum;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
Array ArMinusTab(Array T1, Array T2)
{
    Array Tmin;
    ArMakeEmpty(&Tmin);
    Tmin.Neff = T1.Neff;
    for (int i = ArGetFirstIdx(T1); i <= ArGetLastIdx(T1); i++)
    {
        ArSetEl(&Tmin, i, ArGetElmt(T1, i) - ArGetElmt(T2, i));
    }
    return Tmin;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ArElType ArValMax(Array T)
{
    ArElType max;
    int i;
    max = T.TI[ArGetFirstIdx(T)];
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (max < T.TI[i])
        {
            max = T.TI[i];
        }
    }

    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ArElType ArValMin(Array T)
{
    ArElType min;
    int i;
    min = T.TI[ArGetFirstIdx(T)];
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (min > T.TI[i])
        {
            min = T.TI[i];
        }
    }

    return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType ArIdxMaxTab(Array T)
{
    int i;
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (T.TI[i] == ArValMax(T))
        {
            return i;
        }
    }
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType ArIdxMinTab(Array T)
{
    int i;
    for (i = (ArGetFirstIdx(T) + 1); i <= (ArGetLastIdx(T)); i++)
    {
        if (T.TI[i] == ArValMin(T))
        {
            return i;
        }
    }
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
