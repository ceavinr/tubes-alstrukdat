#include "map.h"

void CreateEmptyMap(Map *M)
{
    (*M).Count = NilMap;
}

boolean IsEmptyMap(Map M)
{
    return M.Count == NilMap;
}

boolean IsFullMap(Map M)
{
    return M.Count == MaxElMap;
}

valuetype ValueInMap(Map M, keytype k)
{
    boolean found = false;
    addressMap idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (IsEQWord(M.Elements[idx].Key, k)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void InsertInMap(Map *M, keytype k, valuetype v)
{
    if (!IsMemberInMap(*M, k)) {
        CopyWord(&(*M).Elements[(*M).Count].Key, k);
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
    SortMap(M);
}

void DeleteInMap(Map *M, keytype k)
{
    boolean found = false;
    addressMap idx = 0, iterator;

    if (!IsMemberInMap(*M, k)) {
        return;
    }

    while (!found && (idx < (*M).Count)) {
        if (IsEQWord((*M).Elements[idx].Key, k)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < (*M).Count; iterator++) {
        (*M).Elements[iterator - 1].Key = (*M).Elements[iterator].Key;
        (*M).Elements[iterator - 1].Value = (*M).Elements[iterator].Value;
    }

    (*M).Count--;
}

boolean IsMemberInMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    addressMap idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (IsEQWord(M.Elements[idx].Key, k)) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}

boolean IsEQMap(Map m1, Map m2)
{
    if (m1.Count != m2.Count)
    {
        return false;
    } else
    {
        boolean cek = true;
        int i=0;
        while (cek && i<m1.Count)
        {
            if (!IsEQWord(m1.Elements[i].Key, m2.Elements[i].Key) || m1.Elements[i].Value != m2.Elements[i].Value)
            {
                cek = false;
            }
            
        }
        return cek;
    }
    
}

void CopyMap(Map *m1, Map m2)
{
    for (int i = 0; i < (*m1).Count; i++)
    {
        CopyWord(&(*m1).Elements[i].Key, m2.Elements[i].Key);
        (*m1).Elements[i].Value = m2.Elements[i].Value;
    }
    
}

void SortMap(Map *m)
{
    int j, tempVal;
    Word tempKey;

    boolean flag = true;
    while (flag)
    {
        flag = false;
        for (j = 0; j < (*m).Count - 1; j++)
        {
            if ((*m).Elements[j].Value < (*m).Elements[j+1].Value)
            {
                CopyWord(&tempKey, (*m).Elements[j].Key);
                tempVal = (*m).Elements[j].Value;

                CopyWord(&(*m).Elements[j].Key, (*m).Elements[j+1].Key);
                (*m).Elements[j].Value = (*m).Elements[j+1].Value;

                CopyWord(&(*m).Elements[j+1].Key, tempKey);
                (*m).Elements[j+1].Value = tempVal;
                flag = true;
            }
        }
    }
}

void PrintMap(Map m)
{
    int i, j, spacing, skor;
    printf("| NAMA          | SKOR          |\n");
    printf("|-------------------------------|\n");

    if (IsEmptyMap(m))
    {
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else
    {
        for (i = 0; i < m.Count; i++)
        {
            printf("| ");
            printWord(m.Elements[i].Key);

            spacing = 14 - m.Elements[i].Key.Length;
            for (j = 0; j < spacing; j++)
            {
                printf(" ");
            }

            skor = m.Elements[i].Value;
            printf("| %d", skor);

            spacing = 14;
            while (skor != 0)
            {
                skor = skor / 10;
                spacing--;
            }

            for (j = 0; j < spacing; j++)
            {
                printf(" ");
            }
            printf("|\n");
        }
    }
    printf("\n");
}