#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

ArrayDin MakeArrayDin()
{
    ArrayDin arr;

    BUFFER(arr) = (ElType *)malloc(InitialSize * sizeof(ElType));
    CAPACITY(arr) = InitialSize;
    NEFF(arr) = 0;

    return arr;
}

void DeallocateArrayDin(ArrayDin *array)
{
    free(BUFFER(*array));
}

boolean IsEmpty(ArrayDin array)
{
    return NEFF(array) == 0;
}

boolean IsMember(ArrayDin array, ElType el)
{
    boolean member = false;
    int i = 0;
    while (!member && i<Length(array))
    {
        if (IsEQWord(array.A[i], el))
        {
            member = true;
        }
        else
        {
            i++;
        }
        
    }
    
    return member;
}

int Length(ArrayDin array)
{
    return NEFF(array);
}

ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

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
            CopyWord(&BUFFER(temp)[j], BUFFER(*array)[j]);
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

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, NEFF(*array));
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i)
{
    IdxType idx;
    for (idx = i; idx < Length(*array); idx++)
    {
        CopyWord(&BUFFER(*array)[idx], BUFFER(*array)[idx + 1]);
    }
    NEFF(*array) -= 1;
}

void DeleteLast(ArrayDin *array)
{
    NEFF(*array) -= 1;
}

void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array)
{
    if (IsEmpty(array))
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else
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
}
