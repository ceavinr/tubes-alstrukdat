#include "set.h"

void CreateEmpty(Set *S)
{
    (*S).Count = Nil;
}

boolean IsEmpty(Set S)
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
{
    return S.Count == MaxEl;
}

void Insert(Set *S, infotype Elmt)
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    (*S).Elements[(*S).Count] = Elmt;
    (*S).Count++;
}

void Delete(Set *S, infotype Elmt)
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < (*S).Count)
    {
        if (IsEQWord((*S).Elements[idx], Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < (*S).Count; iterator++)
    {
        (*S).Elements[iterator - 1] = (*S).Elements[iterator];
    }
    (*S).Count--;
}

boolean IsMember(Set S, infotype Elmt)
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (IsEQWord(S.Elements[idx], Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}