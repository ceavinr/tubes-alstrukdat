#include <stdio.h>
#include "array.h"
#include <stdlib.h>

void CreateArray(Array *arr)
{
    (*arr).Count = 0;
}

boolean IsArrayEmpty(Array arr)
{
    return (arr).Count == 0;
}

boolean IsArrayFull(Array arr)
{
    return (arr).Count == MaxArrayEl;
}

void Insert(Array *arr, Masakan val)
{
    int i = COUNT(*arr);
    boolean stop = false;

    while (i != 0 && !stop)
    {
        if (NOMOR(val) >= NOMOR(ARRELMT(*arr, i - 1)))
        {
            stop = true;
        }
        else
        {
            copyMasakan(&ARRELMT(*arr, i), ARRELMT(*arr, i - 1));
            i--;
        }
    }

    copyMasakan(&ARRELMT(*arr, i), val);
    COUNT(*arr) += 1;
}

void DeleteArrayAt(Array *arr, Masakan *val, int idx)
{
    copyMasakan(val, ARRELMT((*arr), idx));

    for (int i = idx; i < COUNT(*arr) - 1; i++)
    {
        copyMasakan(&ARRELMT(*arr, i), ARRELMT(*arr, i + 1));
    }
    COUNT(*arr) -= 1;
}

int indexOf(Array arr, int nomor)
{
    int i = 0;
    boolean found = false;
    while (i <= COUNT(arr) - 1 && !found)
    {
        if (NOMOR(ARRELMT(arr, i)) == nomor)
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
        return IDX_UNDEF;
    }
}

Masakan find(Array arr, int nomor)
{
    return ARRELMT(arr, indexOf(arr, nomor));
}

boolean isMember(Array arr, int nomor)
{
    return indexOf(arr, nomor) != IDX_UNDEF;
}
