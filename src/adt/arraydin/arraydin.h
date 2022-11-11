#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../mesinkata/mesinkata.h"
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
boolean IsEmpty(ArrayDin array);

/**
 * Fungsi untuk mengetahui apakah suatu elemen terdapat pada array.
 * Prekondisi: array terdefinisi
 * mengembalikan true jika elemen ada di dalam array
 */
boolean IsMember(ArrayDin array, ElType el);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i);

/**
 * menambahkan elemen baru di index ke-i
 * I.S. array terdefinisi, i di antara 0..Length(array).
 * F.S. array telah ditambahkan pada elemen ke-i
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i);

/**
 * menambahkan elemen baru di akhir array.
 * I.S. array terdefinisi
 * F.S. array telah ditambahkan pada elemen terakhir
 */
void InsertLast(ArrayDin *array, ElType el);

/**
 * menambahkan elemen baru di awal array.
 * I.S. array terdefinisi
 * F.S. array telah ditambahkan pada elemen pertama
 */
void InsertFirst(ArrayDin *array, ElType el);

/**
 * menghapus elemen di index ke-i ArrayDin
 * I.S. array terdefinisi, i di antara 0..Length(array).
 * F.S. array telah dihapus pada elemen ke-i
 */
void DeleteAt(ArrayDin *array, IdxType i);

/**
 * menghapus elemen terakhir ArrayDin
 * I.S. array terdefinisi
 * F.S. array telah dihapus pada elemen terakhir
 */
void DeleteLast(ArrayDin *array);

/**
 * menghapus elemen pertama ArrayDin
 * I.S. array terdefinisi
 * F.S. array telah dihapus pada elemen pertama
 */
void DeleteFirst(ArrayDin *array);

/**
 * melakukan print suatu ArrayDin.
 * I.S. array terdefinisi
 * F.S. Print dilakukan dengan format: Daftar Game
 * dan diakhiri newline.
 */
void PrintArrayDin(ArrayDin array);

#endif