#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../mesin/mesinkata.h"
#include "../word/word.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxType;
typedef Word ElType;
typedef struct
{
    ElType *A;
    int Capacity;
    int Neff;
} ArrayDin;

#define BUFFER(arr) (arr).A
#define CAPACITY(arr) (arr).Capacity
#define NEFF(arr) (arr).Neff

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 * mengembalikan true jika array kosong
 */
boolean IsEmptyArrayDin(ArrayDin array);

/**
 * Fungsi untuk mengetahui apakah suatu elemen terdapat pada array.
 * Prekondisi: array terdefinisi
 * mengembalikan true jika elemen ada di dalam array
 */
boolean IsMemberArrayDin(ArrayDin array, ElType el);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayDin(ArrayDin array);

/**
 * menambahkan elemen baru di index ke-i
 * I.S. array terdefinisi, i di antara 0..Length(array).
 * F.S. array telah ditambahkan pada elemen ke-i
 */
void InsertAtArrayDin(ArrayDin *array, ElType el, IdxType i);

/**
 * menambahkan elemen baru di akhir array.
 * I.S. array terdefinisi
 * F.S. array telah ditambahkan pada elemen terakhir
 */
void InsertLastArrayDin(ArrayDin *array, ElType el);

/**
 * menambahkan elemen baru di awal array.
 * I.S. array terdefinisi
 * F.S. array telah ditambahkan pada elemen pertama
 */
void InsertFirstArrayDin(ArrayDin *array, ElType el);

/**
 * menghapus elemen di index ke-i ArrayDin
 * I.S. array terdefinisi, i di antara 0..Length(array).
 * F.S. array telah dihapus pada elemen ke-i
 */
void DeleteAtArrayDin(ArrayDin *array, IdxType i);

/**
 * menghapus elemen terakhir ArrayDin
 * I.S. array terdefinisi
 * F.S. array telah dihapus pada elemen terakhir
 */
void DeleteLastArrayDin(ArrayDin *array);

/**
 * menghapus elemen pertama ArrayDin
 * I.S. array terdefinisi
 * F.S. array telah dihapus pada elemen pertama
 */
void DeleteFirstArrayDin(ArrayDin *array);

/**
 * melakukan print suatu ArrayDin. 
 * Banyak merupakan banyak data yang akan ditampilkan
 * I.S. array terdefinisi
 * F.S. Print dilakukan dengan format: Daftar Game
 * dan diakhiri newline.
 */
void PrintArrayDin(ArrayDin array, int banyak);

#endif