#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"

// #define false 0
// #define true 1
#define NilMap 0
#define MaxElMap 100

// typedef int bool;
typedef Word keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotypeMap;

typedef struct
{
	infotypeMap Elements[MaxElMap];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai Nil */
void CreateEmptyMap(Map *M);

/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
boolean IsEmptyMap(Map M);

/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElMap */
boolean IsFullMap(Map M);

/* Mengembalikan nilai value dengan key k dari M */
valuetype ValueInMap(Map M, keytype k);

/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void InsertInMap(Map *M, keytype k, valuetype v);

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void DeleteInMap(Map *M, keytype k);

/* Mengembalikan true jika k adalah member dari M */
boolean IsMemberInMap(Map M, keytype k);

/* Mengembalikan true jika m1 == m2 */
boolean IsEQMap(Map m1, Map m2);

/* Melakukan copy Elmt dari Map m2 ke m1. */
/* I.S. m1 dan m2 terdefinisi
/* F.S. elemen dari m2 dicopy ke m2 */
void CopyMap(Map *m1, Map m2);

/* Melakukan sorting berdasarkan value */
/* I.S. m terdefinisi
/* F.S. elemen dari m berhasil disorting secara discending*/
void SortMap(Map *m);

/* Melakukan print isi map sesuai format scoreboard. */
/* I.S. m1 terdefinisi
/* F.S. menampilkan si map sesuai scoreboard */
void PrintMap(Map m);

#endif