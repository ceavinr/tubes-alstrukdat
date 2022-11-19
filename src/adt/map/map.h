#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../word/word.h"

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 100
#define Undefined -9999

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

/* Map merupakan Hashing Map */
/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
void CreateEmptyMap(Map *M);

/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
boolean IsEmptyMap(Map M);

/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
boolean IsFullMap(Map M);

/* Mengembalikan nilai value dengan key k dari M */
valuetype ValueInMap(Map M, keytype k);

/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, value akan direplace 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi*/
void InsertInMap(Map *M, keytype k, valuetype v);

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void DeleteInMap(Map *M, keytype k);

/* Mengembalikan true jika k adalah member dari M */
boolean IsMemberInMap(Map M, keytype k);

/* *** Index Penyimpanan dengan modulo *** */
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
address Hash(keytype K);

/*Mengubah word menjadi integer dan menjadikannya sebagai key*/
keytype ToKey(Word w);

/*Mengembalikan index pada M dengan key bernilai k, 
apabila tidak ditemukan akan mengembalikan index yang memungkinkan untuk diisi (key dan value undefined)*/
address IndexInMap(Map M, keytype k);

#endif