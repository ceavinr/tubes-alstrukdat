#include "word.h"

int wordToInt(Word w)
{
    /*
     I.S word terdefinisi
     F.S dirubah ke integer dan dimasukkan ke dalan integer
    */
    int val = 0;
    int i;
    for (i = 0; i < w.Length; i++)
    {
        val = val * 10 + (w.TabWord[i] - 48);
    }

    return val;
}

void printWord(Word w)
{
    /*
     I.S word terdefinisi
     F.S menampilkan word
    */
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

Word stringToWord(char string[100])
{
    Word w;

    int i;
    for (i = 0; i < stringLength(string); i++)
    {
        w.TabWord[i] = string[i];
    }
    w.Length = stringLength(string);

    return w;
}

void CopyWord(Word *w1, Word w2)
{
    for (int i = 0; i < w2.Length; i++)
    {
        (*w1).TabWord[i] = w2.TabWord[i];
    }
    (*w1).Length = w2.Length;
}

boolean stringEQWord(Word w, char *c)
{
    /*Mengembalikan Nilai true jika string dengan tabword bernilai sama*/
    boolean eq = false;
    if (w.Length == stringLength(c))
    {
        eq = true;
        int i = 0;
        while (i < w.Length && eq)
        {
            if (w.TabWord[i] != c[i])
            {
                eq = false;
            }
            else
            {
                i++;
            }
        }
    }

    return eq;
}