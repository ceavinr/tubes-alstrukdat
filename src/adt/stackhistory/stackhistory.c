#include "stackhistory.h"

void CreateStackHistory(StackHistory *S)
{
    Top(*S) = NilHistory;
}

boolean IsStackHistoryEmpty(StackHistory S)
{
    return Top(S) == NilHistory;
}

boolean IsStackHistoryFull(StackHistory S)
{
    return Top(S) == MaxElHistory - 1;
}

void PushHistory(StackHistory *S, infotypeHistory X)
{
    if (!IsStackHistoryFull(*S)) {
        Top(*S) += 1;
        CopyWord(&InfoTop(*S), X);
    } else {
        printf("Stack is full ...\n");
    }
}

void PopHistory(StackHistory *S, infotypeHistory *X)
{
    CopyWord(X, InfoTop(*S));
	Top(*S) -= 1;
}

void InverseStackHistory(StackHistory *S)
{
    StackHistory temp;
    CreateStackHistory(&temp);
    infotypeHistory val;
    CopyStackHistory(&temp, *S);
    CreateStackHistory(S);
    while (Top(temp) >= 0)
    {
        PopHistory(&temp, &val);
        PushHistory(S, val);
    }
}

void CopyStackHistory(StackHistory *S1, StackHistory S2)
{
    StackHistory temp;
    CreateStackHistory(&temp);
    infotypeHistory val;
    while (Top(S2) >= 0) {
        PopHistory(&S2, &val);
        PushHistory(&temp, val);
    }
    while (Top(temp) >= 0) {
        PopHistory(&temp, &val);
        PushHistory(S1, val);
    }
}

void PrintStackHistory(StackHistory S, int banyak)
{
    int i, j, neff;
    infotypeHistory val;

    if (IsStackHistoryEmpty(S) || banyak==0)
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else if (banyak < Top(S)+1)
    {
        for (i = 0; i < banyak; i++)
        {
            printf("%d. ", i + 1);
            PopHistory(&S, &val);
            for (j = 0; j < val.Length; j++)
            {
                printf("%c", val.TabWord[j]);
            }
            printf("\n");
        }
    }
    else
    {
        neff = Top(S)+1;
        for (i = 0; i < neff; i++)
        {
            printf("%d. ", i + 1);
            PopHistory(&S, &val);
            for (j = 0; j < val.Length; j++)
            {
                printf("%c", val.TabWord[j]);
            }
            printf("\n");
        }
    }
}
