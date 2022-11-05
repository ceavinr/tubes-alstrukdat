#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

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
            CopyWord(BUFFER(temp)[j], BUFFER(*array)[j]);
        }
        temp.Neff = (*array).Neff;

        DeallocateArrayDin(array);

        CAPACITY(*array) *= 2;
        BUFFER(*array) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));

        for (j = 0; j < Length(*array); j++)
        {
            CopyWord(&BUFFER(*array)[j], (temp.A[j]));
        }
        (*array).Neff = temp.Neff;
        DeallocateArrayDin(&temp);
    }

    for (j = NEFF(*array); j > i; j--)
    {
        CopyWord(&BUFFER(*array)[j], BUFFER(*array)[j - 1]);
    }
    CopyWord(&BUFFER(*array)[i], el);

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
        CopyWord(&BUFFER(*array)[idx], BUFFER(*array)[idx + 1]);
    }
    NEFF(*array) -= 1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
    NEFF(*array) -= 1;
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
    for (i = 0; i < array.Neff; i++)
    {
        printf("%d. ", i + 1);
        int j;
        for (j = 0; j < BUFFER(array)[i].Length; j++)
        {
            printf("%c", BUFFER(array)[i].TabWord[j]);
        }
        printf("\n");
    }
}
