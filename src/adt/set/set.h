#ifndef set_H
#define set_H
#include <stdio.h>
#include "../../boolean.h"
#include "../word/word.h"

#define Nil 0
#define MaxEl 100

typedef Word infotype;
typedef int address;

typedef struct
{
    infotype Elements[MaxEl];
    address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
void CreateEmpty(Set *S);

/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
boolean IsEmpty(Set S);

/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
boolean IsFull(Set S);

/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
void Insert(Set *S, infotype Elmt);

/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
void Delete(Set *S, infotype Elmt);

/* Mengembalikan true jika Elmt adalah member dari S */
boolean IsMember(Set S, infotype Elmt);

#endif