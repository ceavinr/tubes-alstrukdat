#include "string.h"

int stringLength(char *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    };

    return i;
};

char *concat(char *s1, char *s2)
{
    /*Mengembalikan string berupa gabungan dari s1 dan s2*/
    char *ret = malloc((stringLength(s1) + stringLength(s2) + 1) * sizeof(char));
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