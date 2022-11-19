#include "set.h"

void CreateEmptySet(Set *S)
{
    (*S).Count = Nil;
}

boolean IsEmptySet(Set S)
{
    return S.Count == Nil;
}

boolean IsFullSet(Set S)
{
    return S.Count == MaxEl;
}

void InsertInSet(Set *S, infotype Elmt)
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    (*S).Elements[(*S).Count] = Elmt;
    (*S).Count++;
}

void DeleteInSet(Set *S, infotype Elmt)
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

boolean IsMemberInSet(Set S, infotype Elmt)
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