#include "map.h"

void CreateEmpty(Map *M)
{
    (*M).Count = Nil;
    int i;
    for (i=0; i<MaxEl; i++) {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
}

boolean IsEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsFull(Map M)
{
    return M.Count == MaxEl;
}

valuetype Value(Map M, keytype k)
{
    address idx = Index(M, k);
    return M.Elements[idx].Value;
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (!IsFull(*M))
    {
        address idx = Index(*M, k);
        if (IsMember(*M, k))
        {
            (*M).Elements[idx].Value = v;
        } else {
            (*M).Elements[idx].Value = v;
            (*M).Elements[idx].Key = k;
            (*M).Count++;
        }
    }
}

void Delete(Map *M, keytype k)
{
    if (IsMember(*M, k))
    {
        address idx = Index(*M, k);
        (*M).Elements[idx].Key = Undefined;
        (*M).Elements[idx].Value = Undefined;
        (*M).Count--;
    }
    
}

boolean IsMember(Map M, keytype k)
{
    address idx = Index(M, k);
    return M.Elements[idx].Key != Undefined;
}

address Hash(keytype k)
{
    return k%MaxEl;
}

keytype ToKey(Word w)
{
    int key = 0;
    int i;
    for (i=0;  i<w.Length; i++)
    {
        key += w.TabWord[i]-48;
    }
    return key;
}

address Index(Map M, keytype k)
{
    boolean found = false;
    address hashed = Hash(k);
    address idx = 0;

    while (!found && M.Elements[Hash(hashed+idx)].Key != Undefined) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    if (found)
    {
        return Hash(hashed+idx);
    }
}