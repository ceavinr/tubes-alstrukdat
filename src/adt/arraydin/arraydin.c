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
    if (Length(*array) == CAPACITY(*array))
    {
        ArrayDin temp;

        BUFFER(temp) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));
        for (j = 0; j < Length(*array); j++)
        {
            BUFFER(temp)
            [j] = BUFFER(*array)[j];
        }

        DeallocateArrayDin(array);

        CAPACITY(*array) *= 2;
        BUFFER(*array) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));

        for (j = 0; j < Length(*array); j++)
        {
            BUFFER(*array)
            [j] = BUFFER(temp)[j];
        }
        DeallocateArrayDin(&temp);
    }

    for (j = NEFF(*array); j > i; j--)
    {
        BUFFER(*array)
        [j] = BUFFER(*array)[j - 1];
    }
    BUFFER(*array)
    [i] = el;
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
        (*array).A[idx] = (*array).A[idx + 1];
    }
    NEFF(*array)
    --;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
    NEFF(*array)
    --;
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
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array)
{
    printf("[");
    for (int i = 0; i < NEFF(array); i++)
    {
        printf("%i", BUFFER(array)[i]);
        if (i < Length(array) - 1)
            printf(", ");
    }
    printf("]\n");
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
        BUFFER(temp)
        [i] = BUFFER(*array)[NEFF(*array) - i - 1];
    }
    for (int i = 0; i < NEFF(*array); i++)
    {
        BUFFER(*array)
        [i] = BUFFER(temp)[i];
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

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    int i = 0;
    boolean found = false;
    while (!found && i < NEFF(array))
    {
        if (BUFFER(array)[i] == el)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
