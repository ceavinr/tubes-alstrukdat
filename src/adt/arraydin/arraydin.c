#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER(arr) (arr).A
#define CAPACITY(arr) (arr).Capacity
#define NEFF(arr) (arr).Neff

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
    ArrayDin arr;

    BUFFER(arr) = (ElType *)malloc(InitialSize * sizeof(ElType));
    CAPACITY(arr) = InitialSize;
    NEFF(arr) = 0;

    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    free(BUFFER(*array));
    // CAPACITY(*array) = 0;
    // NEFF(*array) = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    return NEFF(array) == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    return NEFF(array);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    IdxType j;
    int k;
    if (Length(*array) == CAPACITY(*array))
    {
        ArrayDin temp;
    
        BUFFER(temp) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));
        for (j = 0; j < Length(*array); j++)
        {
            for (k=0; k<(*array).A[j].Length; k++) {
                temp.A[j].TabWord[k] = (*array).A[j].TabWord[k];
            }
            temp.A[j].Length = (*array).A[j].Length;
        }
        temp.Neff = (*array).Neff;

        DeallocateArrayDin(array);

        CAPACITY(*array) *= 2;
        BUFFER(*array) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));

        for (j = 0; j < Length(*array); j++)
        {
            for (k=0; k<temp.A[j].Length; k++) {
                (*array).A[j].TabWord[k] = temp.A[j].TabWord[k];
            }
            (*array).A[j].Length = temp.A[j].Length;
        }
        (*array).Neff = temp.Neff;
        DeallocateArrayDin(&temp);
    }

    for (j = NEFF(*array); j > i; j--)
    {
        for (k=0; k<(*array).A[j-1].Length; k++) {
            (*array).A[j].TabWord[k] = (*array).A[j-1].TabWord[k];
        }
        (*array).A[j].Length = (*array).A[j-1].Length;
    }
    for (k=0; k<el.Length; k++) {
        (*array).A[i].TabWord[k] = el.TabWord[k];
    }
    (*array).A[i].Length = el.Length;
    NEFF(*array) += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, NEFF(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    IdxType idx;
    for (idx = i; idx < Length(*array); idx++)
    {
        int k;
        for (k=0; k<(*array).A[idx+1].Length; k++) {
            (*array).A[idx].TabWord[k] = (*array).A[idx+1].TabWord[k];
        }
        (*array).A[idx].Length = (*array).A[idx+1].Length;
    }
    NEFF(*array)--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
    NEFF(*array)--;
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: Daftar Game
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array)
{
    int i;
    for(i=0; i<array.Neff; i++) {
        printf("%d. ", i+1);
        int j;
        for (j=0; j<BUFFER(array)[i].Length; j++) {
            printf("%c", BUFFER(array)[i].TabWord[j]);
        }
        printf("\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array)
{
    ArrayDin temp;
    temp = MakeArrayDin();

    BUFFER(temp) = (ElType *)malloc(sizeof(ElType) * Length(*array));

    for (int i = 0; i < NEFF(*array); i++)
    {
        // BUFFER(temp)[i] = BUFFER(*array)[NEFF(*array) - i - 1];
        int k;
        for (k=0; k<(*array).A[NEFF(*array) - i - 1].Length; k++) {
            temp.A[i].TabWord[k] = (*array).A[NEFF(*array) - i - 1].TabWord[k];
        }
        temp.A[i].Length = (*array).A[NEFF(*array) - i - 1].Length;
    }
    for (int i = 0; i < NEFF(*array); i++)
    {
        // BUFFER(*array)[i] = BUFFER(temp)[i];
        int k;
        for (k=0; k<temp.A[i].Length; k++) {
            (*array).A[i].TabWord[k] = temp.A[i].TabWord[k];
        }
        (*array).A[i].Length = temp.A[i].Length;
    }
    DeallocateArrayDin(&temp);
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array)
{
    ArrayDin copiedArray;

    BUFFER(copiedArray) = (ElType *)malloc(sizeof(ElType) * CAPACITY(array));

    for (int i = 0; i < NEFF(array); i++)
    {
        BUFFER(copiedArray)
        [i] = BUFFER(array)[i];
    }
    NEFF(copiedArray) = NEFF(array);
    CAPACITY(copiedArray) = CAPACITY(array);

    return copiedArray;
}

void PrintWord(Word w) {
/*
I.S word terdefinisi
F.S menghasilkan ouput tabword 
*/
    int i;
    for (i=0; i<w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}