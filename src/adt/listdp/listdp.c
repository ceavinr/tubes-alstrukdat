#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyDP(ListDP L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == NilDP && Last(L) == NilDP);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyDP(ListDP *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = NilDP;
    Last(*L) = NilDP;
}
/****************** Manajemen Memori ******************/
addressDP AlokasiDP(char X)
/* Mengirimkan addressDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressDP tidak NilDP. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilDP, Prev(P)=NilDP */
/* Jika alokasi gagal, mengirimkan NilDP. */
{
    ElmtListDP *P = NilDP;
    P = (ElmtListDP *)malloc(sizeof(ElmtListDP));
    if (P != NilDP)
    {
        Info(P) = X;
        Next(P) = NilDP;
        Prev(P) = NilDP;
        return P;
    }
    else
    {
        return NilDP;
    }
}
void DealokasiDP(addressDP P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressDP P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressDP SearchDP(ListDP L, char X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressDP elemen tersebut. */
/* Jika tidak ada, mengirimkan NilDP */
{
    addressDP P = First(L);
    boolean found = false;
    while (P != NilDP && !found)
    {
        if (Info(P) == X)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if (found)
    {
        return (P);
    }
    else
    {
        return NilDP;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstDP(ListDP *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressDP P = AlokasiDP(X);
    if (P != NilDP)
    {
        InsertFirstDP(L, P);
    }
}
void InsVLastDP(ListDP *L, char X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressDP P = AlokasiDP(X);
    if (P != NilDP)
    {
        InsertLastDP(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstDP(ListDP *L, char *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressDP P;
    DelFirstDP(L, &P);
    *X = Info(P);
    DealokasiDP(P);
}

void DelVLastDP(ListDP *L, char *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
{
    addressDP P;
    DelLastDP(L, &P);
    *X = Info(P);
    DealokasiDP(P);
}
void InsertFirstDP(ListDP *L, addressDP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressDP P sebagai elemen pertama */
{
    Prev(P) = NilDP;
    if (IsEmptyDP(*L))
    {
        Next(P) = NilDP;
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLastDP(ListDP *L, addressDP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    Next(P) = NilDP;
    if (IsEmptyDP(*L))
    {
        First(*L) = P;
        Prev(P) = NilDP;
        Last(*L) = P;
    }
    else
    {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void InsertAfterDP(ListDP *L, addressDP P, addressDP Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
    Prev(P) = Prec;
    if (Next(P) == NilDP)
    {
        Last(*L) = P;
    }
    else
    {
        Prev(Next(Prec)) = P;
    }
}
void InsertBeforeDP(ListDP *L, addressDP P, addressDP Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Next(P) = Succ;
    Prev(P) = Prev(Succ);
    Prev(Succ) = P;
    if (Prev(P) != NilDP)
    {
        Next(Prev(P)) = P;
    }
    else
    {
        First(*L) = P;
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstDP(ListDP *L, addressDP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    addressDP q = First(*L);
    *P = q;
    if (Next(q) == NilDP)
    {
        CreateEmptyDP(L);
    }
    else
    {
        First(*L) = Next(q);
        Prev(First(*L)) = NilDP;
    }
}
void DelLastDP(ListDP *L, addressDP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    addressDP q = Last(*L);
    *P = q;
    if (Prev(q) == NilDP)
    {
        CreateEmptyDP(L);
    }
    else
    {
        Next(Prev(q)) = NilDP;
        Last(*L) = Prev(q);
    }
}
void DelPDP(ListDP *L, char X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressDP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressDP P = SearchDP(*L, X);
    addressDP Q = Last(*L);
    if (P == First(*L))
    {
        DelFirstDP(L, &P);
    }
    else if (P == Last(*L))
    {
        DelLastDP(L, &P);
    }
    else
    {
        while (Q != P)
        {
            Q->Pos.X = Prev(Q)->Pos.X;
            Q->Pos.Y = Prev(Q)->Pos.Y;
        }
        Next(Prev(P)) = Next(P);
        Prev(Next(P)) = Prev(P);
    }
    DealokasiDP(P);
}
void DelAfterDP(ListDP *L, addressDP *Pdel, addressDP Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NilDP)
    {
        Next(Prec) = Next(Next(Prec));
        if (Next(Prec) == NilDP)
        {
            Last(*L) = Prec;
        }
        else
        {
            Prev(Next(Prec)) = Prec;
        }
    }
}
void DelBeforeDP(ListDP *L, addressDP *Pdel, addressDP Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    addressDP Q = Last(*L);
    if (Prev(Succ) != NilDP)
    {
        Prev(Succ) = Prev(Prev(Succ));
        if (Prev(Succ) == NilDP)
        {
            First(*L) = Succ;
        }
        else
        {
            Next(Prev(Succ)) = Succ;
        }
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardDP(ListDP L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyDP(L))
    {
        addressDP P = First(L);
        printf("%c", Info(P));
        P = Next(P);
        while ((P) != NilDP)
        {
            printf(",%c", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
void PrintBackwardDP(ListDP L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyDP(L))
    {
        addressDP P = Last(L);
        printf("%d", Info(P));
        P = Prev(P);
        while ((P) != NilDP)
        {
            printf(",%d", Info(P));
            P = Prev(P);
        }
    }
    printf("]");
}
