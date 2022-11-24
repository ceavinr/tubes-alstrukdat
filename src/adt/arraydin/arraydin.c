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

boolean IsEmptyArrayDin(ArrayDin array)
{
    return NEFF(array) == 0;
}

boolean IsMemberArrayDin(ArrayDin array, ElType el)
{
    boolean member = false;
    int i = 0;
    while (!member && i<LengthArrayDin(array))
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

int LengthArrayDin(ArrayDin array)
{
    return NEFF(array);
}

void InsertAtArrayDin(ArrayDin *array, ElType el, IdxType i)
{
    IdxType j;
    int k;
    if (LengthArrayDin(*array) == CAPACITY(*array))
    {
        ArrayDin temp;

        BUFFER(temp) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));
        for (j = 0; j < LengthArrayDin(*array); j++)
        {
            CopyWord(&BUFFER(temp)[j], BUFFER(*array)[j]);
        }
        temp.Neff = (*array).Neff;

        DeallocateArrayDin(array);

        CAPACITY(*array) *= 2;
        BUFFER(*array) = (ElType *)malloc(sizeof(ElType) * CAPACITY(*array));

        for (j = 0; j < LengthArrayDin(*array); j++)
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

void InsertLastArrayDin(ArrayDin *array, ElType el)
{
    InsertAtArrayDin(array, el, NEFF(*array));
}

void InsertFirstArrayDin(ArrayDin *array, ElType el)
{
    InsertAtArrayDin(array, el, 0);
}

void DeleteAtArrayDin(ArrayDin *array, IdxType i)
{
    IdxType idx;
    for (idx = i; idx < LengthArrayDin(*array)-1; idx++)
    {
        CopyWord(&BUFFER(*array)[idx], BUFFER(*array)[idx + 1]);
    }
    NEFF(*array) -= 1;
}

void DeleteLastArrayDin(ArrayDin *array)
{
    NEFF(*array) -= 1;
}

void DeleteFirstArrayDin(ArrayDin *array)
{
    DeleteAtArrayDin(array, 0);
}

void PrintArrayDin(ArrayDin array, int banyak)
{
    int i, j;
    if (IsEmptyArrayDin(array) || banyak==0)
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else if (banyak < array.Neff)
    {
        for (i = 0; i < banyak; i++)
        {
            printf("%d. ", i + 1);
            for (j = 0; j < BUFFER(array)[i].Length; j++)
            {
                printf("%c", BUFFER(array)[i].TabWord[j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (i = 0; i < array.Neff; i++)
        {
            printf("%d. ", i + 1);
            for (j = 0; j < BUFFER(array)[i].Length; j++)
            {
                printf("%c", BUFFER(array)[i].TabWord[j]);
            }
            printf("\n");
        }
    }
}
