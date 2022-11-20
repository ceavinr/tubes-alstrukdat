#include "map.h"

void CreateEmptyMap(Map *M)
{
    (*M).Count = NilMap;
    int i;
    for (i=0; i<MaxElMap; i++) {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
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
    address idx = IndexInMap(M, k);
    return M.Elements[idx].Value;
}

void InsertInMap(Map *M, keytype k, valuetype v)
{
    if (!IsFullMap(*M))
    {
        address idx = IndexInMap(*M, k);
        if (IsMemberInMap(*M, k))
        {
            (*M).Elements[idx].Value = v;
        } else {
            (*M).Elements[idx].Value = v;
            (*M).Elements[idx].Key = k;
            (*M).Count++;
        }
    }
}

void DeleteInMap(Map *M, keytype k)
{
    if (IsMemberInMap(*M, k))
    {
        address idx = IndexInMap(*M, k);
        (*M).Elements[idx].Key = Undefined;
        (*M).Elements[idx].Value = Undefined;
        (*M).Count--;
    }
    
}

boolean IsMemberInMap(Map M, keytype k)
{
    address idx = IndexInMap(M, k);
    return M.Elements[idx].Key != Undefined;
}

address Hash(keytype k)
{
    return k%MaxElMap;
}

keytype ToKey(Word w)
{
    int key = 0;
    int i;
    for (i=0;  i<w.Length; i++)
    {
        key += w.TabWord[i];
    }
    return key;
}

address IndexInMap(Map M, keytype k)
{
    boolean found = false;
    address hashed = Hash(k);
    address idx = 0;

    while (!found && M.Elements[Hash(hashed+idx)].Key != Undefined) {
        if (M.Elements[Hash(hashed+idx)].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return Hash(hashed+idx);
}