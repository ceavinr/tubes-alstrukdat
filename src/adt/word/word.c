#include "word.h"

int wordToInt(Word w)
{
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
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
}

Word stringToWord(char *string)
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

char *wordToString(Word w)
{
    int i = 0;

    char *ret = malloc((w.Length - i + 2) * sizeof(char));
    char *p = ret;

    while (i < w.Length)
    {
        *p++ = w.TabWord[i];
        i++;
    }
    *p = '\0';

    return ret;
}
