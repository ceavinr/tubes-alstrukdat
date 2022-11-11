#include "stack.h"

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsStackEmpty(Stack S)
{
    return Top(S) == Nil;
}

boolean IsStackFull(Stack S)
{
    return Top(S) == MaxEl - 1;
}

void Push(Stack *S, infotype X, boolean *succeed)
{
    if (IsStackEmpty(*S))
    {
        Top(*S) += 1;
        InfoTop(*S) = X;
        (*succeed) = true;
    }
    else
    {
        if (X < InfoTop(*S))
        {
            Top(*S) += 1;
            InfoTop(*S) = X;
            (*succeed) = true;
        }
        else
        {
            (*succeed) = false;
        }
    }
}

void Pop(Stack *S, infotype *X, boolean *succeed)
{
    if (!IsStackEmpty(*S))
    {
        (*X) = InfoTop(*S);
        Top(*S) -= 1;
        (*succeed) = true;
    }
    else
    {
        (*succeed) = false;
    }
}