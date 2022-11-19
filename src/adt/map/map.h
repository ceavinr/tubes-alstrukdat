#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 10

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotype;

typedef struct
{
	infotype Elements[MaxEl];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */


/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
void CreateEmpty(Map *M);

/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
boolean IsEmpty(Map M);

/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
boolean IsFull(Map M);

/* Mengembalikan nilai value dengan key k dari M */
valuetype Value(Map M, keytype k);

/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void Insert(Map *M, keytype k, valuetype v);

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void Delete(Map *M, keytype k);

/* Mengembalikan true jika k adalah member dari M */
boolean IsMember(Map M, keytype k);

#endif