#include "string.h"

int panjangKata(char *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    };

    return i;
};

boolean isSame(char *a, char *b)
{
    boolean same = true;
    int i = 0;
    if (panjangKata(a) == panjangKata(b))
    {
        while (i < panjangKata(a) && same)
        {
            if (a[i] != b[i])
            {
                same = false;
            }
            i++;
        }
    }
    else
    {
        same = false;
    }
    return same;
}

char *concat(char *s1, char *s2)
{
    /*Mengembalikan string berupa gabungan dari s1 dan s2*/
    char *ret = malloc((panjangKata(s1) + panjangKata(s2) + 1) * sizeof(char));
    char *p = ret;
    while (*s1 != '\0')
    {
        *p++ = *s1++;
    }
    while (*s2 != '\0')
    {
        *p++ = *s2++;
    }
    *p = '\0';
    return ret;
}