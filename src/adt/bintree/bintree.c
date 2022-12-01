#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

BinTree Tree(nodeinfotype Akar, BinTree L, BinTree R)
{
    BinTree result = AlokNode(Akar);
    if (result != NULL)
    {
        Left(result) = L;
        Right(result) = R;
    }
    return result;
}

void MakeTree(nodeinfotype Akar, BinTree L, BinTree R, BinTree *P)
{
    *P = Tree(Akar, L, R);
}

addrNode AlokNode(nodeinfotype X)
{
    addrNode result;
    result = (addrNode)malloc(sizeof(TreeNode));
    if (result != NULL)
    {
        Akar(result) = X;
        Left(result) = NULL;
        Right(result) = NULL;
    }
    return result;
}

void DealokNode(addrNode P)
{
    free(P);
}

boolean IsTreeEmpty(BinTree P)
{
    return P == NULL;
}

boolean IsTreeOneElmt(BinTree P)
{
    if (!IsTreeEmpty(P))
    {
        return ((Left(P) == NULL) && (Right(P) == NULL));
    }
    else
    {
        return false;
    }
}

boolean IsUnerLeft(BinTree P)
{
    if (!IsTreeEmpty(P))
    {
        return ((Left(P) != NULL) && (Right(P) == NULL));
    }
    else
    {
        return false;
    }
}

boolean IsUnerRight(BinTree P)
{
    if (!IsTreeEmpty(P))
    {
        return ((Left(P) == NULL) && (Right(P) != NULL));
    }
    else
    {
        return false;
    }
}

boolean IsBiner(BinTree P)
{
    if (!IsTreeEmpty(P))
    {
        return ((Left(P) != NULL) && (Right(P) != NULL));
    }
    else
    {
        return false;
    }
}

boolean SearchTree(BinTree P, nodeinfotype X)
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else if (Akar(P) == X)
    {
        return true;
    }
    else
    {
        return SearchTree(Left(P), X) || SearchTree(Right(P), X);
    }
}

addrNode SearchByChild(BinTree P, nodeinfotype left, nodeinfotype right)
{
    if (IsTreeOneElmt(P))
    {
        return NULL;
    }
    else
    {
        if (IsUnerLeft(P))
        {
            SearchByChild(Left(P), left, right);
        }
        else if (IsUnerRight(P))
        {
            SearchByChild(Right(P), left, right);
        }
        else
        {
            if ((Akar(Left(P)) == left && Akar(Right(P)) == right) || (Akar(Left(P)) == left && Akar(Right(P)) == right))
            {
                return P;
            }
            else
            {
                addrNode ret = SearchByChild(Left(P), left, right);
                if (ret != NULL)
                {
                    return ret;
                }
                else
                {
                    return SearchByChild(Right(P), left, right);
                }
            }
        }
    }
}

int NbNode(BinTree P)
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return 1 + NbNode(Left(P)) + NbNode(Right(P));
    }
}

int NbDaun(BinTree P)
{
    if (IsTreeOneElmt(P))
    {
        return 1;
    }
    else if (IsUnerLeft(P))
    {
        return NbDaun(Left(P));
    }
    else if (IsUnerRight(P))
    {
        return NbDaun(Right(P));
    }
    else
    { // IsBiner
        return NbDaun(Left(P)) + NbDaun(Right(P));
    }
}

int Level(BinTree P, nodeinfotype X)
{
    if (Akar(P) == X)
    {
        return 1;
    }
    else if (IsBiner(P))
    {
        if (SearchTree(Left(P), X))
        {
            return 1 + Level(Left(P), X);
        }
        else
        {
            return 1 + Level(Right(P), X);
        }
    }
    else if (IsUnerLeft(P))
    {
        return 1 + Level(Left(P), X);
    }
    else if (IsUnerRight(P))
    {
        return 1 + Level(Right(P), X);
    }
}

int Tinggi(BinTree P)
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        int tR = Tinggi(Right(P));
        int tL = Tinggi(Left(P));
        return 1 + (tR > tL ? tR : tL);
    }
}

void AddDaunTerkiri(BinTree *P, nodeinfotype X)
{
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
    }
    else
    {
        AddDaunTerkiri(&(Left(*P)), X);
    }
}

void DelDaunTerkiri(BinTree *P, nodeinfotype *X)
{
    if (IsTreeOneElmt(*P))
    {
        *X = Akar(*P);
        BinTree N = *P;
        *P = NULL;
        DealokNode(N);
    }
    else if (IsUnerRight(*P))
    {
        DelDaunTerkiri(&(Right(*P)), X);
    }
    else
    {
        DelDaunTerkiri(&(Left(*P)), X);
    }
}

void DelDaun(BinTree *P, nodeinfotype X)
{
    if (!IsTreeEmpty(*P))
    {
        if (IsTreeOneElmt(*P))
        {
            if (Akar(*P) == X)
            {
                addrNode Q = *P;
                *P = NULL;
                DealokNode(Q);
            }
        }
        else
        {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

void BuildTreeFromWord(BinTree *P, Word w, int *idx)
{
    (*idx)++;
    if (w.TabWord[*idx] == ')')
    {
        *P = NULL;
    }
    else
    {
        int simpul = (int)w.TabWord[(*idx)] - 48;

        while (48 <= (int)w.TabWord[(*idx) + 1] && (int)w.TabWord[(*idx) + 1] <= 57)
        {
            (*idx)++;
            simpul = 10 * simpul + (int)w.TabWord[*idx] - 48;
        }

        *P = AlokNode(simpul);
        (*idx)++;
        BuildTreeFromWord(&(Left(*P)), w, idx);
        BuildTreeFromWord(&(Right(*P)), w, idx);
    }
    (*idx)++;
}

void BetterPrintTree(BinTree P, int h, int lv)
{
    if (!IsTreeEmpty(P))
    {
        int i;
        for (i = 0; i < h * lv; i++)
        {
            printf(" ");
        }
        printf("%d\n", Akar(P));
        BetterPrintTree(Left(P), h, lv + 1);
        BetterPrintTree(Right(P), h, lv + 1);
    }
}

void PrintTree(BinTree P, int h)
{
    BetterPrintTree(P, h, 0);
}