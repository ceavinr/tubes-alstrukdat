#include "map.h"

void CreateEmpty(Map *M)
{
    (*M).Count = Nil;
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
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (IsMember(*M, k)) {
        return;
    }

    (*M).Elements[(*M).Count].Key = k;
    (*M).Elements[(*M).Count].Value = v;
    (*M).Count++;
}

void Delete(Map *M, keytype k)
{
    boolean found = false;
    address idx = 0, iterator;

    if (!IsMember(*M, k)) {
        return;
    }

    while (!found && (idx < (*M).Count)) {
        if ((*M).Elements[idx].Key == k) {
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

boolean IsMember(Map M, keytype k)
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}